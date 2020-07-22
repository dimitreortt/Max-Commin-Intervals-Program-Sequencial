#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void
printVector(vector<int> v)
{
	cout << "\nvec.size: " << v.size() << endl;
	for (int i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}

// (Uno, 2000) Fast algorithms to enumerate all Common Intervals
int
LHP(vector<int> seq1, vector<int> seq2)
{
	//cout << "\n\nEntrei em LHP, os vetores sao: " << seq1.size() << " " << seq2.size() << "\n";
	//printVector(seq1);
	//printVector(seq2);

	//printVector(seq1);
	//cout << "\n\n";
	//printVector(seq2);
	//exit(1);

	if (seq1.size() != seq2.size())
	{
		printVector(seq1);
		printVector(seq2);
		cout << "\nThe Harmony given is not a Maximum Matching, exiting in LHP!";
		exit(1);
	}

	size_t size = seq1.size();

	static bool show = true;
	if (show) cout << "\nO numero de intervalos comuns de tamanho 1 eh: " << size << "\n", show = false;

	// build dictionary pi_AB
	vector<int> pi_AB;
	for (auto it = seq1.begin(); it != seq1.end(); it++)
	{
		auto it_pos = find(seq2.begin(), seq2.end(), *it);
		int index = (int)std::distance(seq2.begin(), it_pos);

		pi_AB.push_back(index);
	}

	//for (auto value : seq1) {
	//	// find position of value in seq2
	//	auto pos = find(seq2.begin(), seq2.end(), value);

	//	// push this position to pi_AB vector
	//	pi_AB.push_back((int)std::distance(seq2.begin(), pos));
	//}

	for (auto value : pi_AB) {
		//cout << value << ' ';
	}

	//calculate number of CIs
	int numberOfCIs = 0;
	int l, u;
	for (int x = 0; x < size; x++)
	{
		l = u = pi_AB[x];

		// for (int y = x + 1; y < size; y++)
		for (int y = x; y < size; y++)
		{
			l = min(l, pi_AB[y]);
			u = max(u, pi_AB[y]);

			//check length condition
			/*if (u - l > min(size - x, size - 3))
				break;*/

				//check holepoint condition
				//for()

			if (u - l - (y - x) == 0)
			{
				//cout << "\nGlória Deus, Entrei aqui";
				//exit(1);
				//output([x,y], [l,u]);

				//cout << "\n([" << x << "," << y << "], [" << l << "," << u << "]) ";
				numberOfCIs += 1;
			}
		}
	}

	return numberOfCIs;
}