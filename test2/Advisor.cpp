    #pragma once﻿
    #include "Advisor.h"

    Advisor::Advisor(const PlayerColor& c, const int& x, const int& y, const int& p, const bool& alive, const sf::Sprite& sprite) : Piece(c, x, y, p, alive, sprite) {
    }
    bool Advisor::isValidMove(const int& toX, const  int& toY, Piece* grid[10][9]) const {
        if (toX < 0 || toX > 9 || toY < 0 || toY > 8) return false;
        if (toY < 3 || toY > 5) return false;
	    if (grid[toX][toY] != nullptr && grid[toX][toY]->getColor() == color) return false;
        if(x == toX && y == toY) return false;
        if (color == PlayerColor::RED) {
            if (toX < 7 || toX > 9) return false;
        }
        else {
            if (toX < 0 || toX > 2) return false;
        }
        int dx = abs(toX - x);
        int dy = abs(toY - y);
        return (dx == 1 && dy == 1);
    }
    std::string Advisor::getSymbol() const {
        return (color == PlayerColor::RED) ? "RA" : "BA";
    }
    void Advisor::updatePoint(const int &x, const int &y)
    {
    
        this->Point = 250;
        if (x >= 7 && x <= 9 && y >= 3 && y <= 5) this->Point += 10;
        else this->Point -= 20;
    }
    int Advisor::getsymbolvalue() const
    {
        if (this->getSymbol() == "RA") return 7;
        else return 0;
    }
    std::vector<std::pair<int, int>> Advisor::getAllPossibleMoves(Piece* grid[10][9]) const {
        std::vector<std::pair<int, int>> moves;
        int possibleMoves[4][2] = { {1,1}, {1,-1}, {-1,1}, {-1,-1} };
        for (auto& move : possibleMoves) {
            int newX = this->x + move[0];
            int newY = this->y + move[1];
            if (isValidMove(newX, newY, grid)) {
                moves.emplace_back(newX, newY);
            }
        }
        return moves;
    }