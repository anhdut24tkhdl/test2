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
    if (fromX < 0 || fromX > 9 || fromY < 0 || fromY > 8 ||
        toX < 0 || toX > 9 || toY < 0 || toY > 8) {
        return false;
    }
    if (fromX == toX && fromY == toY) return false;

    Piece* piece = grid[fromX][fromY];
    if (piece == nullptr) return false;
    if (piece->getColor() != currentPlayer) return false;

    Piece* target = grid[toX][toY];
    if (target != nullptr && target->getColor() == currentPlayer) return false;
    if (!piece->isValidMove(toX, toY, grid)) return false;

    
    grid[toX][toY] = piece;
    grid[fromX][fromY] = nullptr;

  
    piece->setPosition(toX, toY);

    Move move;
    move.fromX = fromX;
    move.fromY = fromY;
    move.toX = toX;
    move.toY = toY;
    move.movedPiece = piece;
    move.capturedPiece = target; 

    history.Push(move);

    currentPlayer = (currentPlayer == PlayerColor::RED)
        ? PlayerColor::BLACK
        : PlayerColor::RED;

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

// lay quan co co piece
std::vector<Move> Board::getAllPossibleMoves(PlayerColor color)
{
    std::vector<Move> allMoves;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            Piece* piece = grid[i][j];
            if (piece != nullptr && piece->getColor() == color) {
                std::vector<std::pair<int, int>> moves = getAllPossibleMoves(i, j);
				
                for(int k = 0; k < moves.size(); k++)
				{
                    Move move;
                    move.fromX = i;
                    move.fromY = j;
					move.toX = moves[k].first;
					move.toY = moves[k].second;
                    move.movedPiece = piece;
                    if (grid[moves[k].first][moves[k].second] != nullptr)
                        move.capturedPiece = grid[moves[k].first][moves[k].second];
                    else
						move.capturedPiece = nullptr;
					allMoves.push_back(move);
                }
            }
        }
    }
    return allMoves;
}
bool Board::isGameover() const
{
    bool redGeneralAlive = false;
    bool blackGeneralAlive = false;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 9; ++j) {
            Piece* piece = grid[i][j];
            if (piece != nullptr) {
                if (piece->getSymbol() == "RG") {
                    redGeneralAlive = true;
                }
                else if (piece->getSymbol() == "BG") {
                    blackGeneralAlive = true;
                }
            }
        }
    }
    return !(redGeneralAlive && blackGeneralAlive);
}
//tinh gia tri quan co 
int Board::EvaluatePoint() const
{
    int PointAI = 0;
    int PointPlayer = 0;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 9; ++j) {
            Piece* p = grid[i][j];
            if (p == nullptr) continue;
            if (p->getColor() == PlayerColor::BLACK)
                PointAI += p->getPoint();
            else if (p->getColor() == PlayerColor::RED)
                PointPlayer += p->getPoint();
        }
    }
    return PointAI - PointPlayer;
}


//undone
void Board::undo()
{
    if (history.IsEmpty()) return;
    Move lastMove = history.Pop();

    grid[lastMove.fromX][lastMove.fromY] = lastMove.movedPiece;
  
    grid[lastMove.toX][lastMove.toY] = lastMove.capturedPiece;
    if (lastMove.movedPiece)
        lastMove.movedPiece->setPosition(lastMove.fromX, lastMove.fromY);

    currentPlayer = (currentPlayer == PlayerColor::RED) ? PlayerColor::BLACK : PlayerColor::RED;
}
//minimax
int Board::minimax(int depth, int alpha, int beta, bool isturnBlack)
{
    if (depth == 0 || this->isGameover())
        return this->EvaluatePoint();

    if (isturnBlack)
    {
        int maxEval = -1000000;
        std::vector<Move> moves = this->getAllPossibleMoves(PlayerColor::BLACK);
        if (moves.empty()) return EvaluatePoint();

        for (const Move& m : moves)
        {
     
            this->movePiece(m.fromX, m.fromY, m.toX, m.toY);
            int eval = minimax(depth - 1, alpha, beta, false);
            this->undo();

            maxEval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);
            if (beta <= alpha) break;
        }
        return maxEval;
    }
    else
    {
        int minEval = 1000000;
        std::vector<Move> moves = this->getAllPossibleMoves(PlayerColor::RED);
        if (moves.empty()) return EvaluatePoint();

        for (const Move& m : moves)
        {
            this->movePiece(m.fromX, m.fromY, m.toX, m.toY);
            int eval = minimax(depth - 1, alpha, beta, true);
            this->undo();

            minEval = std::min(minEval, eval);
            beta = std::min(beta, eval);
            if (beta <= alpha) break;
        }
        return minEval;
    }
}


Move Board::findBestMove(int depth)
{
    int bestValue = -1000000;
    Move bestMove;
	std::vector<Move> moves = this->getAllPossibleMoves(PlayerColor::BLACK);
    for (int i = 0; i < moves.size(); i++)
    {
       this->movePiece(moves[i].fromX, moves[i].fromY, moves[i].toX, moves[i].toY);
        int moveValue = minimax(depth - 1, -100000 ,100000,false);
      this->undo();
        if (moveValue > bestValue)
        {
            bestValue = moveValue;
            bestMove = moves[i];
        }
    }
    return bestMove;
}
bool Board::checkMate()
{
    
}