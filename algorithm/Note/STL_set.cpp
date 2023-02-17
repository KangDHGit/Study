#include<iostream>
#include<set>
#include<list>
#include<algorithm>

using std::cout;
using std::endl;
using std::cin;

template<typename T>
void PrintContainer(T container) {
	for (auto it = container.begin(); it != container.end(); it++)
		cout << *it << " ";
	cout << endl;
}
template<typename T>
void PrintConPair(T container){
	for (auto it = container.begin(); it != container.end(); it++) {
		cout << it->first << " : " << it->second; cout << endl;
	}
}
int main()
{
	//key에 따라 자동정렬
	std::set<int> s{ 3, 1, 5, 4, 2 };
	//1, 2, 3, 4, 5
	std::for_each(s.begin(), s.end(), [](int x) { cout << x << " "; });
	cout << endl;
	s.insert(5);
	s.insert(4);
	//1, 2, 3, 4, 5 : 중복요소를 허용하지 않음
	std::for_each(s.begin(), s.end(), [](int x) { cout << x << " "; });

	std::list<int> l{ 3, 1, 5, 4, 2 };
	PrintContainer <std::list<int>>(l);
	l.push_back(5);
	l.push_back(4);
	PrintContainer <std::list<int>>(l);

	//set은 자체적으로 find함수를 가지고 있다.
	auto it = s.find(3);
	if(it != s.end())
		cout << *it << endl;
	//erase는 결과에따라 1 또는 0 반환
	bool isfind = s.count(10);
	cout << isfind << endl;
	
	//set과 pair
	std::set<std::pair<std::string, int>> s2{
		{"Kim", 18},
		{"Lee", 19},
		{"Kang", 21},
		{"Kim", 25},		//가능
		{"Kim", 18},		//불가능
	};

	PrintConPair(s2);

	return 0;
}