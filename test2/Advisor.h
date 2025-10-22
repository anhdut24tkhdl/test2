#pragma once
#include "Piece.h"

class Advisor : public Piece {
public:
    Advisor(const PlayerColor &, const int &, const int &,  const int &, const bool&, const sf::Sprite &);
    bool isValidMove(const int &toX,const  int &toY, Piece* grid[10][9]) const override;
    std::string getSymbol() const override;
    void updatePoint(const int &x, const int& y) override;
    int getsymbolvalue() const override;
	std::vector<std::pair<int, int>> getAllPossibleMoves(Piece* grid[10][9]) const override;
  

};