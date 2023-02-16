#include<iostream>
#include<fstream>
#include<string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

//N ��N ũ���� ������ �־��� ��, �� ������ ������ ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//ù° �ٿ��� ������ ũ�⸦ ��Ÿ���� ���� N �� �־�����. N �� ������ 2�� �������� �־�����
//1 �� N �� 64�� ������ ������. �� ��° �ٺ��ʹ� ���� N�� ���ڿ��� N�� ���´�. �� ���ڿ��� 0 �Ǵ� 1�� ���ڷ� �̷���� ������, ������ �� ������ ��Ÿ����.
//�����Է�			�������
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

	//�ش� ������ ���� ������� Ȯ��
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
		//�ٸ��� Ż��
		if (!isAllOne && !isAllZero)
			break;
	}

	if (isAllOne)
		cout << 1;
	else if (isAllZero)
		cout << 0;
	else {
		//����ǥ��
		cout << "(";
		//�������ȣ��
		Compress(n / 2, y, x);						//2��и�(�»��)
		Compress(n / 2, y, x + (n / 2));			//1��и�(����)
		Compress(n / 2, y + (n / 2), x);			//3��и�(���ϴ�)
		Compress(n / 2, y + (n / 2), x + (n / 2));	//4��и�(���ϴ�)
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

	//�ش� ������ ���� ������� Ȯ��
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
		//�ٸ��� Ż��
		if (!isAllOne && !isAllZero)
			break;
	}

	if (isAllOne)
		cout << 1;
	else if (isAllZero)
		cout << 0;
	else {
		//����ǥ��
		cout << "(";
		//�������ȣ��(�����)
		RevCompress(n / 2, y + (n / 2), x);				//3��и�(���ϴ�)
		RevCompress(n / 2, y + (n / 2), x + (n / 2));	//4��и�(���ϴ�)
		RevCompress(n / 2, y, x);						//2��и�(�»��)
		RevCompress(n / 2, y, x + (n / 2));				//1��и�(����)
		cout << ")";
	}
	return;
}

bool MapLoad(const char* fileName, int& n) {
	std::ifstream ifs(fileName);
	if (ifs.is_open()) {
		cout << "�� �ε� ����" << endl;
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
	//����� �ӵ� ����
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