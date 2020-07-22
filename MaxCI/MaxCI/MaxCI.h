#pragma once

#include <vector>
#include "Family.h"

class MaxCI
{
public:
	MaxCI(std::vector<int>, std::vector<int>);
	~MaxCI();
	uint16_t runAllPossibilities();

private:
	uint16_t _globalMaxCI;
	std::vector<Possibility> _globalMM;
	std::vector<Family> _families;
	uint16_t _familiesSize;
	void doGetNumCIs();
	void runAllPossibilities(uint16_t idx);
};

void
maximumMatchingToSequences(std::vector<Possibility> MM);

int
LHP(std::vector<int> seq1, std::vector<int> seq2);

bool 
notEmpty(Possibility p);

