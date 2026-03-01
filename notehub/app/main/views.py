from flask import render_template
from ..models import User, get_latest_notes
from . import main


@main.route('/')
def index():
    notes = get_latest_notes()
    return render_template('index.html', notes=notes)


@main.route('/profile/<username>')
def profile(username):
    user_being_viewed = User(username)
    notes = user_being_viewed.get_all_notes()
    star_notes = user_being_viewed.get_star_notes()

    return render_template(
        'profile.html',
        username=username,
        notes=notes,
        star_notes=star_notes
    )
