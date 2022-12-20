#include<iostream>

using std::cout;
using std::endl;
using std::cin;

// ���丮�� : n���� 1������ ��
// ex) 5! = 120;

// iteration = �ݺ�, recursion = ��ȯ
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
