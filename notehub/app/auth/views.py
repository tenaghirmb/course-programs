from flask import render_template, session, flash, redirect, url_for, request
from ..decorators import login_required
from .forms import *
from . import auth
from ..models import User


@auth.route('/register', methods=['GET', 'POST'])
def register():
    form = RegistrationForm()
    if form.validate_on_submit():
        user = User(form.username.data).register(form.password.data)
        if not user:
            flash('User already exists.')
        else:
            return redirect(url_for('auth.login'))
    return render_template('auth/register.html', form=form)


@auth.route('/login', methods=['GET', 'POST'])
def login():
    form = LoginForm()
    if form.validate_on_submit():
        username = form.username.data
        user = User(username)
        if user is not None and user.verify_password(form.password.data):
            session['username'] = username
            next = request.args.get('next') or request.referrer
            if next is None or not next.startswith('/'):
                next = url_for('main.index')
            return redirect(next)
        flash('Invalid username or password.')
    return render_template('auth/login.html', form=form)


@auth.route('/logout')
@login_required
def logout():
    session.pop('username', None)
    flash('Logged out.')
    return redirect(request.referrer or url_for('main.index'))


@auth.route('/change-password', methods=['GET', 'POST'])
@login_required
def change_password():
    form = ChangePasswordForm()
    if form.validate_on_submit():
        current_user = User(session['username'])
        if current_user.verify_password(form.old_password.data):
            current_user.change_password(form.new_password.data)
            flash('Your password has been updated.')
            return redirect(url_for('main.index'))
        else:
            flash('Invalid password.')
    return render_template("auth/change_password.html", form=form)
