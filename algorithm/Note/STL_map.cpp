#include<iostream>
#include<map>
#include<algorithm>

using std::cout;
using std::endl;
using std::cin;
template<typename T>
void PrintMap() {

}

int main()
{
	std::map<std::string, int> m1{
		{"Kim", 18},
		{"Lee", 19},
		{"Kang", 21},
		{"Kim", 25},	//중복불가
	};
	cout << m1["Kim"] << endl;	//18
	cout << endl;

	//key를 통한 직접접근 가능
	cout << m1["Kang"] << endl;
	m1["Kang"] = 23;
	cout << m1["Kang"] << endl;
	cout << endl;

	//새로운 데이터를 추가할때 새로운 key, value을 직접 입력해서 추가 가능
	m1["Park"] = 28;
	cout << m1["Park"] << endl;	//28
	//insert함수도 가능
	m1.insert({ "Choi", 30 });
	cout << m1["Choi"] << endl;	//30

	
	//map의 람다 사용
	//std::for_each(m1.begin(), m1.end(),[](std::pair<std::string, int> p) {cout << p.first << " : " << p.second << endl; });
	return 0;
}