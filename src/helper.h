#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "types.h"

std::vector <std::string> splitInput(std::string fen);

// Gets the file index of the square where 0 is the a-file
uint8_t square_file(Square sq);

// Gets the rank index of the square where 0 is the first rank."""
uint8_t square_rank(Square sq);

uint8_t square_distance(Square a, Square b);

Square bsf(U64 mask);

Square bsr(U64 mask);

uint8_t popcount(U64 mask);

Square poplsb(U64 &mask);

// returns diagonal of given square
uint8_t diagonal_of(Square sq);

// returns anti diagonal of given square
uint8_t anti_diagonal_of(Square sq);

uint8_t manhatten_distance(Square sq1, Square sq2);

bool get_square_color(Square square);

inline PieceType type_of_piece(Piece piece) {
    if (piece == None)
        return NONETYPE;
    return PieceToPieceType[piece];
}

template<Direction direction>
constexpr U64 step(U64 b) {
    switch (direction) {
        case NORTH:
            return b << 8;
        case SOUTH:
            return b >> 8;
        case NORTH_WEST:
            return (b & ~MASK_FILE[0]) << 7;
        case WEST:
            return (b & ~MASK_FILE[0]) >> 1;
        case SOUTH_WEST:
            return (b & ~MASK_FILE[0]) >> 9;
        case NORTH_EAST:
            return (b & ~MASK_FILE[7]) << 9;
        case EAST:
            return (b & ~MASK_FILE[7]) << 1;
        case SOUTH_EAST:
            return (b & ~MASK_FILE[7]) >> 7;
    }
}

// prints a move in uci format
std::string printMove(Move move);