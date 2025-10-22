#pragma once﻿
#include "Knight.h"


Knight::Knight(const PlayerColor& c, const int& x, const int& y,  const int& p, const bool& alive, const sf::Sprite& sprite) : Piece(c, x, y,  p, alive, sprite) {}
bool Knight::isValidMove(const int& toX, const  int& toY, Piece* grid[10][9]) const {
    if (toX < 0 || toX > 9 || toY < 0 || toY > 8) return false;
    if (grid[toX][toY] != nullptr && grid[toX][toY]->getColor() == color) return false;
    int dx = toX - x;
    int dy = toY - y;
    if (!((abs(dx) == 2 && abs(dy) == 1) || (abs(dx) == 1 && abs(dy) == 2))) return false;
    if (abs(dx) == 2) {
        int legX = x + dx / 2;
        if (grid[legX][y] != nullptr) return false;
    }
    else {
        int legY = y + dy / 2;
        if (grid[x][legY] != nullptr) return false;
    }
    return true;
}
std::string Knight::getSymbol() const {
    return (color == PlayerColor::RED) ? "RH" : "BH";
}
void Knight::updatePoint(const int&x, const int&y)
{
    
	this->Point = 400;
    if (y >= 2 && y <= 6 && x >= 2 && x <= 7)
        this->Point += 25;
    
    if (y == 0 || y == 8) this->Point -= 15;
}
int Knight::getsymbolvalue() const
{
    if (getSymbol() == "RK") return 11;
    else return 4;

}
std::vector<std::pair<int, int>> Knight::getAllPossibleMoves(Piece* grid[10][9]) const {
    std::vector<std::pair<int, int>> moves;
    int dirs[8][2] = { {2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {1,-2}, {-1,2}, {-1,-2} };

    for (auto& d : dirs) {
        int newX = x + d[0];
        int newY = y + d[1];

        // Boundary check trước khi gọi isValidMove
        if (newX < 0 || newX > 9 || newY < 0 || newY > 8) continue;

        if (isValidMove(newX, newY, grid)) {
            moves.emplace_back(newX, newY);
        }
    }

    return moves;
}