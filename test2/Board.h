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
    void khoitao();
	Stack history = Stack(200); 
    Stack redon = Stack(10);
    std::vector<Piece*> redPieces;
    std::vector<Piece*> blackPieces;
    bool movePiece(const int &, const int&,  const int& , const int& ); // Di chuyển quân cờ
    std::vector<std::pair<int, int>> getAllPossibleMoves(const int &,const  int &) const; // Lấy tất cả các nước đi hợp lệ cho quân cờ tại (x, y)
	void printBoard() const;
    int minimax(int ,int , int , bool );
	bool isGameover() const;
	std::vector<Move> getAllPossibleMoves( PlayerColor);
    int EvaluatePoint( )const;
	void undo();
    void redo(const Move &);
	Move findBestMove(int depth);   
    bool checkMate(int x , int y );
    void clear();
	bool Luatnuocdidung(PlayerColor color) ;

	bool isGeneralFacing() const;
    int isYouWin() const;
	bool moveodering(const PlayerColor &);
	/*int scoreMove(const Move& move);
	int getPieceValueAt(Piece * p) const;*/
	  
};