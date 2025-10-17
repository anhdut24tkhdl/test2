#pragma once﻿
#include "Cannon.h"

Cannon::Cannon(const PlayerColor& c, const int& x, const int& y, const bool& alive, const int& p, const sf::Sprite& sprite) : Piece(c, x, y, alive, p,sprite) {}

bool Cannon::isValidMove(int toX, int toY, Piece* grid[10][9]) const {

    if (toX < 0 || toX > 9 || toY < 0 || toY > 8) return false;


    if (toX == x && toY == y) return false;

    if (toX != x && toY != y) return false;

    int count = 0;

    if (toX == x) {
        int minY = std::min(y, toY);
        int maxY = std::max(y, toY);
        for (int j = minY + 1; j < maxY; j++) {
            if (grid[x][j] != nullptr) count++;
        }
    }
    else {
        int minX = std::min(x, toX);
        int maxX = std::max(x, toX);
        for (int i = minX + 1; i < maxX; i++) {
            if (grid[i][y] != nullptr) count++;
        }
    }


    if (grid[toX][toY] == nullptr) {
        return count == 0;
    }
    else {
        return (count == 1 && grid[toX][toY]->getColor() != color);
    }
}

std::string Cannon::getSymbol() const {
    return (color == PlayerColor::RED) ? "RC" : "BC";
}
//void Cannon::updatePoint(int x, int y)
//{
//    
//    
//    if (y >= 2 && y <= 6) this->Point += 40;
//    if (x >= 3 && x <= 6) this->Point += 30;
//}
int Cannon::getsymbolvalue() const
{
    if (getSymbol() == "RC") return 8;
    else return 1;

}