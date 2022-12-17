#include<iostream>
#include<string>;
using namespace std;

class A {
	int a;
public:
	A() { cout << "A생성자" << endl; }
	A(int n) : a(n) { cout << "A매개변수 생성자" << endl; }
	~A() { cout << "A소멸자" << endl; }
	void showA() { cout << a << endl; }
};

class A2 {
	int a2;
public:
	A2() { cout << "A2생성자" << endl; }
	A2(int n) : a2(n) { cout << "A2매개변수 생성자" << endl; }
	~A2() { cout << "A2소멸자" << endl; }
	void showA2() { cout << a2 << endl; }
};

class B :public A, public A2 {
	int b;
public:
	B() { cout << "B생성자" << endl; }
	B(int n1, int n2, int n3) :A(n1), A2(n2), b(n3) { cout << "B매개변수 생성자" << endl; }
	// n2 는 기본클래스의 매개변수로 할당
	~B() { cout << "B소멸자" << endl; }
	void showB() { cout << b << endl; }
};

class C :public B {
	int c;
public:
	C() { cout << "C생성자" << endl; }
	C(int n1, int n2, int n3, int n4) : B(n1, n2, n3), c(n4) { cout << "C매개변수 생성자" << endl; }
	void showC() { cout << c << endl; }
	~C() { cout << "C소멸자" << endl; }
};
//-------------------------------------------------------------------------------------------
class Name {
	string name;
public:
	Name() { name = "empty"; }
	Name(string s) : name(s) {}
	void set_name(string s) { name = s; }
	void print_name() { cout << name << endl; }
};

class Phone : public Name {
	string phone;
public:
	Phone() : Name() { phone = "empty"; }
	Phone(string s) : Name(s) {}
	Phone(string _name, string _phone) : Name(_name), phone(_phone) {}
	void set_phone(string s) { phone = s; }
	void print_phone() { print_name(); cout << phone << endl; }
};
//-------------------------------------------------------------------------------------------
class Man {
	string name;
	int age;
public:
	Man() { name = "empty"; age = 0; }
	Man(const string& _name, int _age) : name(_name), age(_age){}
	void setMan(string _name, int _age) { name = _name; age = _age; }
	void printMan();
};
void Man::printMan() { cout << "이름 : " << name << endl; cout << "나이 : " << age << endl; }

class Student : protected Man {
	string classCode;
	int studentNum;
public:
	Student() : Man() { classCode = "empty"; studentNum = 0; }
	Student(const string& _name, int _age, string _classCode, int _studentNum) : Man(_name, _age), classCode(_classCode), studentNum(_studentNum) {}
	void setStudent(string _name, int _age, string _classCode, int _studentNum);
	void printStudent();
};

void Student::setStudent(string _name, int _age, string _classCode, int _studentNum)
{
	setMan(_name, _age); classCode = _classCode; studentNum = _studentNum;
}
void Student::printStudent()
{
	printMan(); cout << "반 : " << classCode << endl; cout << "학번 : " << studentNum << endl;
}

class Teacher :protected Man {
	string major;
	string department;
public:
	Teacher() : Man(), major("empty"), department("empty"){}
	Teacher(string _name, int _age, string _major, string _department) : Man(_name, _age) { major = _major; department = _department; }
	void setTeacher(string _name, int _age, string _major, string _department);
	void printTeacher();
};

void Teacher::setTeacher(string _name, int _age, string _major, string _department)
{
	setMan(_name, _age); major = _major, department = _department;
}

void Teacher::printTeacher()
{
	printMan(); cout << "전공 : " << major << endl; cout << "담당과목 : " << department << endl;
}

void printString(const string& str)
{
	cout << str << endl;
}

int main()
{
	//Phone h("Smile Han", "1234-0000");
	//h = Phone("Smile Han", "1234-5678");
	//h.print_phone();

	Student kdh("강대한", 20, "A반", 20221214);
	Teacher pjs("박정수", 40, "컴퓨터공학", "프로그래밍 기초");

	kdh.printStudent();
	pjs.printTeacher();

	printString("문자열출력");

	return 0;
}