#include<iostream>

using std::cout;
using std::endl;
using std::cin;

//반복문 제어
//break, continue
int main()
{
	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
			break;
		cout << i << endl;
	}
	return 0;
}