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
		{"Kim", 25},	//�ߺ��Ұ�
	};
	cout << m1["Kim"] << endl;	//18
	cout << endl;

	//key�� ���� �������� ����
	cout << m1["Kang"] << endl;
	m1["Kang"] = 23;
	cout << m1["Kang"] << endl;
	cout << endl;

	//���ο� �����͸� �߰��Ҷ� ���ο� key, value�� ���� �Է��ؼ� �߰� ����
	m1["Park"] = 28;
	cout << m1["Park"] << endl;	//28
	//insert�Լ��� ����
	m1.insert({ "Choi", 30 });
	cout << m1["Choi"] << endl;	//30

	
	//map�� ���� ���
	//std::for_each(m1.begin(), m1.end(),[](std::pair<std::string, int> p) {cout << p.first << " : " << p.second << endl; });
	return 0;
}