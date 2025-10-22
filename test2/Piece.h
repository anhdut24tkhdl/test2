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
    int x, y;
    int Point;
    bool alive;
public:
	sf::Sprite sprite;
    Piece(const PlayerColor &c, const int& x,const  int& y, const  int& p,const bool&,const sf::Sprite&);
    virtual ~Piece();
	virtual std::vector<std::pair<int, int>> getAllPossibleMoves(Piece* grid[10][9]) const = 0 ;
    virtual bool isValidMove(const int &toX,const  int& toY, Piece* grid[10][9]) const = 0;
    virtual std::string getSymbol() const = 0;
    PlayerColor getColor() const;
     void setPosition(const int& newX,const  int& newY) ;
      int getX()  {
         return x;
     }
      int getY()  { return y; }
    virtual void updatePoint (const int& ,const int&) = 0;
	int getPoint() const { return Point; }
    virtual int getsymbolvalue() const = 0 ;
    void setAlive(bool status) { this->alive = status; }
	bool getAlive() const { return alive; }
   

};

#endif