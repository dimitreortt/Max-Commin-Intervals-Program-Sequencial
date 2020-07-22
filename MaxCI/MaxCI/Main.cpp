#include <iostream>
#include <array>
#include "MaxCI.h"
#include "IO.h"
#include <fstream>

using namespace std;

struct a {
  int id;
  vector<int> positions;
};

int main(int argc, char** argv) {

  /*auto g1 = readGenome("21Exact_1");
  auto g2 = readGenome("21Exact_2");

	printVector(g1);
	printVector(g2);*/
  
  vector<int> test1{ 1,3,5, 7, 3, 2, 2 };
  vector<int> test2{ 1,2,6, 7, 3, 5, 1 };

  ////MaxCI m(g1, g2);
  MaxCI m(test1, test2);
  m.runAllPossibilities();
  //Family f(test1, test2);
  //auto p = f.nextPossibility();
  //while (notEmpty(p))
  //{
  //  showPairs(p);
  //  p = f.nextPossibility();
  //}

  return 0;
}