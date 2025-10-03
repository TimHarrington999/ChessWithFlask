from flask import Flask, Blueprint, render_template

bp = Blueprint('main', __name__)

# index welcome page
@bp.route('/')
def index():
    return render_template('index.html')
    
# page for chess board
@bp.route('/game')
def play():
    return render_template('game.html')