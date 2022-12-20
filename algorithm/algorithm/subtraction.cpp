#include<iostream>

using std::cout;
using std::endl;
using std::cin;

// n부터 -3씩 빼면서 더하기
int sub_3_recu(int n)
{
	if (n > 0) return n + sub_3_recu(n - 3);
	else return 0;
}

int sub_3_iter(int n)
{
	int result = 0;
	for (int i = n; i > 0; i -= 3)
		result += i;
	return result;
}

int main()
{
	cout << "sub_3_recu(10) : " << sub_3_recu(10) << endl;
	cout << "sub_3_iter(10) : " << sub_3_iter(10) << endl;
	return 0;
}