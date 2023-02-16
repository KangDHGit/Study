#include<iostream>
#include<fstream>
#include<string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

//N ×N 크기의 영상이 주어질 때, 이 영상을 압축한 결과를 출력하는 프로그램을 작성하시오.
//첫째 줄에는 영상의 크기를 나타내는 숫자 N 이 주어진다. N 은 언제나 2의 제곱수로 주어지며
//1 ≤ N ≤ 64의 범위를 가진다. 두 번째 줄부터는 길이 N의 문자열이 N개 들어온다. 각 문자열은 0 또는 1의 숫자로 이루어져 있으며, 영상의 각 점들을 나타낸다.
//예제입력			예제출력
//8					((110(0101))(0010)1(0001))
//11110000
//11110000
//00011100
//00011100
//11110000
//11110000
//11110011
//11110011

#define MAX 64
int map[MAX][MAX];

void Compress(int n, int y, int x) {
	if (n == 1) {
		cout << map[y][x];
		return;
	}

	bool isAllZero = true;
	bool isAllOne = true;

	//해당 범위가 같은 요소인지 확인
	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
		{
			if (map[i][j] == 1)
				isAllZero = false;
			else
				isAllOne = false;

			if (!isAllOne && !isAllZero)
				break;
		}
		//다르면 탈출
		if (!isAllOne && !isAllZero)
			break;
	}

	if (isAllOne)
		cout << 1;
	else if (isAllZero)
		cout << 0;
	else {
		//분할표시
		cout << "(";
		//분할재귀호출
		Compress(n / 2, y, x);						//2사분면(좌상단)
		Compress(n / 2, y, x + (n / 2));			//1사분면(우상단)
		Compress(n / 2, y + (n / 2), x);			//3사분면(좌하단)
		Compress(n / 2, y + (n / 2), x + (n / 2));	//4사분면(우하단)
		cout << ")";
	}
	return;
}

void RevCompress(int n, int y, int x) {
	if (n == 1) {
		cout << map[y][x];
		return;
	}

	bool isAllZero = true;
	bool isAllOne = true;

	//해당 범위가 같은 요소인지 확인
	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
		{
			if (map[i][j] == 1)
				isAllZero = false;
			else
				isAllOne = false;

			if (!isAllOne && !isAllZero)
				break;
		}
		//다르면 탈출
		if (!isAllOne && !isAllZero)
			break;
	}

	if (isAllOne)
		cout << 1;
	else if (isAllZero)
		cout << 0;
	else {
		//분할표시
		cout << "(";
		//분할재귀호출(뒤집어서)
		RevCompress(n / 2, y + (n / 2), x);				//3사분면(좌하단)
		RevCompress(n / 2, y + (n / 2), x + (n / 2));	//4사분면(우하단)
		RevCompress(n / 2, y, x);						//2사분면(좌상단)
		RevCompress(n / 2, y, x + (n / 2));				//1사분면(우상단)
		cout << ")";
	}
	return;
}

bool MapLoad(const char* fileName, int& n) {
	std::ifstream ifs(fileName);
	if (ifs.is_open()) {
		cout << "맵 로드 성공" << endl;
		ifs >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				char m;
				ifs >> m;
				map[i][j] = m - '0';
				cout << map[i][j];
			}
			cout << endl;
		}
		return true;
	}
	return false;
}

int main()
{
	//입출력 속도 절감
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	//cin >> N;

	/*string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < N; j++)
			map[i][j] = str[j] - '0';
	}*/

	if(MapLoad("QMap.txt", N))
		Compress(N, 0, 0);
	cout << endl;
	cout << "Reverse" << endl;
	RevCompress(N, 0, 0);

	return 0;
}