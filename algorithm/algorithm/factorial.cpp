#include<iostream>

using std::cout;
using std::endl;
using std::cin;

// 팩토리얼 : n부터 1까지의 곱
// ex) 5! = 120;

// iteration = 반복, recursion = 순환
int factorial_iter(int n)
{
	int result = 1;
	for (int i = n; i > 0; i--)
		result *= i;
	return result;
}

int factorial_recu(int n)
{
	if (n > 1)  return n* factorial_recu(n - 1); 
	else return 1;
}

int main()
{
	cout << "factorial_iter : " << factorial_iter(5) << endl;
	cout << "factorial_recu : " << factorial_recu(5) << endl;

	return 0;
}
