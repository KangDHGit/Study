#include<iostream>
#include<math.h>

using std::cout;
using std::endl;
using std::cin;

// p75
// 1. 2차원 좌표 공간에서 하나의 점을 나타내는 구조체 정의 및 typedef 사용
typedef struct point {
	int x;
	int y;

	// 4. 두개의 point 를 받아서 거리를 계산하는 함수
	static double get_distance(point p1, point p2)
	{
		int x = p1.x - p2.x;
		int y = p1.y - p2.y;
		double distacne = sqrt(((x * x) + (y * y)));
		return distacne;
	}
} Point;

int main()
{
	// 2.구조체 변수 p1, p2 정의
	// 3. 각각 (1,2) (9,8) 로 초기화
	Point p1 = { 1,2 };
	Point p2 = { 9, 8 };
	double distance = Point::get_distance(p1, p2);
	cout << distance << endl;
	return 0;
}