#pragma once﻿
#include "Advisor.h"


Advisor::Advisor(const PlayerColor &c, const int &x, const int &y, const bool &alive, const int &p, const sf::Sprite &sprite) : Piece(c, x, y, alive, p,sprite) {

   
}
bool Advisor::isValidMove(int toX, int toY, Piece* grid[10][9]) const {
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
    return (dx == 1 && dy == 1);
}
std::string Advisor::getSymbol() const {
    return (color == PlayerColor::RED) ? "RA" : "BA";
}
//void Advisor::updatePoint(int x, int y)
//{
//    
//
//    if ((x == 8 && y == 4) || (x == 7 && (y == 3 || y == 5)))
//        this->Point += 10;
//}
int Advisor::getsymbolvalue() const
{
    if (this->getSymbol() == "RA") return 7;
    else return 0;
}