#include <iostream>
#include <array>
#include <fstream>
#include <vector>
#include "IO.h"
#include "FamilyDict.h"

using namespace std;

struct Ocurrencies {
  int id;
  vector<int> positions;
};

//struct Family {
//  Family(vector<int> posg1, vector<int> posg2) {
//    _posg1 = posg1;
//    _posg2 = posg2;
//  }
//
//  vector<int> _posg1;
//  vector<int> _posg2;
//};

typedef struct Ocurrencies Ocurrencies;

void showOcurrencies(Ocurrencies o) {
  cout << "Ocurrencies -> id: " << o.id << ", vector: ";
  printVec(o.positions);
  cout << "\n";
}

void showOcurrenciesVector(vector<Ocurrencies*> ov) {
  for (auto o : ov) {
    showOcurrencies(*o);
  }
  cout << "\n";
}

class OcurrenciesDict {
public:
  OcurrenciesDict(vector<int> idVector) {
    int vectorSize = idVector.size();

    for (auto idx = 0; idx < vectorSize; idx++) {
      auto id = idVector[idx];
      auto occurency = containsOccurency(id);

      if (!occurency) {
        auto o = new Ocurrencies{ id, {idx} };
        ov.push_back(o);
      }
      else
      {
        occurency->positions.push_back(idx);
      }
    }
  }

  Ocurrencies* containsOccurency(int id) {
    for (auto o : ov) {
      if (o->id == id) {
        return o;
      }
    }
    return nullptr;
  }

  void showDict() {
    showOcurrenciesVector(ov);
  }

  vector<Ocurrencies*> getOcurrenciesVector() { return ov; }

private:
  vector<Ocurrencies*> ov;
};

void showFamilyVector(vector<Family> fv) {
  cout << "FamilyVector:\n";
  for (auto f : fv) {
    showFamily(f);
  }
  cout << "\n";
}

vector<Family> vectorsToFamilies(vector<int> v1, vector<int> v2)
{
  OcurrenciesDict od1{ v1 };
  OcurrenciesDict od2{ v2 };

  od1.showDict();
  od2.showDict();

  vector<Family> fv;
  Family f{ {},{} };

  auto ov1 = od1.getOcurrenciesVector();
  for (auto occ1 : ov1) {
    auto occ2 = od2.containsOccurency(occ1->id);
    if (occ2) {
      Family f{ occ1->positions, occ2->positions };
      showFamily(f);
      fv.push_back(f);
    }
  }

  //showFamilyVector(fv);
  return fv;
}
