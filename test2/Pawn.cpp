#pragma once﻿
#include "Pawn.h"


Pawn::Pawn(PlayerColor c, int x, int y, bool alive, int p, const sf::Sprite sprite) : Piece(c, x, y, alive, p,sprite) {}

bool Pawn::isValidMove(int toX, int toY, Piece* grid[10][9])  const {
    if (toX < 0 || toX > 9 || toY < 0 || toY > 8) return false;
    bool is_river = false;
    int dx = toX - x;
    int dy = toY - y;
    if ((dx == 0 && dy==0)||(dx != 0 && dy != 0))return false;
	
    if (color == PlayerColor::RED) {
        if (x <= 4) {
            is_river = true;
        }
        if (dx > 0 || abs(dx) > 1 || abs(dy) > 1) return false;
    }
    else {
        if (x >= 5) {
            is_river = true;
        }
        if (dx < 0 || abs(dx) > 1 || abs(dy) > 1) return false;
    }
    if (!is_river) {
        if (abs(dy) != 0) return false;
    }
    return true;
}

std::string Pawn::getSymbol() const {
    return(color == PlayerColor::RED) ? "RP" : "BP";
}
void Pawn::updatePoint(int x, int y)
{
    if (this->color == PlayerColor::RED)
    {
		if (x == 6) this->Point += 10;
        if (x < 6) {
            for(int i = x ; i>0;i--)
				this->Point += 20;
                   }
    }
    else
    {
		if (x == 4) this->Point += 5;
        if (x > 4) {
            
                this->Point += 10;
		}
    }
}
