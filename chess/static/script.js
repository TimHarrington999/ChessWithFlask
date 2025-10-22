// create the board
var config = {
    draggable: true,
    dropOffBoard: 'snapback',
    position: 'start',
    pieceTheme: '/static/chesspieces/wikipedia/{piece}.png'
}

var board = Chessboard('board', config);







/* // Enable dragging for player's pieces
const piece = document.getElementsByClassName("Piece");

// test for getting data from flask
function testFunction()
{
    fetch('/api/move')
        .then(res => res.json())
        .then(data => {
            console.log(data);
            document.body.innerHTML += `${test_data.random}`;
        });

     
} */