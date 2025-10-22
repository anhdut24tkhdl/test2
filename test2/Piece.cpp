#pragma once﻿
#include "Piece.h"

Piece::Piece(const PlayerColor& c,const  int& x, const int& y,const  int& p, const bool& alive, const sf::Sprite & sprite) : color(c),  x(x), y(y), Point(p),alive(alive),sprite(sprite) {}

Piece::~Piece() = default;

PlayerColor Piece::getColor() const { return color; }
void Piece::setPosition(const int &newX,const int& newY) { this->x = newX; this->y = newY; }




