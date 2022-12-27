#include<iostream>
#include<math.h>

using std::cout;
using std::endl;
using std::cin;

// p75
// 1. 2���� ��ǥ �������� �ϳ��� ���� ��Ÿ���� ����ü ���� �� typedef ���
typedef struct point {
	int x;
	int y;

	// 4. �ΰ��� point �� �޾Ƽ� �Ÿ��� ����ϴ� �Լ�
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
	// 2.����ü ���� p1, p2 ����
	// 3. ���� (1,2) (9,8) �� �ʱ�ȭ
	Point p1 = { 1,2 };
	Point p2 = { 9, 8 };
	double distance = Point::get_distance(p1, p2);
	cout << distance << endl;
	return 0;
}