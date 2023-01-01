#include<iostream>

using std::cout;
using std::endl;
using std::cin;

//배열
int main()
{
	//int nums[3]; // 선언만 하면 쓰레기값이 들어가있다.
	////초기화 방법
	//int nums0[3] = { 1,2,3 };		// 1 2 3
	//int nums1[3] = { 1, };			// 1 0 0
	//int nums2[] = { 1,2,3,4 };		// 1 2 3 4

	//for (int i = 0; i < sizeof(nums) / sizeof(int); i++)
	//{
	//	cout << nums[i] << endl;
	//}
	//nums[0] = 100;
	//for (int i = 0; i < sizeof(nums) / sizeof(int); i++)
	//{
	//	cout << nums[i] << endl;
	//}
	//cout << nums[0] << endl;

#pragma region 구구단
	bool isDebug = true;

	int gugudan[8][9];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 9; j++)
			gugudan[i][j] = (i + 2) * (j + 1);
	}

	/*if (isDebug)
	{
		for (int i = 0; i < 8; i++)
		{
			cout << i + 2 << "단 : ";
			for (int j = 0; j < 9; j++)
				cout << gugudan[i][j] << " ";
			cout << endl;
		}
	}*/
#pragma endregion

#pragma region 구구단 선택
	int dan = -1;
	cout << "출력할 단수를 입력해주세요 (2~9) : ";
	cin >> dan;
	if (dan >= 2 && dan <= 9)
	{
		cout << dan << "단 : ";
		int index = dan - 2;
		for (int i = 0; i < 9; i++)
		{
			cout << gugudan[index][i] << " ";
		}
		cout << "출력 끝" << endl;
	}
	else {
		cout << "잘못 입력하셨습니다." << endl;
	}
#pragma endregion

	return 0;
}