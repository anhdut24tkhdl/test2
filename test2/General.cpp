#pragma once﻿
#include "General.h"

General::General(const PlayerColor& c, const int& x, const int& y, const int& p, const bool& alive, const sf::Sprite& sprite) : Piece(c, x, y,  p, alive, sprite) {}

bool General::isValidMove(const int& toX, const  int& toY, Piece* grid[10][9]) const {
    if (toX < 0 || toX > 9 || toY < 0 || toY > 8) return false;
    if (toY < 3 || toY > 5) return false;
	if (grid[toX][toY] != nullptr && grid[toX][toY]->getColor() == color) return false;
    if (color == PlayerColor::RED) {
        if (toX < 7 || toX > 9) return false;
    }
    else {
        if (toX < 0 || toX > 2) return false;
    }

    int dx = abs(toX - x);
    int dy = abs(toY - y);
    return (dx + dy == 1);
}

std::string General::getSymbol() const {
    return (color == PlayerColor::RED) ? "RG" : "BG";
}
void General::updatePoint(const int&x, const int&y)
{
	this->Point = 10000;
    if (y == 3 || y == 5) this->Point += 20;
    if (y == 4) this->Point += 30;
}
int General::getsymbolvalue() const
{
    if (getSymbol() == "RG") return 10;
    else return 3;

}
std::vector<std::pair<int, int>> General::getAllPossibleMoves(Piece* grid[10][9]) const {
    std::vector<std::pair<int, int>> moves;
    int directions[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

    for (auto& dir : directions) {
        int newX = x + dir[0];
        int newY = y + dir[1];

        
        if (newX < 0 || newX > 9 || newY < 0 || newY > 8) continue;

        if (isValidMove(newX, newY, grid)) {
            moves.emplace_back(newX, newY);
        }
    }

    return moves;
}