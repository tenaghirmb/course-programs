from flask import Flask
from flask_bootstrap import Bootstrap
from flask_pagedown import PageDown
from flask_moment import Moment
from .models import graph
from config import Config

bootstrap = Bootstrap()
pagedown = PageDown()
moment = Moment()


def create_app():
    app = Flask(__name__)
    app.config.from_object(Config)
    Config.init_app(app)

    bootstrap.init_app(app)
    pagedown.init_app(app)
    moment.init_app(app)

    from .main import main as main_blueprint
    app.register_blueprint(main_blueprint)

    from .auth import auth as auth_blueprint
    app.register_blueprint(auth_blueprint, url_prefix='/auth')

    from .note import note as note_blueprint
    app.register_blueprint(note_blueprint, url_prefix='/note')

    return app


# graph.schema.create_uniqueness_constraint('User', 'username')
# graph.schema.create_uniqueness_constraint('Note', 'nid')