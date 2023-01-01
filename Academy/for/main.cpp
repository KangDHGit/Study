#include<iostream>
#include<iomanip>

using std::cout;
using std::endl;
using std::cin;

void star(int n)
{
	for (int i = 0; i < n; i += 2)
	{
		for (int j = 0; j < i; j += 2)
			cout << ' ';
		for (int k = n - i; k > 0; k--)
		{
			cout << '*';
		}
		cout << endl;
	}
	//  ***
	// *****
	//*******
	for (int i = 2; i < n; i += 2)
	{ // 0 2 4 6
		for (int j = i; j < n-2; j += 2)	// 0 2 4
			cout << ' ';
		for (int k = 0; k < i + 1; k++)
		{
			cout << '*';
		}
		cout << endl;
	}
}

int main()
{
	////for(초기화;조건식;증감식)
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << i << endl;
	//}

	//for (int i = 0; i < 10; i++)
	//{
	//	for (int j = 0; j < 10; j++)
	//		cout << j << " ";
	//	cout << endl;
	//}

#pragma region 실습 구구단출력1
	//for (int i = 2; i < 10; i++)
	//{ // 1, 2, 3, 4, 5, 6, 7, 8, 9
	//	cout << i << "단";
	//	for (int j = 1; j < 10; j++)
	//	{
	//		cout << i << " X " << j << " = " << i * j << " / ";
	//	}
	//	cout << endl;
	//}
#pragma endregion

#pragma region 실습 구구단출력2
	//// 실습 구구단출력2
	//cout << std::setiosflags(std::ios::left);
	//for (int i = 1; i < 10; i++)
	//{ // 1, 2, 3, 4, 5, 6, 7, 8, 9
	//	/*cout << i << "단" << endl;;*/
	//	for (int j = 2; j < 10; j++)
	//	{
	//		cout << j << " X " << i << " = " << std::setw(2) << i * j << " / ";
	//	}
	//	cout << endl;
	//}
	star(9);
#pragma endregion

	return 0;
}