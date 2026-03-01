from py2neo import Graph, Node, Relationship
from passlib.hash import bcrypt
from config import url, username, password
from datetime import datetime
import time
import uuid

graph = Graph(url + '/db/data/', username=username, password=password)


timestamp = lambda: int(round(time.time() * 1000))


moment_stamp = lambda: datetime.now().strftime('%Y-%m-%d %H:%M:%S')


def get_latest_notes():
    query = '''
    MATCH (note:Note)
    RETURN note
    ORDER BY note.last_modified DESC LIMIT 10
    '''

    return graph.run(query)


def find_note_owner(nid):
    query = '''
    MATCH (user:User)-[r:OWN]->(note:Note)
    WHERE note.nid = {nid}
    RETURN user
    '''

    cursor = graph.run(query, nid=nid)
    user = cursor.data()[0]
    return user.get('user').get('username')


def get_note_info(nid):
    note = graph.find_one('Note', 'nid', nid)
    return note


class User:
    def __init__(self, username):
        self.username = username

    def find(self):
        user = graph.find_one('User', 'username', self.username)
        return user

    def register(self, password):
        if not self.find():
            user = Node('User', username=self.username, password_hash=bcrypt.encrypt(password), register_time=timestamp())
            graph.create(user)
            return True
        else:
            return False

    def verify_password(self, password):
        user = self.find()
        if user:
            return bcrypt.verify(password, user['password_hash'])
        else:
            return False

    def change_password(self, password):
        query = '''
        MATCH (user:User)
        WHERE user.username = {username}
        SET user.password_hash = {password_hash}
        '''

        return graph.run(query, username=self.username, password_hash=bcrypt.encrypt(password))

    def add_note(self, title, tag):
        user = self.find()
        note = Node(
            'Note',
            nid=str(uuid.uuid4()),
            title=title,
            content='',
            last_modified=timestamp(),
            moment_stamp=moment_stamp(),
            tag=tag,
            views=1
        )
        rel = Relationship(user, 'OWN', note)
        graph.create(rel)

    def delete_note(self, nid):
        query1 = '''
        MATCH (user:User)-[r:OWN]->(note:Note)-[i:FORKED_FROM]-(:Note)
        WHERE user.username = {username}
        AND note.nid = {nid}
        DELETE i
        '''
        query2 = '''
        MATCH (user:User)-[r:OWN]->(note:Note)
        WHERE user.username = {username}
        AND note.nid = {nid}
        DELETE note, r
        '''

        graph.run(query1, username=self.username, nid=nid)
        return graph.run(query2, username=self.username, nid=nid)

    def edit_note(self, nid, content):
        query = '''
        MATCH (user:User)-[r:OWN]->(note:Note)
        WHERE user.username = {username}
        AND note.nid = {nid}
        SET note.content = {content}, note.last_modified = {time}, note.moment_stamp = {mtime}
        '''

        return graph.run(query, username=self.username, nid=nid, content=content, time=timestamp(), mtime=moment_stamp())

    def change_note_title(self, nid, title):
        query = '''
        MATCH (user:User)-[r:OWN]->(note:Note)
        WHERE user.username = {username}
        AND note.nid = {nid}
        SET note.title = {title}, note.last_modified = {time}, note.moment_stamp = {mtime}
        '''

        return graph.run(query, username=self.username, nid=nid, title=title, time=timestamp(), mtime=moment_stamp())

    def change_note_tag(self, nid, tag):
        query = '''
        MATCH (user:User)-[r:OWN]->(note:Note)
        WHERE user.username = {username}
        AND note.nid = {nid}
        SET note.tag = {tag}, note.last_modified = {time}, note.moment_stamp = {mtime}
        '''

        return graph.run(query, username=self.username, nid=nid, tag=tag, time=timestamp(), mtime=moment_stamp())

    def star_note(self, nid):
        user = self.find()
        note = graph.find_one('Note', 'nid', nid)
        graph.merge(Relationship(user, 'STAR', note, star_time=timestamp()))

    def unstar_note(self, nid):
        query = '''
        MATCH (user:User)-[r:STAR]->(note:Note)
        WHERE user.username = {username}
        AND note.nid = {nid}
        DELETE r
        '''

        return graph.run(query, username=self.username, nid=nid)

    def if_stared(self, nid):
        query = '''
        MATCH (user:User)-[r:STAR]->(note:Note)
        WHERE user.username = {username}
        AND note.nid = {nid}
        RETURN count(*) AS n
        '''

        cursor = graph.run(query, username=self.username, nid=nid)
        n = bool(cursor.data()[0].get('n'))
        return n

    def fork_note(self, nid):
        user = self.find()
        note = graph.find_one('Note', 'nid', nid)
        forked_note = Node(
            'Note',
            nid=str(uuid.uuid4()),
            title=note.get('title'),
            content=note.get('content'),
            last_modified=timestamp(),
            moment_stamp=moment_stamp(),
            tag=note.get('tag'),
            views=1
        )
        rel = Relationship(user, 'OWN', forked_note)
        fork_rel = Relationship(forked_note, 'FORKED_FROM', note, fork_time=timestamp())
        graph.create(rel)
        graph.create(fork_rel)

    def get_all_notes(self):
        query = '''
        MATCH (user:User)-[:OWN]->(note:Note)
        WHERE user.username = {username}
        RETURN note
        ORDER BY note.last_modified DESC
        '''

        return graph.run(query, username=self.username)

    def get_star_notes(self):
        query = '''
        MATCH (user:User)-[r:STAR]->(note:Note)
        WHERE user.username = {username}
        RETURN note
        ORDER BY r.star_time DESC
        '''

        return graph.run(query, username=self.username)


