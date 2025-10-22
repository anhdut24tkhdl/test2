#pragma once﻿﻿
#include "Elephant.h"



Elephant::Elephant(const PlayerColor& c, const int& x, const int& y,  const int& p, const bool& alive, const sf::Sprite& sprite) : Piece(c, x, y,  p, alive, sprite) {}
bool Elephant::isValidMove(const int& toX, const  int& toY, Piece* grid[10][9]) const {
    if (toX < 0 || toX > 9 || toY < 0 || toY > 8) return false;
    if (grid[toX][toY] != nullptr && grid[toX][toY]->getColor() == color) return false;
    if (color == PlayerColor::RED) {
        if (toX < 5) return false;
    }
    else {
        if (toX > 4) return false;
    }
    int dx = abs(toX - x);
    int dy = abs(toY - y);
    if (dx == 2 && dy == 2) {
        int eyeX = (x + toX) / 2;
        int eyeY = (y + toY) / 2;
        if (grid[eyeX][eyeY] != nullptr) return false;
        return true;
    }
    return false;
}
std::string Elephant::getSymbol() const {
    return (color == PlayerColor::RED) ? "RE" : "BE";
}
void Elephant::updatePoint(const int&x, const int&y)
{
    
	this->Point = 250;
    if (this->color == PlayerColor::RED && x >= 5) this->Point += 10;
    if (this->color == PlayerColor::BLACK && x <= 4) this->Point += 10;
    
}
int Elephant::getsymbolvalue() const
{
    if (getSymbol() == "RE") return 9;
    else return 2;

}
std::vector<std::pair<int, int>> Elephant::getAllPossibleMoves(Piece* grid[10][9]) const {
    std::vector<std::pair<int, int>> moves;
    int possibleMoves[4][2] = { {2,2}, {2,-2}, {-2,2}, {-2,-2} };

    for (auto& move : possibleMoves) {
        int newX = x + move[0];
        int newY = y + move[1];

  
        if (newX < 0 || newX > 9 || newY < 0 || newY > 8) continue;

        if (isValidMove(newX, newY, grid)) {
            moves.emplace_back(newX, newY);
        }
    }
    return moves;
}
