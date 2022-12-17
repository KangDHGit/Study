#include<iostream>
#include<string>

using namespace std;
// 가상함수 구현 및 오버라이딩
class A {
public:
	virtual int SS(int i) { return i * 2; }
	~A() { cout << "A 소멸자 호출" << endl; }
};

class B : public A {
public:
	int SS(int i) { return i * 3; }
	~B() { cout << "B 소멸자 호출" << endl; }
};

// 추상클래스 및 순수가상함수 구현
class Shape { // 추상클래스(abstract class)
protected:
	double x, y;
public:
	virtual double area() = 0; // 순수가상함수
};

class Rectangle : public Shape {
	double height, width;
public:
	Rectangle(double h, double w) :height(h), width(w){}
	double area() { return(width * height); }
};

class Triangle : public Shape {
	double height, width;
public:
	Triangle(double h, double w) :height(h), width(w){}
	double area() { return (width * height) / 2.0; }
};

int main()
{
	/*A aa;
	B bb;
	cout << aa.SS(2) << endl;
	cout << bb.SS(2) << endl;
	A* pA = new A();
	A* pB = new B();
	cout << pA->SS(3) << endl;
	cout << pB->SS(3) << endl;
	delete pA; delete pB;*/

	//Shape ss; // 컴파일 오류(추상클래스는 객체를 생성할 수 없음)
	Shape* pS;
	Rectangle nemo(10.0, 20.0);
	Triangle semo(10.0, 20.0);
	
	pS = &nemo;
	cout << "네모 면적 : " << pS->area() << endl;
	pS = &semo;
	cout << "세모 면적 : " << pS->area() << endl;

	return 0;
}