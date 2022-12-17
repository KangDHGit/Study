#include<iostream>
#include<string>

using namespace std;
// �����Լ� ���� �� �������̵�
class A {
public:
	virtual int SS(int i) { return i * 2; }
	~A() { cout << "A �Ҹ��� ȣ��" << endl; }
};

class B : public A {
public:
	int SS(int i) { return i * 3; }
	~B() { cout << "B �Ҹ��� ȣ��" << endl; }
};

// �߻�Ŭ���� �� ���������Լ� ����
class Shape { // �߻�Ŭ����(abstract class)
protected:
	double x, y;
public:
	virtual double area() = 0; // ���������Լ�
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

	//Shape ss; // ������ ����(�߻�Ŭ������ ��ü�� ������ �� ����)
	Shape* pS;
	Rectangle nemo(10.0, 20.0);
	Triangle semo(10.0, 20.0);
	
	pS = &nemo;
	cout << "�׸� ���� : " << pS->area() << endl;
	pS = &semo;
	cout << "���� ���� : " << pS->area() << endl;

	return 0;
}