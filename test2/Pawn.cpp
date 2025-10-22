#pragma once﻿
#include "Pawn.h"


Pawn::Pawn(const PlayerColor& c, const int& x, const int& y, const int& p, const bool& alive, const sf::Sprite& sprite) : Piece(c, x, y, p, alive, sprite) {}

bool Pawn::isValidMove(const int& toX, const  int& toY, Piece* grid[10][9])  const {
    if (toX < 0 || toX > 9 || toY < 0 || toY > 8) return false;
    bool is_river = false;
    if (grid[toX][toY] != nullptr && grid[toX][toY]->getColor() == color) return false;
    int dx = toX - x;
    int dy = toY - y;
    if ((dx == 0 && dy==0)||(dx != 0 && dy != 0))return false;
	
    if (color == PlayerColor::RED) {
        if (x <= 4) {
            is_river = true;
        }
        if (dx > 0 || abs(dx) > 1 || abs(dy) > 1) return false;
    }
    else {
        if (x >= 5) {
            is_river = true;
        }
        if (dx < 0 || abs(dx) > 1 || abs(dy) > 1) return false;
    }
    if (!is_river) {
        if (abs(dy) != 0) return false;
    }
    return true;
}

std::string Pawn::getSymbol() const {
    return(color == PlayerColor::RED) ? "RP" : "BP";
}
void Pawn::updatePoint(const int&x, const int&y)
{
	this->Point = 100;
    if (this->color == PlayerColor::RED) {
        if (x < 5) this->Point += 40; // qua sông
        else if (x == 5) this->Point += 20; // sát sông
    }
    else {
        if (x > 4) this->Point += 40; // qua sông
        else if (x == 4) this->Point += 20;
    }
}
int Pawn::getsymbolvalue() const
{
    if (getSymbol() == "RP") return 12;
    else return 5;

}
std::vector<std::pair<int, int>> Pawn::getAllPossibleMoves(Piece* grid[10][9]) const {
    std::vector<std::pair<int, int>> moves;
    int dirs[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} }; 

    for (auto& d : dirs) {
        int newX = x + d[0];
        int newY = y + d[1];

       
        if (newX < 0 || newX > 9 || newY < 0 || newY > 8) continue;

        if (isValidMove(newX, newY, grid)) {
            moves.emplace_back(newX, newY);
        }
    }

    return moves;
}