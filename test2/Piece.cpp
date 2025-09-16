#pragma once﻿
#include "Piece.h"

Piece::Piece(PlayerColor c, int x, int y, bool alive, int p,const sf::Sprite & sprite) : color(c), alive(alive), x(x), y(y), Point(p),sprite(sprite) {}

Piece::~Piece() = default;

PlayerColor Piece::getColor() const { return color; }
void Piece::setPosition(int newX, int newY) { x = newX; y = newY; }
int Piece::getX() const { return x; }
int Piece::getY() const { return y; }


