#include<iostream>

using namespace std;

class Point {
	int x, y;
public:
	Point() : x(0), y(0) {}
	Point(int xx, int yy) :x(xx), y(yy){}
	int getX() { return x; }
	int getY() { return y; }

	// ++Point 전차 단항연산자 중첩
	Point operator++ ()
	{
		++x;
		++y;
		return *this;
	}
	// Point++ 후치 단항연산자 중첩
	Point operator++ (int)
	{
		Point temp = Point(x++, y++);
		return temp;
	}
	// --전치, 후치
	Point operator--() { --x; --y; return *this; }
	Point operator--(int) { Point temp = Point(x--,y--); return temp; }

	//+ 이항연산자 중첩
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
	// * 이항연산자 중첩
	Point operator* (Point ob)
	{
		Point temp;
		temp.x = x * ob.x;
		temp.y = x * ob.y;
		return temp;
	}
	// == 이항연산자 중첩 선언
	bool operator== (Point ob);
	// != 이항연산자
	bool operator!= (Point ob);
	// int 형변환 함수
	operator int();
};
// == 이항연산자 중첩 구현
bool Point::operator==(Point ob) { return (x == ob.x && y == ob.y) ? true : false; }
// != 이항연산자
bool Point::operator!=(Point ob) { return (x != ob.x || y != ob.y) ? true : false; }
// int 형변환 함수
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
	//ob3 = ob1 + ob2; // ob1이 +연산자 함수를 호출하는 주체로 ob2를 매개변수로 넘김
	//cout << ob3.getX() << ", " << ob3.getY() << " ";
	//cout << endl;

	//if (ob1 == ob3) { cout << "참" << endl; }
	//else { cout << "거짓" << endl; }

	//if(ob3 == (ob1+ob2)) {cout << "참" << endl; }
	//else { cout << "거짓" << endl; }

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