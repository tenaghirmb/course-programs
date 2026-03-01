import os

url = os.environ.get('GRAPHDB_URL', 'http://localhost:7474')
username = os.environ.get('NEO4J_USERNAME', 'neo4j')
password = os.environ.get('NEO4J_PASSWORD', 'admin')


class Config:
    SECRET_KEY = os.environ.get('SECRET_KEY', 'The Fray')

    @staticmethod
    def init_app(app):
        pass