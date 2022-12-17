#include<iostream>

using namespace std;

class A {
	int x, y;
public:
	A(int xx, int yy) :x(xx), y(yy) {}
	friend class B;
};

class B {
	int b, total;
public:
	B(int bb) : b(bb) {}
	void sum(A a) { total = a.x + a.y + b; }
	void print() { cout << total << endl; }
};

int main()
{
	A a(10, 20);
	B b(30);
	b.sum(a);
	b.print();

	return 0;
}