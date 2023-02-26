#include<iostream>
#include<algorithm>
#include<set>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int Numbers[] = { 64, 102, 34, 32 };
	int Rank[4] = { 0 };
	for (int num : Numbers) {
		std::cout << "nums : " << num << std::endl;
	}
	for (int rank : Rank) {
		std::cout << "nums : " << rank << std::endl;
	}

	for (int i = 0; i < 4; i++)
	{
		int num = Numbers[i];
		for (int j = 0; j < 4; j++)
		{
			if (i == j) continue;
			if (num < Numbers[j])
				Rank[i]++;
		}
	}

	cout << endl;
	for (int rank : Rank) {
		std::cout << "nums : " << rank << std::endl;
	}

	return 0;
}