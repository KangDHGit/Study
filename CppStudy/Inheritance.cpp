#include<iostream>
#include<string>

using namespace std;

class A {
private:
	int x;
public:
	void setX(int i) { x = i; }
	void showX() { cout << x << endl; }
};

class B : public A {
	int y;
public:
	void setY(int i) { y = i; }
	void showY() { cout << y << endl; }
};

class C {
private:
	int x ;
public:
	void setX(int i) { x = i; }
	void showX() { cout << x << endl; }
};

class D : private A{
	int y;
public:
	void setXY(int i) { setX(i); y = i; }
	void showXY() { showX(); cout << y << endl; }
};

int main()
{
	B bb;
	//bb.setX(1); // ��������Ӽ��� private�� ������ ����
	bb.setY(2);
	//bb.showX(); // ��������Ӽ��� private�� ������ ����
	bb.showY();
	return 0;
}