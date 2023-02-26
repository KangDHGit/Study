#include<iostream>

using std::cout;
using std::endl;
using std::cin;

//template class
template<typename T>
class AA {
	T num;
public:
	AA(T a) : num(a){}
	static void Print();
};

// template func
template<typename T1, typename T2, typename T3>
T3 Sum(T1 a, T2 b) { return a + b; }

int main()
{
	AA<int> aa(10);
	AA<float>* aaptr = new AA<float>(0.989f);

	cout << Sum<int, float, float>(10, 2.5) << endl;	//리턴값이 누구인지 알려줘야 함

	AA<int>::Print();

	return 0;
}