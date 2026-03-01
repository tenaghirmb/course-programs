from flask import render_template, session, flash, redirect, request, url_for
from markdown import markdown
from ..decorators import login_required
from .forms import *
from . import note
from ..models import User, find_note_owner, get_note_info
from datetime import datetime


@note.route('/view/<nid>')
def view(nid):
    info = get_note_info(nid)
    username = find_note_owner(nid)
    body = markdown(info.get('content'), output_format='html')
    moment_stamp = datetime.strptime(info.get('moment_stamp'), '%Y-%m-%d %H:%M:%S')
    stared = None
    if session.get('username'):
        stared = User(session.get('username')).if_stared(nid)
    return render_template('note/note_view.html', note=info, author=username, body=body, stared=stared, moment_stamp=moment_stamp)


@note.route('/new', methods=['GET', 'POST'])
@login_required
def new():
    form = NewForm()
    if form.validate_on_submit():
        User(session['username']).add_note(form.title.data, form.tag.data)
        flash('New note created.')
        return redirect(url_for('main.profile', username=session['username']))
    return render_template('note/note_new.html', form=form)


@note.route('/delete/<nid>')
@login_required
def delete(nid):
    username = find_note_owner(nid)
    if session['username'] == username:
        User(username).delete_note(nid)
        flash('Note Deleted.')
        return redirect(url_for('main.profile', username=username) or url_for('main.index'))
    else:
        flash('Unauthorized operation.')
        return redirect(url_for('main.index'))


@note.route('/edit/<nid>', methods=['GET', 'POST'])
@login_required
def edit(nid):
    form = EditForm()
    info = get_note_info(nid)
    if form.validate_on_submit():
        username = find_note_owner(nid)
        if session['username'] == username:
            User(username).edit_note(nid, form.body.data)
            flash('Note saved.')
            return redirect(url_for('note.view', nid=nid))
        else:
            flash('Unauthorized operation.')
            return redirect(url_for('main.index'))
    else:
        form.body.data = info.get('content')
    return render_template('note/note_edit.html', form=form, note=info)


@note.route('/change-title/<nid>', methods=['GET', 'POST'])
@login_required
def change_title(nid):
    form = ChangeTitleForm()
    if form.validate_on_submit():
        username = find_note_owner(nid)
        if session['username'] == username:
            User(username).change_note_title(nid, form.new_title.data)
            flash('Title updated.')
            return redirect(url_for('note.view', nid=nid))
        else:
            flash('Unauthorized operation.')
            return redirect(url_for('main.index'))
    return render_template('note/change_info.html', form=form)


@note.route('/change-tag/<nid>', methods=['GET', 'POST'])
@login_required
def change_tag(nid):
    form = ChangeTagForm()
    if form.validate_on_submit():
        username = find_note_owner(nid)
        if session['username'] == username:
            User(username).change_note_tag(nid, form.new_tag.data)
            flash('Tag updated.')
            return redirect(url_for('note.view', nid=nid))
        else:
            flash('Unauthorized operation.')
            return redirect(url_for('main.index'))
    return render_template('note/change_info.html', form=form)


@note.route('/star/<nid>')
@login_required
def star(nid):
    username = session['username']
    User(username).star_note(nid)
    flash('Stared note.')
    return redirect(request.referrer or url_for('main.index'))


@note.route('/unstar/<nid>')
@login_required
def unstar(nid):
    username = session['username']
    User(username).unstar_note(nid)
    flash('Unstared note.')
    return redirect(request.referrer or url_for('main.index'))


@note.route('/fork/<nid>')
@login_required
def fork(nid):
    username = session['username']
    User(username).fork_note(nid)
    flash('Note forked.')
    return redirect(request.referrer or url_for('main.index'))
