#include<iostream>
#include<array>
#include<algorithm>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	//고정크기 배열
	//기존의 정적배열과 거의 유사함

	//타입이름과 배열 사이즈를 알려줘야 함
	std::array<int, 5> arr{ 1,2,3,4,5 };

	std::array<std::string, 3> arr2{ "Kim", "Lee", "Park" };

	//알고리즘 사용이 가능
	cout << arr.size() << endl;
	//기존 배열처럼 인덱스로 접근 가능
	cout << arr[0] << endl;

	//주요함수
	cout << arr.at(0) << endl;		//배열의 0번재 인덱스 값을 반환
	cout << arr.front() << endl;	//배열의 0번째 인덱스 값을 반환
	cout << arr.back() << endl;		//배열의 마지막 인덱스 값을 반환
	return 0;
}