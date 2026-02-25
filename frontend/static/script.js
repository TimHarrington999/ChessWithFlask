
var board = null;
var game = new Chess();
var pendingEngineMove;
var $status = $('#status');
var $fen = $('#fen');
var $pgn = $('#pgn');


// called whenever a piece is starting to get dragged
function onDragStart(source, piece, position, orientation) {
    // do not pick up pieces if the game is over
    if (game.game_over()) return false

    // player can only move their color of pieces
    if ((orientation === 'white' && piece.search(/^w/) === -1) ||
        (orientation === 'black' && piece.search(/^b/) === -1)) {
        return false
    }
}

// Ensure player can only make legal moves
// also sends the updated board position to the back-end
function onDrop(source, target, piece, newPos, oldPos, orientation) {

    try {
        // see if the move is legal
        var move = game.move({
            from: source,
            to: target,
            promotion: 'q' // Always assume queen for simplicity
        });

        if (move === null) return 'snapback';
    } catch (e) {
        console.error(e);
        return 'snapback';
    }

    updateStatus();

    const player_move = source + target;

    fetch("/api/move", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({
            game_id: 1,
            move: player_move,
            fen: game.fen
        })
    })
        .then(res => res.json())
        .then(data => {
            //board.position(data.fen);
            newGameFen = data.fen;
            pendingEngineMove = data.engine_move;
            console.log("Engine move has been received\n");
        });

    //return 'snapback';
}

function onSnapEnd() {

    console.log(pendingEngineMove);

    // TODO: Change this to game.move() in order to properly update the fen string
    board.position(newGameFen);
    game.load(newGameFen);
    //game.move(pendingEngineMove);
    //board.move(pendingEngineMove);

    updateStatus();

}

// TODO: Properly keep track of PGN
function updateStatus() {
    console.log(game.ascii());

    var status = '';

    var moveColor = 'White';
    if (game.turn() === 'b') {
        moveColor = 'Black';
    }

    if (game.in_checkmate()) {
        status = 'Game over, ' + moveColor + ' is in checkmate.';
    }

    else if (game.in_draw()) {
        status = 'Game over, drawn position';
    }

    else {
        status = moveColor + ' to move.';

        if (game.in_check()) {
            status += ',' + moveColor + ' is in check.';
        }
    }

    $status.html(status)
    $fen.html(game.fen())
    $pgn.html(game.pgn())
}

var config = {
    draggable: true,
    dropOffBoard: 'snapback',
    position: 'start',
    pieceTheme: '/static/chesspieces/wikipedia/{piece}.png',
    onDragStart: onDragStart,
    onDrop: onDrop,
    onSnapEnd: onSnapEnd
}

board = Chessboard('board', config);

updateStatus();
