#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>

using std::cin;
using std::cout;
using std::endl;;
using std::string;

int main() {
	std::vector<int> vec{ 1, 2, 3 };

	//반복자의 기본 선언
	//std::vector<int>::iterator it;
	
	

	//for문과 반복자
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it << endl;	//포인터와 마찬가지로 역참조로 출력
	}

	//벡터 컨테이너의 반복자의 효율적인 선언 및 초기화 문법
	//for (auto it = vec.begin(); it != vec.end(); it++) {
	//	cout << *it << endl;	//포인터와 마찬가지로 역참조로 출력
	//}
}