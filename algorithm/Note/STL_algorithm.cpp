#include<iostream>
#include<algorithm>
#include<vector>

using std::cout;
using std::endl;
using std::cin;

//functor
//�Լ�ó�� ����� �� �ִ� ��ü
//�Լ��� ������ �ִ� ����ü
struct Func {
	void operator()(int x) {
		cout << x * x << endl;
	}
};

void f(int x) {
	cout << x * x << endl;
}

int main()
{
	//�˰��� find
	//�ݺ��ڸ� ��ȯ
	//��ã�� ���� end()�� ��ȯ(�����Ⱚ)
	//operator == �� ���ǹǷ� Ŭ������ ��� �����ε��� �ʿ�

	std::vector<int> vec{ 1, 3, 7, 4, 8, 10 };
	const auto result = std::find(vec.begin(), vec.end(), 4);

	//���� ������ ã��
	//const auto result = std::find(vec.begin(), vec.begin() + 2, 4);
	//�̶� ã�Ҵ��� Ȯ���ҋ�
	//if(result != vec.begin() + 2)

	if(result != vec.end())
		cout << *result << endl;

	//�˰��� for_each
	//�� ��Ҹ� ���ڷ� �Լ� ȣ��
	//�Լ��� ���ڷ� �ѱ�� ���
	//functor, function pointer, lambda expression

	//functor Ȱ��
	Func f;
	f(3);
	//std::for_each(vec.begin(), vec.end(), f);

	//function pointer Ȱ��
	//�Լ��� �ּ�(�Լ��� �̸�)
	//std::for_each(vec.begin(), vec.end(), f);

	//lamda expression
	//�͸��Լ�
	//�Լ��� �̸��� �ο����� �ʰ�, �ѹ��� ����ϱ� ����
	std::for_each(vec.begin(), vec.end(), [](int x) { cout << x * x << endl; });


	return 0;
}