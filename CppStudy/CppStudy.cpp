#include<iostream>
#include<string>
#include<iomanip>

//using ����
using namespace std; // ���ӽ����̽��� std���, �� ���� ���� 


//using ���ù�
using std::cout;	// �� ���� ���
using std::endl;
// �������� cout�� std::cout�� �����ϰڴ�

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
	cout << "���ڿ��� �Է����ּ���[�̸�] : ";
	cin >> name;
	cout << "�Է��� ���ڿ�[�̸�] : " << name << " " << endl;*/

	//// 1. ���� �Է��ϱ� [�迭]
	//char s[256]; // ũ�Ⱑ �����Ǿ�����
	//cout << "���ڿ��� �Է����ּ���[�迭] : ";
	//cin.get();
	//cin.getline(s, 20);
	//cout << "�Է��� ���ڿ�[�迭] : " << s << endl;

	/*string str;
	cout << "���ڿ��� �Է����ּ���[string] : ";
	getline(cin, str);
	cout << "�Է��� ���ڿ�[string] :	" << str << " " << str.length() << endl;*/

	/*cout << sum3(AA, 4, 6) << endl;
	cout << sum3(AA, 4, 6) / 2 << endl;
	cout << sum3(1.2, 2.3, 3.4) << endl;
	cout << AA << endl;*/
	
	/*int year;
	cout << "������ �Է��ϼ��� : ";
	cin >> year;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		cout << "�����Դϴ�." << endl;
	else
		cout << "����Դϴ�." << endl;*/

	/*char ch;
	cout << "Ű���� �Է� : ";
	cin >> ch;
	if (ch > 'a' && ch < 'z')
		cout << "�ҹ��� �Դϴ�.";
	else
		cout << "�ҹ��ڰ� �ƴմϴ�.";*/
	/*int num1, num2, num3, max, min;
	cout << "������ �ٸ����� �Է��ϰ� Enter�� �������� : ";
	cin >> num1; cin >> num2; cin >> num3;
	if (num1 > num2) { max = num1; min = num2; }
	else { max = num2; min = num1; }
	if (num3 > max) { max = num3; }
	if (num3 < min) { min = num3; }
	cout << "�ִ밪 : " << max << endl;
	cout << "�ּҰ� : " << min << endl;*/
	
	/*char op;
	int num1, num2;
	cout << "����Ϸ��� ���� �Է�";
	cin >> num1 >> op >> num2;
	switch (op)
	{
	case '+':
		cout << "���� ����� " << num1 + num2 << endl;
		break;
	case '-':
		cout << "���� ����� " << num1 - num2 << endl;
		break;
	case 'x':
		cout << "���� ����� " << num1 * num2 << endl;
		break;
	case '%':
		cout << "������ ����� " << (float)num1 / num2 << endl;
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
	//	cout << "�̸� �Է� : "; cin >> names[i];
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


