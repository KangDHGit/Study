#include<iostream>

using std::cout;
using std::endl;
using std::cin;

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

class element {
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STRING];

public:
	element() : student_no(0), name("empty"), address("empty") {};
	element(int student_no, const char* name, const char* address);
	void print();
};

#pragma region element define
element::element(int student_no, const char* name, const char* address)
{
	this->student_no = student_no;
	strcpy(this->name, name);
	strcpy(this->address, address);
}
void element::print()
{
	cout << "====================" << endl;
	cout << "Student_No : " << student_no << endl;
	cout << "Name : " << name << endl;
	cout << "Address : " << address << endl;
}
#pragma endregion


int main()
{
	element student{ 1,"°­´ëÇÑ", "±èÆ÷" };
	student.print();
	
	return 0;
}