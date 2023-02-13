#include<iostream>
#include<vector>
#include<set>
#include<math.h>

using std::cout;
using std::endl;
using std::cin;

constexpr int MAX = 101;
//������� = ����ū ����
constexpr double INF = std::numeric_limits<double>::max(); //double�� �ִ밪

//��ǥ�� ����� Ÿ�� ������ Coordinate(��ǥ)
using Coord = std::pair<int, int>;
//���, ��ǥ �� ����� Ÿ�� ������
using cCoord = std::pair<double, Coord>;

struct Node {
	int parentX, parentY;
	double h, f, g;
};

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
//��ǥ�� ��������� (���� �ƴ���) Ȯ���ϴ� �Լ�
bool IsUnblocked(std::vector<std::vector<int>>& map, int row, int col) {
	return (map[row][col] == 0); //������ϰ�� ��, �ƴ԰���
}
//H(n)�� ����ϴ� �Լ�
double CalcHVale(int row, int col, Coord dst) {
	return (double)(std::sqrt(std::pow(row - dst.first, 2)) + std::pow(col - dst.second, 2));
}

bool AStar(std::vector<std::vector<int>>& map, Coord src, Coord dst) {
	if (!IsInRange(src.first, src.second) || !IsInRange(dst.first, dst.second)) {
		cout << "��ȿ���� ���� ��ǥ�Դϴ�.(OutRange)" << endl; return false;
	}
	if (!IsUnblocked(map, src.first, src.second) || !IsUnblocked(map, dst.first, dst.second)) {
		cout << "��ȿ���� ���� ��ǥ�Դϴ�.(Blocked)" << endl; return false;
	}
	if (isDestination(src.first, src.second, dst)) {
		cout << "��ȿ���� ���� ��ǥ�Դϴ�.(src == dst)" << endl; return false;
	}

	//�湮ó���� ���
	bool visitedList[MAX][MAX];

	//�޸��� ����(��)�� ���ϴ� ũ�⸸ŭ Ư�������� �����ϴ� �Լ�
	//(�ּ�, ��, ������ ����(������))
	std::memset(visitedList, false, sizeof(visitedList));

	Node nodes[MAX][MAX];
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			nodes[i][j].f = nodes[i][j].g = nodes[i][j].h = INF;
			nodes[i][j].parentX = nodes[i][j].parentY = -1;
		}
	}

	int sx = src.second;
	int sy = src.first;

	nodes[sy][sx].f = nodes[sy][sx].g = nodes[sy][sx].h = 0.0;
	nodes[sy][sx].parentX = sx;
	nodes[sy][sx].parentY = sy;

	std::set<cCoord> openlist;
	openlist.insert({ 0.0, {sy, sx} });

	while (!openlist.empty())
	{
		cCoord cc = *openlist.begin();
		openlist.erase(openlist.begin());

		int y = cc.second.first;
		int x = cc.second.second;

		visitedList[y][x] = true;

		double nf, ng, nh;

		for (int i = 0; i < 4; i++)
		{
			//�����¿� Ȯ��
			int ny = y + dy1[i];
			int nx = x + dx1[i];

			//��ȿ�� ��ǥ�ϰ��
			if (IsInRange(ny, nx)) {
				//�������� �����������
				if (isDestination(ny, nx, dst)) {
					//��ǥ ny, nx�� �θ���ǥ�� ������ǥ �Է�
					nodes[ny][nx].parentX = x;
					nodes[ny][nx].parentY = y;
					//TracePath(nodes, dst);
					return true;
				}//���� �������� ó�� �湮�� ��ǥ�̰� ���� �ƴѰ��
				else if(!visitedList[ny][nx] && !IsUnblocked(map, ny, nx)) {
					ng = nodes[y][x].g + 1.0;	//g(n)�� �Է�
					nh = CalcHVale(y, x, dst);	//h(n)�� �Է�
					nf = ng + nh;				//f(n)�� �Է�
				}
			}
		}
	}
	return false;
}

int main()
{
	Coord src, dst;		//���, ���� ��ǥ����
	cin >> ROW >> COL;	//���, ���� ��ǥ�Է�

	//�� ���� vector�� Ȱ���� 2���� �迭
	std::vector<std::vector<int>> map(ROW, std::vector<int>(COL));
	//����� ���� ��
	std::vector<std::vector<char>> zmap(ROW, std::vector<char>(COL));

	//���ʱ�ȭ
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			std::cin >> map[i][j];
			zmap[i][j] = map[i][j] + '0';

			if (map[i][j] == SRC) {	//��������ϰ��
				src = { i, j };
			}
			if (map[i][j] == DST) {	//���������ϰ��
				dst = { i ,j };
			}
		}
	}
	
	AStar(map, src, dst);

	return 0;
}