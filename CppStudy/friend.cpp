#include<iostream>

using namespace std;

class A {
	int x;
public:
	void setX(int i) { x = i; }
	friend int Double(A a); // �Լ� Double�� Ŭ���� A�� friend�Լ�
};

int Double(A a) { return a.x * 2; } // �ܺ��Լ����� friend�Լ��� �����߱� ������ A.x�� ���� ����

// friend ����
class Cat; // ���� ����
class Dog {
	int age;
public:
	Dog(int a) :age(a) { cout << "�۸�\n"; }
	int getAge();
	friend const char* Com(Dog d, Cat c);
};

class Cat {
	int age;
public:
	Cat(int a) :age(a) { cout << "�߿�\n"; }
	int getAge();
	friend const char* Com(Dog d, Cat c);
};

int Dog::getAge() { return age; }
int Cat::getAge() { return age; }

const char* Com(Dog d, Cat c) // Ŭ���� Dog�� Cat�� private ���
{
	return ((d.age == c.age) ? "����" : "������ �ƴ�");
}

int main()
{
	A aa;
	aa.setX(3);
	cout << Double(aa);  // Double�� �Ϲ��Լ�, Double(aa)

	Dog happy(5);
	Cat nabi(3);
	cout << Com(happy, nabi);
	return 0;
}