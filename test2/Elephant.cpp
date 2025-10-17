#pragma once﻿﻿
#include "Elephant.h"



Elephant::Elephant(const PlayerColor& c, const int& x, const int& y, const bool& alive, const int& p, const sf::Sprite& sprite) : Piece(c, x, y, alive, p,sprite) {}
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
    
	this->Point = 250;
    if (this->color == PlayerColor::RED && x >= 5) this->Point += 10;
    if (this->color == PlayerColor::BLACK && x <= 4) this->Point += 10;
    
}
int Elephant::getsymbolvalue() const
{
    if (getSymbol() == "RE") return 9;
    else return 2;

}