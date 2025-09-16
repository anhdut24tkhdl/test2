#pragma once﻿
#include "Board.h"


Board::Board() : currentPlayer(PlayerColor::RED) {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 9; j++)
            grid[i][j] = nullptr;
    
}

Board::~Board() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 9; j++)
            if (grid[i][j] != nullptr) delete grid[i][j];
}




bool Board::movePiece(int fromX, int fromY, int toX, int toY) {
    if (fromX < 0 || fromX > 9 || fromY < 0 || fromY > 8 || toX < 0 || toX > 9 || toY < 0 || toY > 8) {
        return false;
    }
    if (fromX == toX && fromY == toY) return false;
    Piece* piece = grid[fromX][fromY];
    if (piece == nullptr) return false;
    if (piece->getColor() != currentPlayer) return false;
    Piece* target = grid[toX][toY];
    if (target != nullptr && target->getColor() == currentPlayer) return false;
    if (!piece->isValidMove(toX, toY, grid)) return false;
    if (target != nullptr) { delete target; }
    grid[toX][toY] = piece;
    grid[fromX][fromY] = nullptr;
    piece->updatePoint(toX, toY);
    piece->setPosition(toX, toY);
	
   currentPlayer = (currentPlayer == PlayerColor::RED) ? PlayerColor::BLACK : PlayerColor::RED;
    return true;
}
std::vector<std::pair<int, int>> Board::getAllPossibleMoves(int x, int y) const
{
    std::vector<std::pair<int, int>> moves;
    if (x < 0 || x > 9 || y < 0 || y > 8) {
        return moves;
    }
    Piece* piece = grid[x][y];
    if (piece == nullptr) return moves;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (i == x && j == y) continue;
            Piece* target = grid[i][j];
            if (target != nullptr && target->getColor() == piece->getColor()) continue;
            if (piece->isValidMove(i, j, const_cast<Piece * (*)[9]>(grid))) {
                moves.push_back({ i, j });
            }
        }
    }
    return moves;
}
void Board::printBoard() const {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == nullptr) {
                std::cout << ". ";
            }
            else {
                std::cout << grid[i][j]->getSymbol() << " ";
            }
        }
        std::cout << std::endl;
    }
}

std::pair<int ,int> Board::minimax(const int& depth  ,Board &board ,const int&alpha ,const int &beta,bool isturnBlack)
{
    if(depth==0 )
		//return evaluateBoard();
        if (isturnBlack)
        {
			int maxEval = -1000000;
			std::vector<Board::Move> moves = board.getAllPossibleMoves(PlayerColor::BLACK);
        }
        else
        {
			int minEval = 1000000;
			std::vector<Board::Move> moves = board.getAllPossibleMoves(PlayerColor::RED);
        }


}
std::vector<Board::Move> Board::getAllPossibleMoves(PlayerColor color)
{
    std::vector<Move> allMoves;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            Piece* piece = grid[i][j];
            if (piece != nullptr && piece->getColor() == color) {
                std::vector<std::pair<int, int>> moves = getAllPossibleMoves(i, j);
                for (const auto& move : moves) {
                    Piece* capturedPiece = grid[move.first][move.second];
                    allMoves.emplace_back(piece, i, j, move.first, move.second, capturedPiece);
                }
            }
        }
    }
    return allMoves;
}
