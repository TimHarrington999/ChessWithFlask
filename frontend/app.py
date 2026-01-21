from flask import Flask, Blueprint, request, render_template, jsonify
import chess
from engine import UCIEngine

print("My chess file: " + chess.__file__)

import random

# initialize the chess engine
engine = UCIEngine("engine/engine")

# TODO: Move game list to a database instead of being stored in memory
games = {}

def get_game(game_id):
    if game_id not in games:
        games[game_id] = chess.Board()
    return games[game_id]

bp = Blueprint(
    'main', 
    __name__, 
    template_folder="templates",
    static_folder="static",
    static_url_path="/static"
)

# index welcome page
@bp.route('/')
def index():
    return render_template('index.html')
    
# page for chess board
@bp.route('/game')
def play():
    return render_template('game.html')

# chess engine move api
@bp.route('/api/move', methods=["POST"])
def move():
    # fen = request.json["fen"]
    # move = engine.best_move(fen, depth=6)
    # return jsonify({"move": move})

    # pull the fields from the JSON
    data = request.json
    move = data["move"]
    game_id = data["game_id"]
    #fen = data["fen"]

    # TODO: track different games in a DB
    # get the game state
    #board = get_game(game_id)
    board = chess.Board()

    # update the board with the player move
    player_move = chess.Move.from_uci(move)
    board.push(player_move)

    # get the engine move and update the board again
    engine_move = engine.best_move(board.fen(), 6)
    board.push(chess.Move.from_uci(engine_move))

    return jsonify({
        "fen": board.fen(),
        "engine_move": engine_move
    })

# debug route
@bp.route('/debug/static-info')
def debug_static_info():
    from flask import current_app, jsonify
    return jsonify({
        "app_static_folder": current_app.static_folder,
        "blueprint_static_folder": bp.static_folder,
        "static_url_path": current_app.static_url_path
    })

