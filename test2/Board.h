#pragma once﻿
#include "Rook.h"
#include "Pawn.h"
#include "General.h"
#include "Advisor.h"
#include "Elephant.h"
#include"Knight.h"
#include "Cannon.h"
#include"Stack.h"
#include"HashTable.h"
#include<random>
#include <algorithm>
#include <iostream>
#include <cstring>

class Board {

     
public:
    uint64_t zobristTable[10][9][14];
    uint64_t generateZobristKey() const;
    void initZobristTable();
    TranspositionTable TT;
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
    bool checkMate(int x , int y );
    void clear();
	bool Luatnuocdidung(PlayerColor color) ;
	int getXgeneral(PlayerColor color);
    std::vector<std::pair<int, int>> getAllPossibleMoves1(int x, int y) ; // Lấy tất cả các nước đi hợp lệ cho quân cờ tại (x, y)
	bool isGeneralFacing() const;
};