#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <iostream>
#include <cmath>
#include<SFML/Graphics.hpp>
#include <vector>

enum class PlayerColor { RED, BLACK };

class Piece {
protected:
    PlayerColor color;
    bool alive;
    int x, y;
    int Point;
public:
	sf::Sprite sprite;
    Piece(PlayerColor c, int x, int y, bool alive, int p,const sf::Sprite&);
    virtual ~Piece();

    virtual bool isValidMove(int toX, int toY, Piece* grid[10][9]) const = 0;
    virtual std::string getSymbol() const = 0;
    PlayerColor getColor() const;
    void setPosition(int newX, int newY);
    int getX() const;
    int getY() const;
    virtual void updatePoint (int ,int) = 0;
	int getPoint() const { return Point; }
    virtual int getsymbolvalue() const = 0 ;
};

#endif