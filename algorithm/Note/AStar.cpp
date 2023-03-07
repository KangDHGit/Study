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
//무량대수 = 가장 큰 단위
constexpr double INF = std::numeric_limits<double>::max(); //double의 최대값

//좌표로 사용할 타입 재정의 Coordinate(좌표)
using Coord = std::pair<int, int>;
//비용, 좌표 로 사용할 타입 재정의
using cCoord = std::pair<double, Coord>;

struct Node {
	int parentX, parentY;
	double h, f, g;
};
//출력을 위한 맵
char zmap[MAX][MAX];

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
//좌표가 빈공간인지(벽이 아닌지) 확인하는 함수
bool IsUnblocked(std::vector<std::vector<int>>& map, int row, int col) {
	return (map[row][col] == 0); //빈공간일경우 참, 아님거짓
}
//h(x)를 계산하는 함수
double CalcHVale(int row, int col, Coord dst) {
	return (double)(std::sqrt(std::pow(row - dst.first, 2) + std::pow(col - dst.second, 2)));
}
//백트래킹을 이용하여 최단경로를 탐색하는 함수
void TracePath(Node nodes[MAX][MAX], Coord dst) {
	//최단경로를 저장할 스택
	std::stack<Coord> pathS;

	//도착 좌표
	int y = dst.first;
	int x = dst.second;
	//도착 좌표 저장
	pathS.push({ y, x });

	//출발점이 아닐때까지 반복(출발점은 자기 좌표랑 부모노드 좌표랑 같음)
	while (!(nodes[y][x].parentX == x && nodes[y][x].parentY == y))
	{	//도착좌표의 부모노드 부터 출발노드를 부모노드로 가진 노드까지 반복
		//부모노드 좌표를 스택에 삽입
		int tempX = nodes[y][x].parentX;
		int tempY = nodes[y][x].parentY;
		x = tempX;
		y = tempY;
		pathS.push({ y, x });
	}

	while (!pathS.empty())
	{	//최단경로가 입력된 스택노드들의 출력변경
		zmap[pathS.top().first][pathS.top().second] = '*';
		pathS.pop();
	}
}

//A* 알고리즘 실행함수
bool AStar(std::vector<std::vector<int>>& map, Coord src, Coord dst) {
	//출발노드와 도착노드의 좌표가 유효한지 확인
	if (!IsInRange(src.second, src.first) || !IsInRange(src.second, src.first)) {
		cout << "유효하지 않은 좌표입니다.(OutRange)" << endl; return false;
	}
	if (!IsUnblocked(map, src.second, src.first) || !IsUnblocked(map, src.second, src.first)) {
		cout << "유효하지 않은 좌표입니다.(Blocked)" << endl; return false;
	}
	if (isDestination(src.second, src.first, dst)) {
		cout << "유효하지 않은 좌표입니다.(src == dst)" << endl; return false;
	}

	//방문처리할 배열선언
	bool visitedList[MAX][MAX];

	//메모리의 내용(값)을 원하는 크기만큼 특정값으로 세팅하는 함수
	//(주소, 값, 세팅할 범위(사이즈))
	std::memset(visitedList, false, sizeof(visitedList));

	//맵에 맞게 노드 생성 및 무량대수로 초기화
	Node nodes[MAX][MAX];
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			nodes[i][j].f = nodes[i][j].g = nodes[i][j].h = INF;
			nodes[i][j].parentX = nodes[i][j].parentY = -1;
		}
	}

	int sx = src.second;
	int sy = src.first;
	//출발노드 초기화
	nodes[sy][sx].f = nodes[sy][sx].g = nodes[sy][sx].h = 0.0;
	nodes[sy][sx].parentX = sx;
	nodes[sy][sx].parentY = sy;

	//set 컨테이너에 출발데이터 입력
	std::set<cCoord> openlist;
	openlist.insert({ 0.0, {sy, sx} });

	while (!openlist.empty())
	{
		//set의 맨앞 데이터를 꺼내오고 삭제
		cCoord cc = *openlist.begin();
		openlist.erase(openlist.begin());

		//가져온 데이터의 노드(second), x(second.second) y(second.first)
		int y = cc.second.first;
		int x = cc.second.second;
		//노드 방문처리
		visitedList[y][x] = true;
		cout << "방문한 노드 : " << x << ", " << y << endl;

		double nf, ng, nh;

		//상하좌우 확인
		for (int i = 0; i < 4; i++)
		{
			//상하좌우 좌표
			int ny = y + dy1[i];
			int nx = x + dx1[i];

			//유효한 좌표일경우
			if (IsInRange(ny, nx)) {
				//목적지에 도착했을경우
				if (isDestination(ny, nx, dst)) {
					//좌표 ny, nx의 부모좌표에 현재좌표 입력
					nodes[ny][nx].parentX = x;
					nodes[ny][nx].parentY = y;
					TracePath(nodes, dst);
					return true;
				}//도착 안했지만 열려있는 좌표이고 벽이 아닌경우
				else if(!visitedList[ny][nx] && IsUnblocked(map, ny, nx)) {
					ng = nodes[y][x].g + 1.0;		//g(x)값 입력
					nh = CalcHVale(ny, nx, dst);	//h(x)값 입력
					nf = ng + nh;					//f(x)값 입력

					//f(x)가 갱신이 한번도 안된 좌표거나 이미 갱신이 됐지만 새로구한 f(x)이 더 작을경우 
					if (nodes[ny][nx].f == INF || nodes[ny][nx].f > nf) {
						nodes[ny][nx].f = nf; //값 입력
						nodes[ny][nx].g = ng;
						nodes[ny][nx].h = nh;
						//좌표 ny, nx의 부모좌표에 현재좌표 입력
						nodes[ny][nx].parentX = x;
						nodes[ny][nx].parentY = y;

						//set에 데이터 입력
						openlist.insert({ nf, { ny, nx } });
					}
				}
			}
		}

		//대각선 확인
		for (int i = 0; i < 4; i++)
		{
			//대각선 좌표
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
					ng = nodes[y][x].g + 1.414;		//g(x)값 입력
					nh = CalcHVale(ny, nx, dst);	//h(x)값 입력
					nf = ng + nh;					//f(x)값 입력

					if (nodes[ny][nx].f == INF || nodes[ny][nx].f > nf) {
						nodes[ny][nx].f = nf; //값 입력
						nodes[ny][nx].g = ng;
						nodes[ny][nx].h = nh;
						
						nodes[ny][nx].parentX = x;
						nodes[ny][nx].parentY = y;

						//set에 데이터 입력
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
		cout << "맵 로드 성공" << endl;
		ifs >> ROW >> COL;
		cout << "맵 크기 : " << ROW << " X " << COL << endl;
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
	Coord src, dst;		//출발, 도착 좌표선언

	//맵 읽어오기
	std::vector<std::vector<int>> map = MapFileLoad("Map1.txt");

	//출력맵(zmap) 초기화
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			zmap[i][j] = map[i][j] + '0';

			if (map[i][j] == SRC) {	//출발지점일경우
				cout << "출발  지점 : " << j << ", " << i << endl;
				src = { i, j };
			}
			if (map[i][j] == DST) {	//도착지점일경우
				cout << "도착  지점 : " << j << ", " << i << endl;
				dst = { i ,j };
			}
		}
	}

	//cin >> ROW >> COL;	//맵크기 입력
	//
	////맵 생성 vector를 활용한 2차원 배열
	//std::vector<std::vector<int>> map(ROW, std::vector<int>(COL));

	////맵초기화
	//for (int i = 0; i < ROW; i++) {
	//	for (int j = 0; j < COL; j++) {
	//		std::cin >> map[i][j];
	//		zmap[i][j] = map[i][j] + '0';

	//		if (map[i][j] == SRC) {	//출발지점일경우
	//			src = { i, j };
	//			map[i][j] = '0';
	//		}
	//		if (map[i][j] == DST) {	//도착지점일경우
	//			dst = { i ,j };
	//			map[i][j] = '0';
	//		}
	//	}
	//}
	
	if (AStar(map, src, dst)) {
		cout << "경로찾기에 성공했습니다." << endl;
		PrintMap();
	}
	else
		cout << "경로찾기에 실패했습니다." << endl;

	return 0;
}