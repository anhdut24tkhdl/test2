    #pragma once﻿﻿
    #include"HashTable.h"
    #include <cstring>

    TranspositionTable::TranspositionTable() {
        table = new HashEntry[TABLE_SIZE];
        clear();
    }

    TranspositionTable::~TranspositionTable() {
        delete[] table;
    }

    uint64_t TranspositionTable::hashFunction(uint64_t key) const {
        // Hash nhanh, giảm va chạm
        return (key * 11400714819323198485llu) & (TABLE_SIZE - 1);
    }

    bool TranspositionTable::probe(uint64_t key, int depth, int alpha, int beta, int& value) {
        uint64_t index = hashFunction(key);
        HashEntry& entry = table[index];

        if (entry.key != key || entry.depth < depth) {
            return false;
        }

        if (entry.flag == EXACT) {
            value = entry.value;
            return true;
        }
        if (entry.flag == LOWERBOUND && entry.value >= beta) {
            value = entry.value; // cutoff
            return true;
        }
        if (entry.flag == UPPERBOUND && entry.value <= alpha) {
            value = entry.value; // cutoff
            return true;
        }

        // Không đủ điều kiện để trả về sớm
        return false;
    }

    void TranspositionTable::store(uint64_t key, int depth, int value, int flag) {
        uint64_t index = hashFunction(key);
        HashEntry& entry = table[index];

        if (entry.key != key || depth >= entry.depth) {
            entry.key = key;
            entry.depth = depth;
            entry.value = value;
            entry.flag = flag;
        }
    }

    void TranspositionTable::clear() {
        std::memset(table, 0, sizeof(HashEntry) * TABLE_SIZE);
    }
