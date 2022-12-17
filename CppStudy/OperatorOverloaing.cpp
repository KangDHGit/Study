#include<iostream>

using namespace std;

class Point {
	int x, y;
public:
	Point() : x(0), y(0) {}
	Point(int xx, int yy) :x(xx), y(yy){}
	int getX() { return x; }
	int getY() { return y; }

	// ++Point ���� ���׿����� ��ø
	Point operator++ ()
	{
		++x;
		++y;
		return *this;
	}
	// Point++ ��ġ ���׿����� ��ø
	Point operator++ (int)
	{
		Point temp = Point(x++, y++);
		return temp;
	}
	// --��ġ, ��ġ
	Point operator--() { --x; --y; return *this; }
	Point operator--(int) { Point temp = Point(x--,y--); return temp; }

	//+ ���׿����� ��ø
	Point operator+ (Point ob)
	{
		Point temp;
		temp.x = x + ob.x;
		temp.y = y + ob.y;
		return temp;
	}
	Point operator+(int num)
	{
		Point temp;
		temp.x = x + num;
		temp.y = y + num;
		return temp;
	}
	// * ���׿����� ��ø
	Point operator* (Point ob)
	{
		Point temp;
		temp.x = x * ob.x;
		temp.y = x * ob.y;
		return temp;
	}
	// == ���׿����� ��ø ����
	bool operator== (Point ob);
	// != ���׿�����
	bool operator!= (Point ob);
	// int ����ȯ �Լ�
	operator int();
};
// == ���׿����� ��ø ����
bool Point::operator==(Point ob) { return (x == ob.x && y == ob.y) ? true : false; }
// != ���׿�����
bool Point::operator!=(Point ob) { return (x != ob.x || y != ob.y) ? true : false; }
// int ����ȯ �Լ�
Point::operator int() { return x + y; }

class Num {
public:
	int i;
	Num() : i(10){}
};

int main()
{
	/*int x = 0;
	int y = x++;
	cout << x << ", " << y << endl;

	Point ob(1,1);
	Point test = ob++;
	Point test2 = ob;
	cout << test.getX() << ", " << test.getY() << endl;
	cout << test2.getX() << ", " << test2.getY() << endl;*/

	//Point ob1(3, 5), ob2(4, 6), ob3;
	//cout << ob3.getX() << ", " << ob3.getY() << " ";
	//ob3 = ob1 + ob2; // ob1�� +������ �Լ��� ȣ���ϴ� ��ü�� ob2�� �Ű������� �ѱ�
	//cout << ob3.getX() << ", " << ob3.getY() << " ";
	//cout << endl;

	//if (ob1 == ob3) { cout << "��" << endl; }
	//else { cout << "����" << endl; }

	//if(ob3 == (ob1+ob2)) {cout << "��" << endl; }
	//else { cout << "����" << endl; }

	/*Point ob1(3, 5), ob2(4, 6);
	int i;
	i = ob1;
	cout << i << endl;
	cout << ob2 + 3 << endl;*/

	/*Num num ,num2;
	int Num::* n;
	n = &Num::i;

	cout << &n << endl;
	cout << &(num.i) << endl;
	cout << &(num.*n) << endl;*/

	//A oa(2);
	/*B ob(1,2);
	ob.showA();
	ob.showB();
	C oc(10, 20, 30);
	oc.showA();
	oc.showB();
	oc.showC()*/;

	return 0;
}