#pragma once﻿
#include "Rook.h"

Rock::Rock(const PlayerColor& c, const int& x, const int& y, const bool& alive, const int& p, const sf::Sprite& sprite) : Piece(c, x, y, alive, p,sprite) {}
bool Rock::isValidMove(int toX, int toY, Piece* grid[10][9]) const {
    if (toX < 0 || toX > 9 || toY < 0 || toY > 8) return false;
    int dx = toX - x;
    int dy = toY - y;
    if (dx != 0 && dy != 0) return false;
    if (dx != 0) {
        if (dx > 0) {
            for (int i = x + 1; i < toX; i++) {
                if (grid[i][y] != nullptr) {
                    return false;
                }
            }
        }
        if (dx < 0) {
            for (int i = x - 1; i > toX; i--) {
                if (grid[i][y] != nullptr) {
                    return false;
                }
            }
        }
    }
    else if (dy != 0) {
        if (dy > 0) {
            for (int i = y + 1; i < toY; i++) {
                if (grid[x][i] != nullptr) {
                    return false;
                }
            }
        }
        if (dy < 0) {
            for (int i = y - 1; i > toY; i--) {
                if (grid[x][i] != nullptr) {
                    return false;
                }
            }
        }
    }
    return true;
}
std::string Rock::getSymbol() const {
    return (color == PlayerColor::RED) ? "RK" : "BK";
}
void Rock::updatePoint(int x, int y)
{
    this->Point = 1000;
    if (y >= 3 && y <= 5) this->Point += 20;
    if (x >= 3 && x <= 6) this->Point += 20;
}
int Rock::getsymbolvalue() const
{
    if (getSymbol() == "RR") return 13;
    else return 6;

}