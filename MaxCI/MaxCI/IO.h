#pragma once

#include <vector>
#include <string>
#include "Family.h"

std::vector<int>
readGenome(const std::string gName, const std::string pathToGenomes = "../../../Entradas/Genomes/");

void
showPairs(std::vector<Pair> pairs);

void showFamily(Family f);

template<typename T>
void printVec(std::vector<T> a);