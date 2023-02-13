#include<iostream>
#include<vector>
#include<set>
#include<math.h>

using std::cout;
using std::endl;
using std::cin;

constexpr int MAX = 101;
//무량대수 = 가장큰 단위
constexpr double INF = std::numeric_limits<double>::max(); //double의 최대값

//좌표로 사용할 타입 재정의 Coordinate(좌표)
using Coord = std::pair<int, int>;
//비용, 좌표 로 사용할 타입 재정의
using cCoord = std::pair<double, Coord>;

struct Node {
	int parentX, parentY;
	double h, f, g;
};

//직선
const int dx1[4] = { 0, 0, 1, -1 };
const int dy1[4] = { -1, 1, 0, 0 };
//대각선
const int dx2[4] = { 1, -1, -1, 1 };
const int dy2[4] = { -1, 1, -1, 1 };

#define SRC 2	//출발점
#define DST 3	//도착점

int ROW = 0, COL = 0;

//도착지점에 왔는지 확인하는 함수
bool isDestination(int row, int col, Coord dst) {
	return (row == dst.first && col == dst.second);
}
//좌표가 map안에 있는지(유효한 좌표인지) 확인하는 함수
bool IsInRange(int row, int col) {
	return (row >= 0 && row < ROW && col >= 0 && col < COL);
}
//좌표가 빈공간인지 (벽이 아닌지) 확인하는 함수
bool IsUnblocked(std::vector<std::vector<int>>& map, int row, int col) {
	return (map[row][col] == 0); //빈공간일경우 참, 아님거짓
}
//H(n)을 계산하는 함수
double CalcHVale(int row, int col, Coord dst) {
	return (double)(std::sqrt(std::pow(row - dst.first, 2)) + std::pow(col - dst.second, 2));
}

bool AStar(std::vector<std::vector<int>>& map, Coord src, Coord dst) {
	if (!IsInRange(src.first, src.second) || !IsInRange(dst.first, dst.second)) {
		cout << "유효하지 않은 좌표입니다.(OutRange)" << endl; return false;
	}
	if (!IsUnblocked(map, src.first, src.second) || !IsUnblocked(map, dst.first, dst.second)) {
		cout << "유효하지 않은 좌표입니다.(Blocked)" << endl; return false;
	}
	if (isDestination(src.first, src.second, dst)) {
		cout << "유효하지 않은 좌표입니다.(src == dst)" << endl; return false;
	}

	//방문처리할 배멸
	bool visitedList[MAX][MAX];

	//메모리의 내용(값)을 원하는 크기만큼 특정값으로 세팅하는 함수
	//(주소, 값, 세팅할 범위(사이즈))
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
			//상하좌우 확인
			int ny = y + dy1[i];
			int nx = x + dx1[i];

			//유효한 좌표일경우
			if (IsInRange(ny, nx)) {
				//목적지에 도착했을경우
				if (isDestination(ny, nx, dst)) {
					//좌표 ny, nx의 부모좌표에 현재좌표 입력
					nodes[ny][nx].parentX = x;
					nodes[ny][nx].parentY = y;
					//TracePath(nodes, dst);
					return true;
				}//도착 안했지만 처음 방문한 좌표이고 벽이 아닌경우
				else if(!visitedList[ny][nx] && !IsUnblocked(map, ny, nx)) {
					ng = nodes[y][x].g + 1.0;	//g(n)값 입력
					nh = CalcHVale(y, x, dst);	//h(n)값 입력
					nf = ng + nh;				//f(n)값 입력
				}
			}
		}
	}
	return false;
}

int main()
{
	Coord src, dst;		//출발, 도착 좌표선언
	cin >> ROW >> COL;	//출발, 도착 좌표입력

	//맵 생성 vector를 활용한 2차원 배열
	std::vector<std::vector<int>> map(ROW, std::vector<int>(COL));
	//출력을 위한 맵
	std::vector<std::vector<char>> zmap(ROW, std::vector<char>(COL));

	//맵초기화
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			std::cin >> map[i][j];
			zmap[i][j] = map[i][j] + '0';

			if (map[i][j] == SRC) {	//출발지점일경우
				src = { i, j };
			}
			if (map[i][j] == DST) {	//도착지점일경우
				dst = { i ,j };
			}
		}
	}
	
	AStar(map, src, dst);

	return 0;
}