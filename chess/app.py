from flask import Flask, Blueprint, render_template, jsonify
import random

bp = Blueprint('main', __name__, template_folder="templates")
#api_bp = Blueprint('move', __name__)

# index welcome page
@bp.route('/')
def index():
    return render_template('index.html')
    
# page for chess board
@bp.route('/game')
def play():
    return render_template('game.html')

# api for chess AI
@bp.route('/api/move', methods=['POST'])
def ai_move():
    test_data = {
        "piece": "Knight",
        "start": "B2",
        "end": "B3",
        "random": f"{test_func()}"
    }
    return jsonify(test_data)


# test function
def test_func():
    return random.randint(1, 10)