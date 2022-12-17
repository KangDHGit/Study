#include<iostream>
#include<string>

// �����ε�, ����Ʈ����, const
using namespace std;
class Cat {
private:
	int age;
	string name;
public :
	Cat(int age = 1, string name = "����") : age(age), name(name) { cout << this->name << " ����� ��ü�� ����� �����\n"; }
	//Ŭ���� ������� �����ʱ�ȭ, this ������, default �Ű����� Ȱ��
	~Cat() { cout << name << " ��ü ����\n"; }
	int getAge() const { return age; } // �Լ� �̸��ڿ� const�� �Լ� �ȿ��� ������ �Ұ���
	string getName() const; // ����, ������ �ܺο�
	void setAge(int age);
	void setName(string name = "�����"); // ����Ʈ �Ű����� �����
	void meow(int count = 1);
};

string Cat::getName() const { return name; }// �ܺα���
void Cat::setAge(int age) { this->age = age; }
void Cat::setName(string name) { this->name = name; } // ����Ʈ �Ű������� ����� �Լ� �ܺα���(����Ʈ ���� ����� �ȴ�)
void Cat::meow(int count) {
	for (int i = 0; i < count; i++) cout << name << " �߿�~!\n";
}

int main()
{
	Cat nabi(1, "����"), yaong(1, "�߿�"), * pNabi;
	int num, age;

	cout << nabi.getName() << " ��� ���̴� " << nabi.getAge() << "���̴�.\n";
	cout << yaong.getName() << " ��� ���̴� " << yaong.getAge() << "���̴�.\n";
	pNabi = &nabi;
	cout << pNabi->getName() << " ��� ���̴� " << pNabi->getAge() << "���̴�\n";

	nabi.setName("Nabi");
	nabi.setAge(3);
	cout << nabi.getName() << "���̴� " << nabi.getAge() << "���̴�\n";

	yaong.meow();
	nabi.meow();
	yaong.meow();
	nabi.meow(2);

	cout << "\n �������� ������ ����� ��==";
	cin >> num;
	Cat* pCat = new Cat[num];
	if (!pCat) { cout << "�������� �޸� �Ҵ��� ���� �ʾҽ��ϴ�.\n"; exit(1); }

	for (int i = 0; i < num; i++)
	{
		cout << "pCat[" << i << "] ��ü�� ���̸� �Է��Ͻʽÿ�";
		cin >> age;
		pCat[i].setAge(age);
	}

	for (int i = 0; i < num; i++)
	{
		cout << "pCat[" << i << "] ����� ���̴� " << (pCat + i)->getAge() << "�� �Դϴ�.\n";
	}
	delete[] pCat;
}


