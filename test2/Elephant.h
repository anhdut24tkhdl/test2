#pragma once
#include "Piece.h"

class Elephant : public Piece {
public:
    Elephant(PlayerColor c, int x, int y, bool alive, int p, const sf::Sprite sprite);
    bool isValidMove(int toX, int toY, Piece* grid[10][9]) const override;
    std::string getSymbol() const override;
    void updatePoint(int x, int y) override;
    int getsymbolvalue() const override;

};
