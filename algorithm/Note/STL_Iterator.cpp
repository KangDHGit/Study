#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>

using std::cin;
using std::cout;
using std::endl;;
using std::string;

int main() {
	std::vector<int> vec{ 1, 2, 3 };

	//�ݺ����� �⺻ ����
	//std::vector<int>::iterator it;
	
	

	//for���� �ݺ���
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it << endl;	//�����Ϳ� ���������� �������� ���
	}

	//���� �����̳��� �ݺ����� ȿ������ ���� �� �ʱ�ȭ ����
	//for (auto it = vec.begin(); it != vec.end(); it++) {
	//	cout << *it << endl;	//�����Ϳ� ���������� �������� ���
	//}
}