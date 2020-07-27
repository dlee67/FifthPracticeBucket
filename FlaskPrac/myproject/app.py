from flask import Flask
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)

app.config.from_pyfile('confic.cfg')

db = SQLAlchemy(app)

class Test(db.Model):
    id = db.Column(db.Integer, primary_key=True)

class Member(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(30), unique=True)
    password = db.Column(db.String(30))
    email = db.Column(db.String(50))
    join_date = db.Column(db.DateTime)

if __name__ == '__main__':
    app.run()