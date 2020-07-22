#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

vector<int>
readGenome(const string gName, const string pathToGenomes = "../../../Entradas/Genomes/")
{
	vector<int> genome;
	fstream inFile;

	//const string pathToGenomes{ "../../../Entradas/Genomes/" };
	//const string pathToGenomes{ "./../../../Harmony - Search/Fixtures/Entradas/Genomes/" };

	const string g{ gName };

	inFile.open(pathToGenomes + g);
	if (!inFile) {
		cout << "Unable to open file " << pathToGenomes + g;
		exit(1); // terminate with error
	}

	int x;
	while (inFile >> x) {
		//cout << x << endl;//sum = sum + x;
		genome.push_back(x);
	}

	return genome;
}