#pragma once﻿﻿
#ifndef TRANSPOSITION_TABLE_H
#define TRANSPOSITION_TABLE_H

#include <cstdint>

enum TT_Flag {
    EXACT = 0,      // Giá trị chính xác (minimax fully evaluated)
    LOWERBOUND = 1, // Giá trị thấp hơn beta (fail-high)
    UPPERBOUND = -1 // Giá trị cao hơn alpha (fail-low)
};

struct HashEntry {
    uint64_t key;   // mã hash của bàn cờ
    int depth;      // độ sâu minimax
    int value;      // giá trị minimax
    int flag;       // EXACT / LOWERBOUND / UPPERBOUND
    //int bestMove;   // nước đi tốt nhất
};

class TranspositionTable {
private:
    const int TABLE_SIZE = 1 << 22; // 1 triệu ô
    HashEntry* table;

    uint64_t hashFunction(uint64_t key) const;

public:
    TranspositionTable();
    ~TranspositionTable();

    bool probe(uint64_t key, int depth, int alpha, int beta, int& value);
    void store(uint64_t key, int depth, int value, int flag);

    void clear();
   

 

};


#endif
