#include<iostream>
#include<string>
#include<iomanip>

//using 선언문
using namespace std; // 네임스페이스로 std사용, 잘 쓰지 않음 


//using 지시문
using std::cout;	// 더 좋은 방법
using std::endl;
// 이제부터 cout은 std::cout을 참조하겠다

#define AA 2
#define sum3(i,j,k) ((i)+(j)+(k))

namespace Sample
{
	int N = 5;
}

void Print_Double_Number(int x);
void Sub();

class Dog {
private:
	int age;
public:
	/*Dog(int a = 1);*/
	/*Dog() :age(1) {}
	Dog(int a) : age(a) {}*/
	Dog(int a = 1) { age = a; }

	int getAge();
	void setAge(int num);
};
int Dog::getAge() { return age; }
void Dog::setAge(int num) { age = num; }

class Person {
private:
	string name;
	int age;
	float weight;
public:
	void setName(string str) { name = str; }
	void setName(string& str) { name = str; }
	void setAge(int num) { age = num; }
	void setAge(int& num) { age = num; }
	void setWeight(float num) { weight = num; }
	void setWeight(float& num) { weight = num; }

	const string getName();
	const int getAge();
	const float getWeight();
};

const string Person::getName() { return name; }
const int Person::getAge() { return age; }
const float Person::getWeight() { return weight; }

int add(int i = 0, int j = 1);

int main()
{
	/*char name[256];
	cout << "문자열을 입력해주세요[이름] : ";
	cin >> name;
	cout << "입력한 문자열[이름] : " << name << " " << endl;*/

	//// 1. 한줄 입력하기 [배열]
	//char s[256]; // 크기가 고정되어있음
	//cout << "문자열을 입력해주세요[배열] : ";
	//cin.get();
	//cin.getline(s, 20);
	//cout << "입력한 문자열[배열] : " << s << endl;

	/*string str;
	cout << "문자열을 입력해주세요[string] : ";
	getline(cin, str);
	cout << "입력한 문자열[string] :	" << str << " " << str.length() << endl;*/

	/*cout << sum3(AA, 4, 6) << endl;
	cout << sum3(AA, 4, 6) / 2 << endl;
	cout << sum3(1.2, 2.3, 3.4) << endl;
	cout << AA << endl;*/
	
	/*int year;
	cout << "연도를 입력하세요 : ";
	cin >> year;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		cout << "윤년입니다." << endl;
	else
		cout << "평년입니다." << endl;*/

	/*char ch;
	cout << "키보드 입력 : ";
	cin >> ch;
	if (ch > 'a' && ch < 'z')
		cout << "소문자 입니다.";
	else
		cout << "소문자가 아닙니다.";*/
	/*int num1, num2, num3, max, min;
	cout << "세개의 다른수를 입력하고 Enter을 누르세요 : ";
	cin >> num1; cin >> num2; cin >> num3;
	if (num1 > num2) { max = num1; min = num2; }
	else { max = num2; min = num1; }
	if (num3 > max) { max = num3; }
	if (num3 < min) { min = num3; }
	cout << "최대값 : " << max << endl;
	cout << "최소값 : " << min << endl;*/
	
	/*char op;
	int num1, num2;
	cout << "계산하려는 수식 입력";
	cin >> num1 >> op >> num2;
	switch (op)
	{
	case '+':
		cout << "덧셈 결과는 " << num1 + num2 << endl;
		break;
	case '-':
		cout << "뺄셈 결과는 " << num1 - num2 << endl;
		break;
	case 'x':
		cout << "곱셈 결과는 " << num1 * num2 << endl;
		break;
	case '%':
		cout << "나눗셈 결과는 " << (float)num1 / num2 << endl;
	default:
		break;
	}*/
	
	///*Dog happy;
	//happy.setAge(3);
	//cout << happy.getAge() << endl;*/
	//Person kim;
	//kim.setName("Kim ChulSu");
	//kim.setAge(8);
	//kim.setWeight(30.3f);
	///*cout << kim.getName() << endl;
	//cout << kim.getAge() << " " << kim.getWeight() << endl;*/
	///*char names[3][7];
	//for (int i = 0; i < sizeof(names) / sizeof(names[1]); i++)
	//{
	//	cout << "이름 입력 : "; cin >> names[i];
	//}
	//return 0;*/
	//int num = strcmp(kim.getName().c_str(), kim.getName().c_str());
	//cout << num << endl;
	cout << add() << endl;
	cout << add(1) << endl;
	cout << add(1, 3) << endl;

	Dog dog, dog2(4);
}

int add(int i, int j)
{
	return i + j;
}
void Print_Double_Number(int x)
{
	cout << x * 2 << endl;
}

void Sub()
{
	int x = 10;
	static int y = 10;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	x++; y++;
}


