#pragma once﻿﻿
#include "Elephant.h"



Elephant::Elephant(PlayerColor c, int x, int y, bool alive, int p, const sf::Sprite sprite) : Piece(c, x, y, alive, p,sprite) {}
bool Elephant::isValidMove(int toX, int toY, Piece* grid[10][9]) const {
    if (toX < 0 || toX > 9 || toY < 0 || toY > 8) return false;
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
void Elephant::updatePoint(int x, int y)
{
    this->Point = 120; 
   
    if (this->color == PlayerColor::RED && x >= 5) this->Point = 0;
    if (this->color == PlayerColor::BLACK && x <= 4) this->Point = 0;

    if (y == 2 || y == 6) this->Point += 5;
    if (x == 2 || x == 7) this->Point += 5;
}