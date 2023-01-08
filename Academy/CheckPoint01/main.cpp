#include<iostream>
#include<random>

using std::cout;
using std::endl;
using std::cin;

//1. 반복문 추가(0)
//2. 
//3.
//4. 반복문작업

int GetRandomNum(int min, int max) {
	if (min > max)
	{
		cout << "잘못된 입력 값입니다." << endl;
		return 0;
	}
	//시드값을 얻기위한 random_device 생성
	std::random_device rd;
	//random_device를 통해 난수생성 엔진을 초기화 한다.
	std::mt19937 gen(rd());
	//정수(0~9)까지 균등하게 나타내는 난수열을 생성하기위해 균등분포를 정의
	std::uniform_int_distribution<int> random(min, max);
	return random(gen);
}

void CheckAnswer(int input, int answer, int* const count, bool* const isAnswer) {
	if (input == answer)
	{
		cout << "정답입니다! : " << answer << endl;
		*isAnswer = true;
	}
	else if (input > answer) {
		cout << "정답보다 큽니다." << endl; *count -= 1;
		*isAnswer = false;
	}
	else {
		cout << "정답보다 작습니다." << endl; *count -= 1;
		*isAnswer = false;
	}
}

void NumberGame(int ranAnswer, int lifeCount)
{
	int inputNum = -1;
	int answer = ranAnswer;
	bool isAnswer = false;
	int count = lifeCount;

	cout << "숫자를 맞추어 맞추기 게임(1~99)" << endl;
	cout << "남은 기회 : " << count << endl;

	while (!isAnswer && count > 0)
	{
		cout << "숫자를 입력해주세요 : ";
		cin >> inputNum;
		CheckAnswer(inputNum, answer, &count, &isAnswer);
		cout << "남은기회 : " << count << endl;
	}
	
	if (!isAnswer) {
		cout << "기회를 모두 소진했습니다" << endl;
		cout << "정답은 " << answer << "입니다." << endl;
	}

	cout << "게임을 종료합니다." << endl;
}

int main()
{
	int answer = GetRandomNum(1, 99);
	int life = GetRandomNum(5, 10);
	NumberGame(answer, life);
	return 0;
}