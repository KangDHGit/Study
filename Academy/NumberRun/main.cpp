#include<iostream>

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

int main()
{
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


// 내풀이
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

	//선생님
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			cout << tiles[maps[i][j]];
		}
		cout << endl;
	}
	return 0;
}