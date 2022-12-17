#include<iostream>
#include<string>

using namespace std;
// 포인터형식
void pSwap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void rSwap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// 참조자를 이용한 Swap함수
template <class T> void refSwap(T& t1, T& t2)
{
	T temp = t1;
	t1 = t2;
	t2 = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	cout << a << " " << b << endl;
	//pSwap(&a, &b);
	refSwap(a, b);
	cout << a << " " << b << endl;

	int &var = a;
	var++;
	cout << a << " " << b << endl;
	cout << &a << endl; cout << &var << endl;
	return 0;
}
