#pragma once
#include "Resolution.hpp"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> SpawnX(0, maxWidth);
std::uniform_int_distribution<> probability(50, 100);
