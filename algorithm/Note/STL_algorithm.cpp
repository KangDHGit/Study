#include<iostream>
#include<algorithm>
#include<vector>

using std::cout;
using std::endl;
using std::cin;

//functor
//함수처럼 사용할 수 있는 객체
//함수를 가지고 있는 구조체
struct Func {
	void operator()(int x) {
		cout << x * x << endl;
	}
};

void f(int x) {
	cout << x * x << endl;
}

int main()
{
	//알고리즘 find
	//반복자를 반환
	//못찾을 경우는 end()를 반환(쓰레기값)
	//operator == 가 사용되므로 클래스의 경우 오버로딩이 필요

	std::vector<int> vec{ 1, 3, 7, 4, 8, 10 };
	const auto result = std::find(vec.begin(), vec.end(), 4);

	//일정 범위만 찾기
	//const auto result = std::find(vec.begin(), vec.begin() + 2, 4);
	//이때 찾았는지 확인할떄
	//if(result != vec.begin() + 2)

	if(result != vec.end())
		cout << *result << endl;

	//알고리즘 for_each
	//각 요소를 인자로 함수 호출
	//함수를 인자로 넘기는 방법
	//functor, function pointer, lambda expression

	//functor 활용
	Func f;
	f(3);
	//std::for_each(vec.begin(), vec.end(), f);

	//function pointer 활용
	//함수의 주소(함수의 이름)
	//std::for_each(vec.begin(), vec.end(), f);

	//lamda expression
	//익명함수
	//함수에 이름을 부여하지 않고, 한번만 사용하기 위함
	std::for_each(vec.begin(), vec.end(), [](int x) { cout << x * x << endl; });


	return 0;
}