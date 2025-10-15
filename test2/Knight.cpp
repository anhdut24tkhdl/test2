#pragma once﻿
#include "Knight.h"


Knight::Knight(PlayerColor c, int x, int y, bool alive, int p, const sf::Sprite sprite) : Piece(c, x, y, alive, p,sprite) {}
bool Knight::isValidMove(int toX, int toY, Piece* grid[10][9]) const {
    if (toX < 0 || toX > 9 || toY < 0 || toY > 8) return false;
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
void Knight::updatePoint(int x, int y)
{
    
    
    if (y >= 2 && y <= 6 && x >= 2 && x <= 7)
        this->Point += 20;
    
    if (y == 0 || y == 8) this->Point -= 15;
}
int Knight::getsymbolvalue() const
{
    if (getSymbol() == "RK") return 11;
    else return 4;

}