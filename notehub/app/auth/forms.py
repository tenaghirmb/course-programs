from flask_wtf import FlaskForm
from wtforms import StringField, PasswordField, SubmitField
from wtforms.validators import DataRequired, Length, EqualTo, Regexp


class LoginForm(FlaskForm):
    username = StringField('Username', validators=[DataRequired(message='This field is required.'),
                                                   Length(3, 20, message='Username must be between 3 and 20 characters in length.'),
                                                   Regexp('^[a-z][a-z0-9]*$', message='Username must have only lower case letters or numbers')])
    password = PasswordField('Password', validators=[DataRequired(message='This field is required.')])
    submit = SubmitField('Login')


class RegistrationForm(FlaskForm):
    username = StringField('Username', validators=[DataRequired(message='This field is required.'),
                                                   Length(3, 20, message='Username must be between 3 and 20 characters in length.'),
                                                   Regexp('^[a-z][a-z0-9]*$', message='Username must have only lower case letters or numbers')])
    password = PasswordField('Password', validators=[DataRequired(message='This field is required.')])
    confirm_password = PasswordField('Confirm Password', validators=[DataRequired(message='This field is required.'), EqualTo('password', message='Passwords must match.')])
    submit = SubmitField('Register')


class ChangePasswordForm(FlaskForm):
    old_password = PasswordField('Old Password', validators=[DataRequired(message='This field is required.')])
    new_password = PasswordField('New Password', validators=[DataRequired(message='This field is required.')])
    confirm_new_password = PasswordField('Confirm New Password', validators=[DataRequired(message='This field is required.'), EqualTo('new_password', message='Passwords must match.')])
    submit = SubmitField('Update Password')