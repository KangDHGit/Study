#include<iostream>

using std::cout;
using std::endl;
using std::cin;

//�迭
int main()
{
	//int nums[3]; // ���� �ϸ� �����Ⱚ�� ���ִ�.
	////�ʱ�ȭ ���
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

#pragma region ������
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
			cout << i + 2 << "�� : ";
			for (int j = 0; j < 9; j++)
				cout << gugudan[i][j] << " ";
			cout << endl;
		}
	}*/
#pragma endregion

#pragma region ������ ����
	int dan = -1;
	cout << "����� �ܼ��� �Է����ּ��� (2~9) : ";
	cin >> dan;
	if (dan >= 2 && dan <= 9)
	{
		cout << dan << "�� : ";
		int index = dan - 2;
		for (int i = 0; i < 9; i++)
		{
			cout << gugudan[index][i] << " ";
		}
		cout << "��� ��" << endl;
	}
	else {
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
	}
#pragma endregion

	return 0;
}