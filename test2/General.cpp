#pragma once﻿
#include "General.h"

General::General(const PlayerColor& c, const int& x, const int& y, const bool& alive, const int& p, const sf::Sprite& sprite) : Piece(c, x, y, alive, p,sprite) {}

bool General::isValidMove(int toX, int toY, Piece* grid[10][9]) const {
    if (toX < 0 || toX > 9 || toY < 0 || toY > 8) return false;
    if (toY < 3 || toY > 5) return false;

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
void General::updatePoint(int x, int y)
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