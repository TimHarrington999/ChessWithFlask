cmake_minimum_required(VERSION 4.4.0)

project(ChessEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ChessEngine
	src/main.cpp
	src/Board.cpp
	src/Game.cpp
	src/pieces/PieceBase.cpp
	src/pieces/Bishop.cpp
	src/pieces/King.cpp
	src/pieces/Knight.cpp
	src/pieces/Pawn.cpp
	src/pieces/Queen.cpp
	src/pieces/Rook.cpp
)
