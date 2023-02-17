#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::cin;

class Person {
private:
	std::string name;
public:
	Person(std::string name) : name(name){}
	std::string GetName() { return name; }
};

int main()
{
	std::vector<int> vec{ 1, 2, 3, 4, 5 };

	cout << vec[0] << endl;			//1 : 배열처럼 인덱스로 접근 가능
	cout << vec.at(1) << endl;		//2
	cout << endl;
	//[]와 at의 차이
	//cout << vec[-1] << endl;		//Runtime Error : 처리할 수 없는 오류
	//cout << vec.at(-1) << endl;	//Exception		: 처리할 수 있는 오류

	//begin와 end랑 했갈릴 수 있음
	cout << vec.front() << endl;	//1
	cout << vec.back() << endl;		//5
	cout << endl;

	//push_back, pop_back, 
	//cout << vec.size() << endl;
	//cout << vec.capacity() << endl;
	//cout << vec.data() << endl;		//vector의 요소들이 들어가있는 첫주소
	//vec.push_back(10);
	//cout << vec.size() << endl;		//6 : 값이 들어가있는 개수
	//cout << vec.capacity() << endl;	//7 : 메모리가 할당돼어있는 공간의 개수
	//cout << vec.data() << endl;		//vector의 요소들이 들어가있는 첫주소
	//공간확장이 일어나면 새로운 힙공간을 만들어 복사를 하고 기존 공간은 삭제
	//cout << endl;

	//push_back, emplace_back
	//std::vector<Person> vec2;
	//새로운 객체를 생성해서 추가할시
	//vec2.push_back(Person("Lee"));		//임시객체를 생성하고 추가를한다.
	//vec2.emplace_back("Kim");			//객체 생성에 필요한 인자만 받아서 추가한다.
	//cout << vec2[0].GetName() << endl;
	//cout << vec2[1].GetName() << endl;
	//cout << endl;

	//중간에 데이터 삽입(find 함수)
	auto it = std::find(vec.begin(), vec.end(), 4);
	vec.insert(it, 7);		//반복자위치 앞에 삽입
	std::for_each(vec.begin(), vec.end(), [](int x) { cout << x << endl; });
	cout << endl;


	return 0;
}