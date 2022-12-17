#include<iostream>
#include<string>

using namespace std;

template <class T> T Max(T t1, T t2)
{
	return t1 > t2 ? t1 : t2;
}

template <class T> T Min(T t1, T t2)
{
	return t1 > t2 ? t2 : t1;
}
// 
template <class T1, class T2> void Print(T1 t1, T2 t2)
{
	cout << t1 << " " << t2 << endl;
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
	cout << "Max값은 = " << Max(1, 2) << endl;
	cout << "Max값은 = " << Max(7.5, 3.6) << endl;
	cout << "Max값은 = " << Max('A', 'B') << endl;
	Print("string", 2);
	int a = 10;
	int b = 20;
	cout << a << " " << b << endl;
	refSwap(a, b);
	cout << a << " " << b << endl;

	return 0;
}