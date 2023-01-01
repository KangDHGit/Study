#include<iostream>

using std::cout;
using std::endl;
using std::cin;

//ºÐ±â¹®(if, if ~ else, if ~ else if ~ else, switch)
int main()
{
	int num = 0;

	if (num == 0)
		cout << "num == 0" << endl;
	else
		cout << "num != 0" << endl;

	num = 11;
	if (num % 2 == 0)
		cout << "Â¦¼ö" << endl;
	else
		cout << "È¦¼ö" << endl;

	num = 333;
	if (num > 0)
	{
		if (num % 2 != 0)
			cout << "È¦¼ö" << endl;
		else
			cout << "Â¦¼ö" << endl;
	}

	int result = num % 2;
	switch (result)
	{
	case 0:
		cout << "Â¦¼ö" << endl;
		break;
	default:
		cout << "È¦¼ö" << endl;
		break;
	}
	return 0;
}