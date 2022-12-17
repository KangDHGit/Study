#include<iostream>

using namespace std;

class A {
	int x;
public:
	void setX(int i) { x = i; }
	friend int Double(A a); // 함수 Double은 클래스 A의 friend함수
};

int Double(A a) { return a.x * 2; } // 외부함수지만 friend함수로 지정했기 때문에 A.x에 접근 가능

// friend 예제
class Cat; // 전방 참조
class Dog {
	int age;
public:
	Dog(int a) :age(a) { cout << "멍멍\n"; }
	int getAge();
	friend const char* Com(Dog d, Cat c);
};

class Cat {
	int age;
public:
	Cat(int a) :age(a) { cout << "야옹\n"; }
	int getAge();
	friend const char* Com(Dog d, Cat c);
};

int Dog::getAge() { return age; }
int Cat::getAge() { return age; }

const char* Com(Dog d, Cat c) // 클래스 Dog와 Cat의 private 멤버
{
	return ((d.age == c.age) ? "동갑" : "동갑이 아님");
}

int main()
{
	A aa;
	aa.setX(3);
	cout << Double(aa);  // Double은 일반함수, Double(aa)

	Dog happy(5);
	Cat nabi(3);
	cout << Com(happy, nabi);
	return 0;
}