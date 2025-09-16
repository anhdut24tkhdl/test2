#pragma once﻿
#include "Rook.h"
#include "Pawn.h"
#include "General.h"
#include "Advisor.h"
#include "Elephant.h"
#include"Knight.h"
#include "Cannon.h"


class Board {

     
public:
    struct Move {
		Piece* piece;
        int fromX, fromY;
        int toX, toY;
        Piece* capturedPiece;
        Move(Piece* p, int fr, int fc, int tr, int tc, Piece* cap = nullptr)
            : piece(p), fromX(fr), fromY(fc), toX(tr), toY(tc), capturedPiece(cap) {
        }
	};  
    PlayerColor currentPlayer;
    Piece* grid[10][9];
    Board();
    ~Board();

    void initializePieces();       // Khởi tạo vị trí quân cờ
    bool movePiece(int fromX, int fromY, int toX, int toY); // Di chuyển quân cờ
    /*int getX() const;
    //int getY() const; */
    //int getPieceIndexAt(int x, int y) const; // Lấy chỉ số quân cờ tại vị trí (x, y)
  //  Piece* getPieceAt(int x, int y) const; // Lấy con trỏ đến quân cờ tại vị trí (x, y)
  //  Piece* const* getGrid() const; // Lấy lưới quân cờ
    //std::vector<Piece*> getPieces() const; // Lấy tất cả các quân cờ trên bàn
    //PlayerColor getCurrentPlayer() const; // Lấy màu người chơi hiện tại
    std::vector<std::pair<int, int>> getAllPossibleMoves(int x, int y) const; // Lấy tất cả các nước đi hợp lệ cho quân cờ tại (x, y)
	void printBoard() const;
    std::pair<int, int> minimax(const int&  ,Board & ,const int& ,const int &,bool );
	//bool isGameover(Piece *) const;
	std::vector<Move> getAllPossibleMoves(PlayerColor);
};