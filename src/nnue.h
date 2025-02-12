#pragma once

#include <algorithm>
#include <array>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>

#define INPUT_WEIGHTS 64 * 12
#define HIDDEN_BIAS 512
#define HIDDEN_WEIGHTS 512
#define OUTPUT_BIAS 1

/// HIDDEN_BIAS/HIDDEN_WEIGHTS is basically the width of the hidden layer.
extern uint8_t inputValues[INPUT_WEIGHTS];
extern int16_t inputWeights[INPUT_WEIGHTS * HIDDEN_WEIGHTS];
extern int16_t hiddenBias[HIDDEN_BIAS];
extern int16_t hiddenWeights[HIDDEN_WEIGHTS];
extern int32_t outputBias[OUTPUT_BIAS];

namespace NNUE
{
int16_t relu(int16_t x);
void init(const char *filename);
void activate(std::array<int16_t, HIDDEN_BIAS> &accumulator, int inputNum);
void deactivate(std::array<int16_t, HIDDEN_BIAS> &accumulator, int inputNum);
int32_t output(std::array<int16_t, HIDDEN_BIAS> &accumulator);
} // namespace NNUE