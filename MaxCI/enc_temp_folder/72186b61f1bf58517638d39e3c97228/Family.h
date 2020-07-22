#pragma once
#include <vector>
#include <cassert>

struct Pair
{
	uint16_t p1;
	uint16_t p2;
};

typedef struct Pair Pair;
typedef std::vector<Pair> Possibility;

class Family
{
public:
	Family(std::vector<int>, std::vector<int>);
	Possibility nextPossibility();
	~Family();

	std::vector<int> getPositionsInG1() { 
		return _inversed ? _positionsInG2 : _positionsInG1; 
	}
	
	std::vector<int> getPositionsInG2() { 
		return _inversed ? _positionsInG1 : _positionsInG2; 
	}

private:
	std::vector<int> _positionsInG1;
	std::vector<int> _positionsInG2;
	std::vector<int> _mappings;
	std::vector<bool> _isMapped;
	bool _inversed;
	int _size1;
	int _size2;
	int _lastMappingIndex;
	void map(int idx);
	int takeFirstNotMapped();
	Possibility inversePossib(Possibility p);
	int takeNextNotMapped(int);
	bool lastGotAnother();
	bool getAnother(int);
	bool doMapIndex(int);
	Possibility mappingsToPossibility();
	bool nextPossibNotStarted();
	void assertMappingsAreEmpty();
};
