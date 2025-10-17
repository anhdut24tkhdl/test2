#pragma once
#include "Piece.h"

class Cannon : public Piece {
public:
    Cannon(const PlayerColor&, const int&, const int&, const bool&, const int&, const sf::Sprite&);
    bool isValidMove(int toX, int toY, Piece* grid[10][9]) const override;
    std::string getSymbol() const override;
    void updatePoint(int x, int y) override;
    int getsymbolvalue() const override;
};