#include<iostream>

using std::cout;
using std::endl;
using std::cin;

void NumberGame(int answer, int lifeCount)
{
	int inputNum = -1;
	bool isAnswer = false;
	int count = lifeCount;
	cout << "���ڸ� ���߾� ���߱� ����(1~99)" << endl;
	cout << "���� ��ȸ : " << count << endl;

	while (!isAnswer && count > 0)
	{
		cout << "���ڸ� �Է����ּ��� : ";
		cin >> inputNum;
		if (inputNum == answer)
		{
			cout << "�����Դϴ�! : " << answer << endl;
			isAnswer = true;
		}
		else if (inputNum > answer)
			cout << "���亸�� Ů�ϴ�." << endl;
		else
			cout << "���亸�� �۽��ϴ�." << endl;
		count--;
		cout << "������ȸ : " << count << endl;
	}

	cout << "������ �����մϴ�." << endl;
}

int main()
{
	NumberGame(54, 5);
	return 0;
}