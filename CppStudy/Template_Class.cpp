#include<iostream>
#include<string>

using namespace std;

// int형 클래스
class CCC1
{
	int x;
	int y;
public:
	CCC1(int xx, int yy) : x(xx), y(yy) {}
	void Print() { cout << x << ", " << y << endl; }
};
// double형 클래스
class CCC2
{
	double x;
	double y;
public:
	CCC2(double xx, double yy) : x(xx), y(yy) {}
	void Print() { cout << x << ", " << y << endl; }
};
// char형 클래스
class CCC3
{
	char x;
	const char* y;
public:
	CCC3(char xx, const char* yy) : x(xx), y(yy) {}
	void Print() { cout << x << ", " << y << endl; }
};

template <class T1, class T2> class CCC {
	T1 x;
	T2 y;
public:
	CCC(T1 xx, T2 yy) : x(xx), y(yy) {}
	void Print() { cout << x << ", " << y << endl; }
};

int main()
{
	/*CCC1 c1(10, 20);
	CCC2 c2(3.5, 5.5);
	CCC3 c3('I', "love you");
	c1.Print();
	c2.Print();
	c3.Print();*/

	CCC<int, int> c1(10, 10);
	CCC<double, double> c2(3.5, 5.5);
	CCC<char, string> c3('I', "love you");
	
	c1.Print();
	c2.Print();
	c3.Print();

	return 0;
}