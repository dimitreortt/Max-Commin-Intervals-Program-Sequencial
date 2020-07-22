#include "Family.h"
#include <iostream>

using namespace std;

Family::Family(std::vector<int> lst1, std::vector<int> lst2)
{
	if (lst1.size() > lst2.size()) {
		_positionsInG1 = lst2;
		_positionsInG2 = lst1;
		_inversed = true;
	}
	else
	{
		_positionsInG1 = lst1;
		_positionsInG2 = lst2;		
	}

	_size1 = _positionsInG1.size();
	_size2 = _positionsInG2.size();
	
	for (auto i = 0; i < _size1; i++) {
		_mappings.push_back(-1);
	}
	_lastMappingIndex = _size1 - 1;
	
	for (auto i = 0; i < _size2; i++) {
		_isMapped.push_back(false);
	}
}

Family::~Family()
{
}

void Family::assertMappingsAreEmpty()
{
	for (auto i = 0; i < _size1; i++)
	{
		assert(_mappings[i] == -1);
	}
}

bool Family::nextPossibNotStarted()
{
	if (_mappings[0] == -1) {
		assertMappingsAreEmpty();
		return true;
	}
	return false;
}

Possibility Family::nextPossibility()
{
	/*printVec(_mappings);
	printVec(_isMapped);*/

	if(nextPossibNotStarted())
	{ 
		// Start nextPossibility() structures
		//cout << "primeiro\n";
		map(0);
		return mappingsToPossibility();
	}

	if (lastGotAnother()) {
		//cout << "segundo\n";
		return mappingsToPossibility();
	}
	else
	{
		//cout << "terceiro\n";
		for (auto i = _size1 - 2; i >= 0; i--)
		{
			//cout << i << ' ';
			if (getAnother(i))
			{
				map(i + 1);
				return mappingsToPossibility();
			}
		}
		assertMappingsAreEmpty();
	}
	return {};
}

bool Family::doMapIndex(int idx)
{
	auto firstFreeIndex = takeFirstNotMapped();
	assert(firstFreeIndex != -1);
	_mappings[idx] = firstFreeIndex;
}

bool Family::lastGotAnother() 
{
	//assert(_mappings[size1 - 1] == _mappings.back());
	assert(_mappings[_size1 - 1] < _size2);

	auto isMappedIndex = _mappings[_lastMappingIndex];
	auto next = takeNextNotMapped(isMappedIndex);
	if (next == -1) {
		_mappings[_lastMappingIndex] = -1;
		return false;
	}
	else
	{
		assert(next >= 0);
		_mappings[_lastMappingIndex] = next;
		return true;
	}
}

bool Family::getAnother(int idx) 
{
	auto next = takeNextNotMapped(_mappings[idx]);
	if (next == -1) {
		_mappings[idx] = -1;
		return false;
	}
	else
	{
		assert(next >= 0);
		_mappings[idx] = next;
		return true;
	}
}

void Family::map(int idx)
{
	if (idx >= _size1) {
		return;
	}

	assert(_mappings[idx] == -1);

	doMapIndex(idx);
	map(idx + 1);
}

int Family::takeNextNotMapped(int idx)
{
	//cout << "lalla " << idx << " ";
	_isMapped[idx] = false;

	for (auto i = idx + 1; i < _size2; i++) {
		if (!_isMapped[i]) {
			_isMapped[i] = true;
			return i;
		}
	}

	return -1;
}

int Family::takeFirstNotMapped()
{
	for (auto i = 0; i < _size2; i++) {
		if (!_isMapped[i]) {
			_isMapped[i] = true;
			return i;
		}
	}
	cout << "Erro em takefirstnotmapped";
	exit(1);
	return -1;
}

Possibility Family::inversePossib(Possibility possibility)
{
	Possibility inversePossibility;
	for (auto pair : possibility) {
		Pair newPair{ pair.p2, pair.p1 };
		inversePossibility.push_back(newPair);
	}
	return inversePossibility;
}

Possibility Family::mappingsToPossibility()
{	
	/*cout << "In mappingstopos..:";
	printVec(_mappings);
	printVec(_isMapped);
	cout << "end mappingstopos\n\n";*/

	Possibility possibility;
	for (auto i = 0; i < _size1; i++)
	{
		uint16_t posg1 = _positionsInG1[i];
		uint16_t posg2 = _positionsInG2[_mappings[i]];
		possibility.push_back({ posg1, posg2 });
	}
	return _inversed? inversePossib(possibility): possibility;
}