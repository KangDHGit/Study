#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<stack>
#include<math.h>

using std::cout;
using std::endl;
using std::cin;

constexpr int MAX = 101;
//������� = ���� ū ����
constexpr double INF = std::numeric_limits<double>::max(); //double�� �ִ밪

//��ǥ�� ����� Ÿ�� ������ Coordinate(��ǥ)
using Coord = std::pair<int, int>;
//���, ��ǥ �� ����� Ÿ�� ������
using cCoord = std::pair<double, Coord>;

struct Node {
	int parentX, parentY;
	double h, f, g;
};
//����� ���� ��
char zmap[MAX][MAX];

//����
const int dx1[4] = { 0, 0, 1, -1 };
const int dy1[4] = { -1, 1, 0, 0 };
//�밢��
const int dx2[4] = { 1, -1, -1, 1 };
const int dy2[4] = { -1, 1, -1, 1 };

#define SRC 2	//�����
#define DST 3	//������

int ROW = 0, COL = 0;

//���������� �Դ��� Ȯ���ϴ� �Լ�
bool isDestination(int row, int col, Coord dst) {
	return (row == dst.first && col == dst.second);
}
//��ǥ�� map�ȿ� �ִ���(��ȿ�� ��ǥ����) Ȯ���ϴ� �Լ�
bool IsInRange(int row, int col) {
	return (row >= 0 && row < ROW && col >= 0 && col < COL);
}
//��ǥ�� ���������(���� �ƴ���) Ȯ���ϴ� �Լ�
bool IsUnblocked(std::vector<std::vector<int>>& map, int row, int col) {
	return (map[row][col] == 0); //������ϰ�� ��, �ƴ԰���
}
//h(x)�� ����ϴ� �Լ�
double CalcHVale(int row, int col, Coord dst) {
	return (double)(std::sqrt(std::pow(row - dst.first, 2) + std::pow(col - dst.second, 2)));
}
//��Ʈ��ŷ�� �̿��Ͽ� �ִܰ�θ� Ž���ϴ� �Լ�
void TracePath(Node nodes[MAX][MAX], Coord dst) {
	//�ִܰ�θ� ������ ����
	std::stack<Coord> pathS;

	//���� ��ǥ
	int y = dst.first;
	int x = dst.second;
	//���� ��ǥ ����
	pathS.push({ y, x });

	//������� �ƴҶ����� �ݺ�(������� �ڱ� ��ǥ�� �θ��� ��ǥ�� ����)
	while (!(nodes[y][x].parentX == x && nodes[y][x].parentY == y))
	{	//������ǥ�� �θ��� ���� ��߳�带 �θ���� ���� ������ �ݺ�
		//�θ��� ��ǥ�� ���ÿ� ����
		int tempX = nodes[y][x].parentX;
		int tempY = nodes[y][x].parentY;
		x = tempX;
		y = tempY;
		pathS.push({ y, x });
	}

	while (!pathS.empty())
	{	//�ִܰ�ΰ� �Էµ� ���ó����� ��º���
		zmap[pathS.top().first][pathS.top().second] = '*';
		pathS.pop();
	}
}

//A* �˰��� �����Լ�
bool AStar(std::vector<std::vector<int>>& map, Coord src, Coord dst) {
	//��߳��� ��������� ��ǥ�� ��ȿ���� Ȯ��
	if (!IsInRange(src.second, src.first) || !IsInRange(src.second, src.first)) {
		cout << "��ȿ���� ���� ��ǥ�Դϴ�.(OutRange)" << endl; return false;
	}
	if (!IsUnblocked(map, src.second, src.first) || !IsUnblocked(map, src.second, src.first)) {
		cout << "��ȿ���� ���� ��ǥ�Դϴ�.(Blocked)" << endl; return false;
	}
	if (isDestination(src.second, src.first, dst)) {
		cout << "��ȿ���� ���� ��ǥ�Դϴ�.(src == dst)" << endl; return false;
	}

	//�湮ó���� �迭����
	bool visitedList[MAX][MAX];

	//�޸��� ����(��)�� ���ϴ� ũ�⸸ŭ Ư�������� �����ϴ� �Լ�
	//(�ּ�, ��, ������ ����(������))
	std::memset(visitedList, false, sizeof(visitedList));

	//�ʿ� �°� ��� ���� �� ��������� �ʱ�ȭ
	Node nodes[MAX][MAX];
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			nodes[i][j].f = nodes[i][j].g = nodes[i][j].h = INF;
			nodes[i][j].parentX = nodes[i][j].parentY = -1;
		}
	}

	int sx = src.second;
	int sy = src.first;
	//��߳�� �ʱ�ȭ
	nodes[sy][sx].f = nodes[sy][sx].g = nodes[sy][sx].h = 0.0;
	nodes[sy][sx].parentX = sx;
	nodes[sy][sx].parentY = sy;

	//set �����̳ʿ� ��ߵ����� �Է�
	std::set<cCoord> openlist;
	openlist.insert({ 0.0, {sy, sx} });

	while (!openlist.empty())
	{
		//set�� �Ǿ� �����͸� �������� ����
		cCoord cc = *openlist.begin();
		openlist.erase(openlist.begin());

		//������ �������� ���(second), x(second.second) y(second.first)
		int y = cc.second.first;
		int x = cc.second.second;
		//��� �湮ó��
		visitedList[y][x] = true;
		cout << "�湮�� ��� : " << x << ", " << y << endl;

		double nf, ng, nh;

		//�����¿� Ȯ��
		for (int i = 0; i < 4; i++)
		{
			//�����¿� ��ǥ
			int ny = y + dy1[i];
			int nx = x + dx1[i];

			//��ȿ�� ��ǥ�ϰ��
			if (IsInRange(ny, nx)) {
				//�������� �����������
				if (isDestination(ny, nx, dst)) {
					//��ǥ ny, nx�� �θ���ǥ�� ������ǥ �Է�
					nodes[ny][nx].parentX = x;
					nodes[ny][nx].parentY = y;
					TracePath(nodes, dst);
					return true;
				}//���� �������� �����ִ� ��ǥ�̰� ���� �ƴѰ��
				else if(!visitedList[ny][nx] && IsUnblocked(map, ny, nx)) {
					ng = nodes[y][x].g + 1.0;		//g(x)�� �Է�
					nh = CalcHVale(ny, nx, dst);	//h(x)�� �Է�
					nf = ng + nh;					//f(x)�� �Է�

					//f(x)�� ������ �ѹ��� �ȵ� ��ǥ�ų� �̹� ������ ������ ���α��� f(x)�� �� ������� 
					if (nodes[ny][nx].f == INF || nodes[ny][nx].f > nf) {
						nodes[ny][nx].f = nf; //�� �Է�
						nodes[ny][nx].g = ng;
						nodes[ny][nx].h = nh;
						//��ǥ ny, nx�� �θ���ǥ�� ������ǥ �Է�
						nodes[ny][nx].parentX = x;
						nodes[ny][nx].parentY = y;

						//set�� ������ �Է�
						openlist.insert({ nf, { ny, nx } });
					}
				}
			}
		}

		//�밢�� Ȯ��
		for (int i = 0; i < 4; i++)
		{
			//�밢�� ��ǥ
			int ny = y + dy2[i];
			int nx = x + dx2[i];

			if (IsInRange(ny, nx)) {
				if (isDestination(ny, nx, dst)) {
					nodes[ny][nx].parentX = x;
					nodes[ny][nx].parentY = y;
					TracePath(nodes, dst);
					return true;
				}
				else if (!visitedList[ny][nx] && IsUnblocked(map, ny, nx)) {
					ng = nodes[y][x].g + 1.414;		//g(x)�� �Է�
					nh = CalcHVale(ny, nx, dst);	//h(x)�� �Է�
					nf = ng + nh;					//f(x)�� �Է�

					if (nodes[ny][nx].f == INF || nodes[ny][nx].f > nf) {
						nodes[ny][nx].f = nf; //�� �Է�
						nodes[ny][nx].g = ng;
						nodes[ny][nx].h = nh;
						
						nodes[ny][nx].parentX = x;
						nodes[ny][nx].parentY = y;

						//set�� ������ �Է�
						openlist.insert({ nf, { ny, nx } });
					}
				}
			}
		}
	}
	return false;
}

void PrintMap() {
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
			cout << zmap[i][j];
		cout << '\n';
	}
}

std::vector<std::vector<int>> MapFileLoad(const char* fileName) {
	std::ifstream ifs(fileName);

	if (ifs.is_open()) {
		cout << "�� �ε� ����" << endl;
		ifs >> ROW >> COL;
		cout << "�� ũ�� : " << ROW << " X " << COL << endl;
		std::vector<std::vector<int>> result(ROW, std::vector<int>(COL));

		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				ifs >> result[i][j];
			}
		}

		return result;
	}
	return std::vector<std::vector<int>>();
}

int main()
{
	Coord src, dst;		//���, ���� ��ǥ����

	//�� �о����
	std::vector<std::vector<int>> map = MapFileLoad("Map1.txt");

	//��¸�(zmap) �ʱ�ȭ
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			zmap[i][j] = map[i][j] + '0';

			if (map[i][j] == SRC) {	//��������ϰ��
				cout << "���  ���� : " << j << ", " << i << endl;
				src = { i, j };
			}
			if (map[i][j] == DST) {	//���������ϰ��
				cout << "����  ���� : " << j << ", " << i << endl;
				dst = { i ,j };
			}
		}
	}

	//cin >> ROW >> COL;	//��ũ�� �Է�
	//
	////�� ���� vector�� Ȱ���� 2���� �迭
	//std::vector<std::vector<int>> map(ROW, std::vector<int>(COL));

	////���ʱ�ȭ
	//for (int i = 0; i < ROW; i++) {
	//	for (int j = 0; j < COL; j++) {
	//		std::cin >> map[i][j];
	//		zmap[i][j] = map[i][j] + '0';

	//		if (map[i][j] == SRC) {	//��������ϰ��
	//			src = { i, j };
	//			map[i][j] = '0';
	//		}
	//		if (map[i][j] == DST) {	//���������ϰ��
	//			dst = { i ,j };
	//			map[i][j] = '0';
	//		}
	//	}
	//}
	
	if (AStar(map, src, dst)) {
		cout << "���ã�⿡ �����߽��ϴ�." << endl;
		PrintMap();
	}
	else
		cout << "���ã�⿡ �����߽��ϴ�." << endl;

	return 0;
}