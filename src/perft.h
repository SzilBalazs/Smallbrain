#pragma once

#include <chrono>

#include "board.h"

class Perft
{
  public:
    Board board;
    int depth;
    uint64_t nodes;

    U64 perftFunction(int depth, int max);
    void perfTest(int depth, int max);
    void testAllPos();
};