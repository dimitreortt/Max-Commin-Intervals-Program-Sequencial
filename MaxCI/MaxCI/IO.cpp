#include "Family.h"
#include "IO.h"
#include <iostream>

using namespace std;

template<typename T>
void printVec(vector<T> v) {
  cout << "Vec:";
  for (auto item : v) {
    cout << " " << item;
  }
  cout << ";";
}

void showPair(Pair p)
{
  cout << "Pair(" << p.p1 << "," << p.p2 << "), ";
}

void
showPairs(vector<Pair> pairs)
{
  cout << "Pairs: [ ";
  for (auto p : pairs) {
    showPair(p);
  }
  cout << "]\n";
}

void showFamily(Family f) {
  cout << "Family -> posg1: ";
  printVec(f.getPositionsInG1());
  cout << " posg2: ";
  printVec(f.getPositionsInG2());
  cout << "\n";
}