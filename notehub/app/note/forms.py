from flask_wtf import FlaskForm
from wtforms import StringField, SubmitField
from flask_pagedown.fields import PageDownField


class NewForm(FlaskForm):
    title = StringField('Title')
    tag = StringField('tag')
    submit = SubmitField('Create')


class EditForm(FlaskForm):
    save =SubmitField('Save')
    body = PageDownField('')


class ChangeTitleForm(FlaskForm):
    new_title = StringField('New Title')
    submit = SubmitField('Update')


class ChangeTagForm(FlaskForm):
    new_tag = StringField('New Tag')
    submit = SubmitField('Update')