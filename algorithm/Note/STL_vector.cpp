#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::cin;

class Person {
private:
	std::string name;
public:
	Person(std::string name) : name(name){}
	std::string GetName() { return name; }
};

int main()
{
	std::vector<int> vec{ 1, 2, 3, 4, 5 };

	cout << vec[0] << endl;			//1 : �迭ó�� �ε����� ���� ����
	cout << vec.at(1) << endl;		//2
	cout << endl;
	//[]�� at�� ����
	//cout << vec[-1] << endl;		//Runtime Error : ó���� �� ���� ����
	//cout << vec.at(-1) << endl;	//Exception		: ó���� �� �ִ� ����

	//begin�� end�� �߰��� �� ����
	cout << vec.front() << endl;	//1
	cout << vec.back() << endl;		//5
	cout << endl;

	//push_back, pop_back, 
	//cout << vec.size() << endl;
	//cout << vec.capacity() << endl;
	//cout << vec.data() << endl;		//vector�� ��ҵ��� ���ִ� ù�ּ�
	//vec.push_back(10);
	//cout << vec.size() << endl;		//6 : ���� ���ִ� ����
	//cout << vec.capacity() << endl;	//7 : �޸𸮰� �Ҵ�ž��ִ� ������ ����
	//cout << vec.data() << endl;		//vector�� ��ҵ��� ���ִ� ù�ּ�
	//����Ȯ���� �Ͼ�� ���ο� �������� ����� ���縦 �ϰ� ���� ������ ����
	//cout << endl;

	//push_back, emplace_back
	//std::vector<Person> vec2;
	//���ο� ��ü�� �����ؼ� �߰��ҽ�
	//vec2.push_back(Person("Lee"));		//�ӽð�ü�� �����ϰ� �߰����Ѵ�.
	//vec2.emplace_back("Kim");			//��ü ������ �ʿ��� ���ڸ� �޾Ƽ� �߰��Ѵ�.
	//cout << vec2[0].GetName() << endl;
	//cout << vec2[1].GetName() << endl;
	//cout << endl;

	//�߰��� ������ ����(find �Լ�)
	auto it = std::find(vec.begin(), vec.end(), 4);
	vec.insert(it, 7);		//�ݺ�����ġ �տ� ����
	std::for_each(vec.begin(), vec.end(), [](int x) { cout << x << endl; });
	cout << endl;


	return 0;
}