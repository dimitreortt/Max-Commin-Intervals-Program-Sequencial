#include "MaxCI.h"
#include "IO.h"
#include "FamilyDict.h"
#include <iostream>

using namespace std;

MaxCI::MaxCI(std::vector<int> vec1, std::vector<int> vec2)
{
  _globalMaxCI = 0;
  _families = vectorsToFamilies(vec1, vec2);
  showFamilyVector(_families);
  _familiesSize = _families.size();
  _globalMM.reserve(_familiesSize);
}

MaxCI::~MaxCI()
{
}

uint16_t MaxCI::runAllPossibilities() 
{
  runAllPossibilities(0);
  cout << "\aquii ;)";
  return _globalMaxCI;
}

bool notEmpty(Possibility p) {
  cout << "\nla1";
  if (p.size() == 0) {
    cout << "\nla2";
    return false;
  }
  return true;
}

void MaxCI::runAllPossibilities(uint16_t idx)
{
  //cout << "\nidx: " << idx << ", _families size: " << _families.size() << ".";
  auto f = _families[idx];
  if (idx >= _families.size() - 1)
  {
    auto nextPossib = f.nextPossibility();
    while (notEmpty(nextPossib)) {
      //doGetNumCIs();
      cout << "\nnextpossib, idx: " << idx << " -> ";
      showPairs(nextPossib);
      cout << "should doGetNumCIs() :)\n";
      nextPossib = f.nextPossibility();
    }
    cout << "hope :)\n";
  }
  else
  {
    auto nextPossib = f.nextPossibility();
    while (notEmpty(nextPossib)) {
      cout << "\nnextpossib, idx: " << idx << " -> ";
      showPairs(nextPossib);
      cout << "\noi";
      //_globalMM[idx] = nextPossib;
      _globalMM.at(idx) = nextPossib;
      cout << "\noi2";
      runAllPossibilities(idx + 1);
      cout << "\noi3, idx: " << idx;
      nextPossib = f.nextPossibility();
    }
  }
}

void MaxCI::doGetNumCIs() {
    
}