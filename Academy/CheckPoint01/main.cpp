#include<iostream>

using std::cout;
using std::endl;
using std::cin;

void NumberGame(int answer, int lifeCount)
{
	int inputNum = -1;
	bool isAnswer = false;
	int count = lifeCount;
	cout << "숫자를 맞추어 맞추기 게임(1~99)" << endl;
	cout << "남은 기회 : " << count << endl;

	while (!isAnswer && count > 0)
	{
		cout << "숫자를 입력해주세요 : ";
		cin >> inputNum;
		if (inputNum == answer)
		{
			cout << "정답입니다! : " << answer << endl;
			isAnswer = true;
		}
		else if (inputNum > answer)
			cout << "정답보다 큽니다." << endl;
		else
			cout << "정답보다 작습니다." << endl;
		count--;
		cout << "남은기회 : " << count << endl;
	}

	cout << "게임을 종료합니다." << endl;
}

int main()
{
	NumberGame(54, 5);
	return 0;
}