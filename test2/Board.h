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
    std::vector<std::pair<int, int>> getAllPossibleMoves(const int &,const  int &) ; // Lấy tất cả các nước đi hợp lệ cho quân cờ tại (x, y)
	void printBoard() const;
    int minimax(int ,int , int , bool );
	bool isGameover() const;
	std::vector<Move> getAllPossibleMoves( PlayerColor);
    int EvaluatePoint( )const;
	void undo();
    void redo();
	Move findBestMove(int depth);   
    bool checkMate();
    void clear();
	bool Luatnuocdidung(PlayerColor color) ;

	bool isGeneralFacing() const;
    int isYouWin() const;
	bool moveodering(const PlayerColor &);
	bool getCheckmate();
    bool Checkmate();
    bool tamchieu();
    std::vector<Move> moveOrdering(const PlayerColor& color) {
        std::vector<Move> moves = getAllPossibleMoves(color);

        std::sort(moves.begin(), moves.end(), [](const Move& a, const Move& b) {
            int valueA = a.capturedPiece ? a.capturedPiece->getPoint () : 0;
            int valueB = b.capturedPiece ? b.capturedPiece->getPoint() : 0;
            return valueA > valueB; 
            });

        return moves;
    }
   
};