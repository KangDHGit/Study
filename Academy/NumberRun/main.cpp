#include<iostream>
#include<Windows.h>;
#include<random>;

using std::cout;
using std::endl;
using std::cin;

#define GROUND 0
#define WALL 1
#define GOAL 2
#define PLAYER1 3
#define PLAYER2 4
#define PLAYER3 5
#define PLAYER4 6
#define PLAYER5 7

struct Racer {
	int posX;
	int posY;
	int beforeX;
};

class Race {
	char tiles[8] = { ' ', '-', '|','1','2','3','4','5' };
	int maps[7][25] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0},
		{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0},
		{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0},
		{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0},
		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};
	int racerXpos[5] = { 0, };

	void swapX(const int posX, const int posY);
	void racersMove(int racer) {
		racerXpos[racer]++;
	}
	bool goalCheck();
	void print();
public:
	void start();
};

#pragma region RaceDefine
void Race::swapX(const int posX, const int posY) {
	int temp = maps[posY][posX];
	maps[posY][posX + 1] = temp;
	maps[posY][posX] = 0;
}

bool Race::goalCheck() {
	for (int i = 0; i < 5; i++)
	{
		if (racerXpos[i] >= 24)
		{
			cout << i + 1 << "�� ���̼��� �¸��߽��ϴ�." << endl;
			return true;
		}
	}
	return false;
}

void Race::print() {
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			cout << tiles[maps[i][j]];
		}
		cout << endl;
	}
}

void Race::start() {
	int posX = 0;
	bool isGoal = false;
	//�õ尪�� ������� random_device ����
	std::random_device rd;
	//random_device�� ���� �������� ������ �ʱ�ȭ �Ѵ�.
	std::mt19937 gen(rd());
	//����(0~4)���� �յ��ϰ� ��Ÿ���� �������� �����ϱ����� �յ������ ����
	std::uniform_int_distribution<int> random(0, 4);

	while (!isGoal)
	{
		print();

		for (int mapY = 1; mapY < 6; mapY++)
		{
			int racer = mapY - 1;
			swapX(racerXpos[racer], mapY);
		}

		for (int i = 0; i < 5; i++) {
			racersMove(i);
			isGoal = goalCheck();
			if (isGoal) break;
		}

		int racer = random(gen);
		int mapY = racer + 1;

		swapX(racerXpos[racer], mapY);
		racersMove(racer);

		isGoal = goalCheck();

		Sleep(1000);
	}
}
#pragma endregion
#pragma region 01/15 �Լ�ȭ ����
void Print(char* tiles, int(*maps)[25]) {
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			cout << *(tiles + *(maps[i] + j));
		}
		cout << endl;
	}
}

void MoveMaps(int(*maps)[25], int* posXs) {
	for (int i = 1; i < 6; i++)
	{
		int player = i - 1;
		int temp = *(maps[i] + *(posXs+ player)); // 0 ~ 4
		*(maps[i] + (*(posXs + player) + 1)) = temp;
		*(maps[i] + *(posXs + player)) = 0;
	}
}
void MoveMaps(int(*maps)[25], int* posXs, int randomPlayer) {
	int temp = *(maps[randomPlayer] + *(posXs + (randomPlayer - 1)));
	*(maps[randomPlayer] + (*(posXs + (randomPlayer - 1)) + 1)) = temp;
	*(maps[randomPlayer] + *(posXs + (randomPlayer - 1))) = 0;
}
void MovePlayer(int* posXs) {
	for (int i = 0; i < 5; i++)
		++*(posXs + i);
}
void MovePlayer(int* posXs, int randomPlayer) {
	++* (posXs + (randomPlayer - 1));
}
int CheckFinish(int* posXs, bool& isPlay) {
	int winner = 0;
	for (int i = 0; i < 5; i++)
	{
		if (posXs[i] >= 24)
		{
			isPlay = false;
			return i + 1;
		}
	}
	Sleep(1000);
	return -1;
}
#pragma endregion



int main()
{
#pragma region �п�
	char tiles[] = { ' ', '-', '|','1','2','3','4','5' };
	int maps[7][25] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0},
		{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0},
		{5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0},
		{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0},
		{7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};
	int posXs[5] = { 0, };
	// ��Ǯ��
#pragma region My
	/*for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			char map;
			switch (maps[i][j])
			{
			case GROUND:
				map = tiles[GROUND];
				break;
			case WALL:
				map = tiles[WALL];
				break;
			case GOAL:
				map = tiles[GOAL];
				break;
			case PLAYER1:
				map = tiles[PLAYER1];
				break;
			case PLAYER2:
				map = tiles[PLAYER2];
				break;
			case PLAYER3:
				map = tiles[PLAYER3];
				break;
			case PLAYER4:
				map = tiles[PLAYER4];
				break;
			case PLAYER5:
				map = tiles[PLAYER5];
				break;
			default:
				map = 'X';
				break;
			}
			cout << map;
		}
		cout << endl;
	}*/
#pragma endregion

	//������
	int posX = 0;
	bool isPlay = true;

	while (true)
	{
		//�ʱ׸���
		/*for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				cout << tiles[maps[i][j]];
			}
			cout << endl;
		}*/

		Print(tiles, maps);

		////�÷��̾�� ������ġ �׸��� ������ġ �����
		//for (int i = 1; i < 6; i++)
		//{
		//	int player = i - 1;
		//	int temp = maps[i][posXs[player]]; // 0 ~ 4
		//	maps[i][posXs[player] + 1] = temp;
		//	maps[i][posXs[player]] = 0;
		//}

		MoveMaps(maps, posXs);

		////�÷��̾�� ����ǥ �̵�
		//for (int i = 0; i < 5; i++)
		//	++posXs[i];

		MovePlayer(posXs);

#pragma region 1�� �÷��̾� �ѹ��� �̵�
		////1�� �÷��̾ �ѹ��� �̵� �׸���
		//int player1 = 0;
		//int temp = maps[1][posXs[player1]];
		//maps[1][posXs[player1] + 1] = temp;	//������ġ�� �׸���(�� ��ǥ�̵�X)
		//maps[1][posXs[player1]] = 0;
		////1�� �÷��̾� ����ǥ �̵�
		//posXs[player1]++;
#pragma endregion

#pragma region �����÷��̾� �ѹ��� �̵�
		//�õ尪�� ������� random_device ����
		std::random_device rd;
		//random_device�� ���� �������� ������ �ʱ�ȭ �Ѵ�.
		std::mt19937 gen(rd());
		//����(0~4)���� �յ��ϰ� ��Ÿ���� �������� �����ϱ����� �յ������ ����
		std::uniform_int_distribution<int> random(1, 5);

		int randomPlayer = random(gen);

		/*int temp = maps[randomPlayer][posXs[randomPlayer - 1]];
		maps[randomPlayer][posXs[randomPlayer - 1] + 1] = temp;
		maps[randomPlayer][posXs[randomPlayer - 1]] = 0;
		++posXs[randomPlayer - 1];*/
		MoveMaps(maps, posXs, randomPlayer);
		MovePlayer(posXs, randomPlayer);
#pragma endregion

		////��������..
		//int winner = 0;
		//for (int i = 0; i < 5; i++)
		//{
		//	if (posXs[i] >= 24)
		//	{
		//		isPlay = false;
		//		winner = i + 1;
		//		break;
		//	}
		//}
		int winner = CheckFinish(posXs, isPlay);

		if (!isPlay)
		{
			cout << winner << "�� �÷��̾ �¸��߽��ϴ�." << endl;
			break;
		}


		//Sleep(1000);
	}

#pragma region ������ Ǯ��
	/*bool isPlay = true;
	int PosXs[5] = { 0, };*/

	//while (isPlay)
	//{
	//	//ȭ�� ����..
	//	{
	//		for (int i = 0; i < 7; i++)
	//		{
	//			for (int j = 0; j < 25; j++)
	//			{
	//				int index = maps[i][j];
	//				std::cout << tiles[index];
	//			}
	//			std::cout << std::endl;
	//		}
	//	}

	//	//������ ��ȯ..
	//	{
	//		for (int i = 1; i < 6; i++)
	//		{
	//			int indexY = i - 1;
	//			int temp = maps[i][PosXs[indexY]];
	//			maps[i][PosXs[indexY] + 1] = temp;
	//			maps[i][PosXs[indexY]] = 0;
	//		}

	//		for (int i = 0; i < 5; i++)
	//		{
	//			++PosXs[i];
	//		}

	//		int temp = maps[1][PosXs[0]];
	//		maps[1][PosXs[0] + 1] = temp;
	//		maps[1][PosXs[0]] = 0;
	//		++PosXs[0];
	//	}

	//	//��������..
	//	{
	//		for (int i = 0; i < 5; i++)
	//		{
	//			if (PosXs[i] >= 24)
	//			{
	//				isPlay = false;
	//				break;
	//			}
	//		}
	//	}

	//	Sleep(500); //#include <windows.h>
	//}
#pragma endregion
#pragma endregion

	/*Race race;
	race.start();*/
	return 0;
}