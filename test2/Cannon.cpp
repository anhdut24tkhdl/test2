#pragma once﻿
#include "Cannon.h"

Cannon::Cannon(const PlayerColor& c, const int& x, const int& y,  const int& p, const bool& alive, const sf::Sprite& sprite) : Piece(c, x, y,  p, alive, sprite) {}

bool Cannon::isValidMove(const int& toX, const int& toY, Piece* grid[10][9]) const {
    // Check chỉ số hợp lệ
    if (toX < 0 || toX > 9 || toY < 0 || toY > 8) return false;

    // Không được di chuyển vào chính ô mình
    if (toX == x && toY == y) return false;

    // Không được ăn quân đồng màu
    if (grid[toX][toY] != nullptr && grid[toX][toY]->getColor() == color) return false;

    // Chỉ được đi theo hàng hoặc cột
    if (toX != x && toY != y) return false;

    int count = 0;

    // Di chuyển theo cùng cột
    if (toX == x) {
        int startY = std::min(y, toY) + 1;
        int endY = std::max(y, toY);
        for (int j = startY; j < endY; j++) {
            if (j >= 0 && j <= 8 && grid[x][j] != nullptr) {
                count++;
            }
        }
    }
    // Di chuyển theo cùng hàng
    else if (toY == y) {
        int startX = std::min(x, toX) + 1;
        int endX = std::max(x, toX);
        for (int i = startX; i < endX; i++) {
            if (i >= 0 && i <= 9 && grid[i][y] != nullptr) {
                count++;
            }
        }
    }

    // Nếu đi tới ô trống, phải không có quân chắn
    if (grid[toX][toY] == nullptr) {
        return count == 0;
    }
    // Nếu đi tới ô có quân đối phương, phải có đúng 1 quân chắn
    else {
        return count == 1 && grid[toX][toY]->getColor() != color;
    }
}

std::string Cannon::getSymbol() const {
    return (color == PlayerColor::RED) ? "RC" : "BC";
}
void Cannon::updatePoint(const int&x, const int&y)
{
    
	this->Point = 900;
    if (y >= 2 && y <= 6) this->Point += 20;
    if (x >= 3 && x <= 6) this->Point += 15;
}
int Cannon::getsymbolvalue() const
{
    if (getSymbol() == "RC") return 8;
    else return 1;

}
std::vector<std::pair<int, int>> Cannon::getAllPossibleMoves(Piece* grid[10][9]) const {
    std::vector<std::pair<int, int>> moves;
    for(int i = 0; i < 10; i++) {
        if(this->isValidMove(i, this->y, grid)) {
            moves.emplace_back(i, this->y);
		}
	}
    for (int j = 0; j < 9; j++) {
        if (this->isValidMove(this->x, j, grid)) {
            moves.emplace_back(this->x, j);
        }
    }
    
    return moves;
}