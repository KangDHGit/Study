#include<iostream>

using std::cout;
using std::endl;
using std::cin;

//�б⹮(if, if ~ else, if ~ else if ~ else, switch)
int main()
{
	int num = 0;

	if (num == 0)
		cout << "num == 0" << endl;
	else
		cout << "num != 0" << endl;

	num = 11;
	if (num % 2 == 0)
		cout << "¦��" << endl;
	else
		cout << "Ȧ��" << endl;

	num = 333;
	if (num > 0)
	{
		if (num % 2 != 0)
			cout << "Ȧ��" << endl;
		else
			cout << "¦��" << endl;
	}

	int result = num % 2;
	switch (result)
	{
	case 0:
		cout << "¦��" << endl;
		break;
	default:
		cout << "Ȧ��" << endl;
		break;
	}
	return 0;
}