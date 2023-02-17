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
	//for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
	//	cout << *it << endl;	//포인터와 마찬가지로 역참조로 출력
	//}

	//벡터 컨테이너의 반복자의 효율적인 선언 및 초기화 문법
	//for (auto it = vec.begin(); it != vec.end(); it++) {
	//	cout << *it << endl;	//포인터와 마찬가지로 역참조로 출력
	//}

	//포인터처럼 한번에 여러번 주소이동가능
	/*auto it = vec.begin();
	it += 2;
	cout << *it << endl;*/

	//추상화 : 데이터 종류의 상관없이 사용 가능
	/*std::set<char> st{ 'A', 'B', 'D'};
	for (auto it = st.begin(); it != st.end(); it++)
		cout << *it << endl;*/

	//역반복자
	//vec.rbegin() : 마지막 요소, vec.rend() : 첫요소 앞

	//const 반복자
	//이 반복자를 통해서 값을 바꾸지 않겠다.
	//아래처럼 역참조해서 컨테이너에 데이터를 바꿀 수 없다.
	/*for (auto it = vec.cbegin(); it != vec.end(); it++)
		*it = 2;*/
}