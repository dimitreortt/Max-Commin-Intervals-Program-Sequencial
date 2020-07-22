#include "Family.h"
#include "IO.h"
#include <vector>
#include <iostream>

using namespace std;

vector<Pair> 
gatherPairs(vector<Possibility> MM)
{
  vector<Pair> pv;
  for (auto possibility : MM) {
    for (auto pair : possibility) {
      pv.push_back(pair);
    }
  }

  return pv;
}

void 
maximumMatchingToSequences(vector<Possibility> MM) 
{
  vector<Pair> pairs = gatherPairs(MM);
  showPairs(pairs);
}