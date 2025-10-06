#pragma once﻿
#include "Rook.h"
#include "Pawn.h"
#include "General.h"
#include "Advisor.h"
#include "Elephant.h"
#include"Knight.h"
#include "Cannon.h"
#include"Stack.h"


class Board {

     
public:
     
    PlayerColor currentPlayer;
    Piece* grid[10][9];
    Board();
    ~Board();
	Stack history = Stack(100);

    void initializePieces();       // Khởi tạo vị trí quân cờ
    bool movePiece(int fromX, int fromY, int toX, int toY); // Di chuyển quân cờ
    std::vector<std::pair<int, int>> getAllPossibleMoves(int x, int y) const; // Lấy tất cả các nước đi hợp lệ cho quân cờ tại (x, y)
	void printBoard() const;
    int minimax(int ,int , int , bool );
	bool isGameover() const;
	std::vector<Move> getAllPossibleMoves(PlayerColor);
    int EvaluatePoint( )const;
	void undo();
	Move findBestMove(int depth);   
    bool checkMate();
};