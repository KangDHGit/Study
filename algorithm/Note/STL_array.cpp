#include<iostream>
#include<array>
#include<algorithm>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	//����ũ�� �迭
	//������ �����迭�� ���� ������

	//Ÿ���̸��� �迭 ����� �˷���� ��
	std::array<int, 5> arr{ 1,2,3,4,5 };

	std::array<std::string, 3> arr2{ "Kim", "Lee", "Park" };

	//�˰��� ����� ����
	cout << arr.size() << endl;
	//���� �迭ó�� �ε����� ���� ����
	cout << arr[0] << endl;

	//�ֿ��Լ�
	cout << arr.at(0) << endl;		//�迭�� 0���� �ε��� ���� ��ȯ
	cout << arr.front() << endl;	//�迭�� 0��° �ε��� ���� ��ȯ
	cout << arr.back() << endl;		//�迭�� ������ �ε��� ���� ��ȯ
	return 0;
}