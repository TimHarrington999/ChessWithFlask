from flask import Flask, Blueprint, request, render_template, jsonify
import chess
from engine import UCIEngine


engine = UCIEngine("engine/engine")

# TODO: Move game list to a database instead of being stored in memory
the_game = chess.Board()

# def get_game(game_id):
#     if game_id not in games:
#         games[game_id] = chess.Board()
#     return games[game_id]

bp = Blueprint(
    "main",
    __name__,
    template_folder="templates",
    static_folder="static",
    static_url_path="/static",
)


# index welcome page
@bp.route("/")
def index():
    return render_template("index.html")


# page for chess board
@bp.route("/game")
def play():
    return render_template("game.html")


# When the player makes a move, that move gets sent to this route.
# This route also takes that move, sends it to the engine, then returns the engine's move.
# TODO: Right now, only one game is kept per flask instance for easier development
# Integrate a DB in order to enable simultaneous games
# Also we need to only trust/implement fen strings from the server to ensure data integrity.
@bp.route("/api/move", methods=["POST"])
def move():
    # pull the fields from the JSON request
    data = request.json
    move = data["move"]
    game_id = data["game_id"]

    # get the game state
    # board = get_game(game_id)
    # board = chess.Board()

    player_move = chess.Move.from_uci(move)
    the_game.push(player_move)

    print(f"(app.py) FEN after PLAYER move: {the_game.fen()}")

    engine_move = engine.best_move(the_game.fen(), 6)
    the_game.push(chess.Move.from_uci(engine_move))
    print(type(engine_move))

    print(f"(app.py) FEN after ENGINE move: {the_game.fen()}")

    return jsonify({"fen": the_game.fen(), "engine_move": engine_move})


# debug route
@bp.route("/debug/static-info")
def debug_static_info():
    from flask import current_app, jsonify

    return jsonify(
        {
            "app_static_folder": current_app.static_folder,
            "blueprint_static_folder": bp.static_folder,
            "static_url_path": current_app.static_url_path,
        }
    )
