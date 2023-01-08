#include<iostream>
#include<random>

using std::cout;
using std::endl;
using std::cin;

//1. �ݺ��� �߰�(0)
//2. 
//3.
//4. �ݺ����۾�

int GetRandomNum(int min, int max) {
	if (min > max)
	{
		cout << "�߸��� �Է� ���Դϴ�." << endl;
		return 0;
	}
	//�õ尪�� ������� random_device ����
	std::random_device rd;
	//random_device�� ���� �������� ������ �ʱ�ȭ �Ѵ�.
	std::mt19937 gen(rd());
	//����(0~9)���� �յ��ϰ� ��Ÿ���� �������� �����ϱ����� �յ������ ����
	std::uniform_int_distribution<int> random(min, max);
	return random(gen);
}

void CheckAnswer(int input, int answer, int* const count, bool* const isAnswer) {
	if (input == answer)
	{
		cout << "�����Դϴ�! : " << answer << endl;
		*isAnswer = true;
	}
	else if (input > answer) {
		cout << "���亸�� Ů�ϴ�." << endl; *count -= 1;
		*isAnswer = false;
	}
	else {
		cout << "���亸�� �۽��ϴ�." << endl; *count -= 1;
		*isAnswer = false;
	}
}

void NumberGame(int ranAnswer, int lifeCount)
{
	int inputNum = -1;
	int answer = ranAnswer;
	bool isAnswer = false;
	int count = lifeCount;

	cout << "���ڸ� ���߾� ���߱� ����(1~99)" << endl;
	cout << "���� ��ȸ : " << count << endl;

	while (!isAnswer && count > 0)
	{
		cout << "���ڸ� �Է����ּ��� : ";
		cin >> inputNum;
		CheckAnswer(inputNum, answer, &count, &isAnswer);
		cout << "������ȸ : " << count << endl;
	}
	
	if (!isAnswer) {
		cout << "��ȸ�� ��� �����߽��ϴ�" << endl;
		cout << "������ " << answer << "�Դϴ�." << endl;
	}

	cout << "������ �����մϴ�." << endl;
}

int main()
{
	int answer = GetRandomNum(1, 99);
	int life = GetRandomNum(5, 10);
	NumberGame(answer, life);
	return 0;
}