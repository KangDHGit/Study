#include<iostream>

using std::cout;
using std::endl;
using std::cin;

#define SIZE 10

struct student {
	const char name[10];
	int age;
	double gpa;
};

int main()
{
	int* p = new int[SIZE];
	if (p == NULL)
	{
		cout << "메모리가 부족해서 할당할 수 없습니다." << endl;
		return 1;
	}

	for (int i = 0; i < SIZE; i++)
		p[i] = i;

	for (int i = 0; i < SIZE; i++)
	{
		cout << p[i] << ", ";
	}
	cout << endl;
	delete[] p;

	student* s = new student{ "Park", 20 };
	if(s == NULL)
	{
		cout << "메모리가 부족해서 할당할 수 없습니다." << endl;
		return 1;
	}
	cout << "name : " << s->name << " age : " << s->age << endl;

	delete s;

	return 0;
}