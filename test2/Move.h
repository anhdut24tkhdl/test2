#pragma once
#include "Piece.h"


struct Move {
    int fromX, fromY;
    int toX, toY;
    Piece* movedPiece;   // con trỏ quân đã di chuyển
    Piece* capturedPiece; // quân bị ăn (nếu có, NULL nếu không)
};
