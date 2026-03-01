from functools import wraps
from flask import session, redirect, url_for


def login_required(func):
    @wraps(func)
    def decorated_view(*args, **kwargs):
        username = session.get('username')
        if not username:
            return redirect(url_for('auth.login'))
        return func(*args, **kwargs)
    return decorated_view