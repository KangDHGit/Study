#include<iostream>

using std::cout;
using std::endl;
using std::cin;

static int recuCount = 0;
static int iterCount = 0;

int fibo_recu(int n)
{
	recuCount++;
	if (n == 1) return 1;
	else if (n == 0) return 0;
	else return fibo_recu(n - 1) + fibo_recu(n - 2);
}

int fibo_iter(int n)
{
	if (n == 1) { iterCount = 1; return 1; }
	else if (n == 0) { iterCount = 1; return 0; }

	int n_1 = 1;
	int n_2 = 0;
	int result = 0;
	for (int i = 2; i <= n; i++)
	{
		iterCount++;
		result = n_1 + n_2;
		n_2 = n_1;
		n_1 = result;
	}
	return result;
}

int main()
{
	cout << "fibo_recu(5) : " << fibo_recu(5) << endl;
	cout << "recuCount : " << recuCount << endl;
	cout << "fibo_iter(5) : " << fibo_iter(5) << endl;
	cout << "iterCount : " << iterCount << endl;
	return 0;
}