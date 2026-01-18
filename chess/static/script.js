
var board = null;
var game = new Chess();
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

        // illegal move
        if (move === null) return 'snapback';
    } catch (e) {
        console.error(e);
        return 'snapback';
    }

    // a valid move was made, then update
    updateStatus();
}

// update the board position after the piece snap for castling, en passant, pawn promotion
function onSnapEnd() {
    board.position(game.fen());
}

function updateStatus() {
    var status = '';

    // determine which color is taking their turn
    var moveColor = 'White';
    if (game.turn() === 'b') {
        moveColor = 'Black';
    }

    // Check for checkmate
    if (game.in_checkmate()) {
        status = 'Game over, ' + moveColor + ' is in checkmate.';
    }

    // check for draw
    else if (game.in_draw()) {
        status = 'Game over, drawn position';
    }

    // game has not ended yet
    else {
        status = moveColor + ' to move.';

        // check?
        if (game.in_check()) {
            status += ',' + moveColor + ' is in check.';
        }
    }

    $status.html(status)
    $fen.html(game.fen())
    $pgn.html(game.pgn())

    console.log("Status has been updated.");
}

// configure the board
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
