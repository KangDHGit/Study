#include<iostream>
#include<string>

// 오버로딩, 디폴트인자, const
using namespace std;
class Cat {
private:
	int age;
	string name;
public :
	Cat(int age = 1, string name = "냥이") : age(age), name(name) { cout << this->name << " 고양이 객체가 만들어 졌어요\n"; }
	//클래스 멤버변수 직접초기화, this 포인터, default 매개변수 활용
	~Cat() { cout << name << " 객체 바이\n"; }
	int getAge() const { return age; } // 함수 이름뒤에 const시 함수 안에서 값변경 불가능
	string getName() const; // 선언만, 구현은 외부에
	void setAge(int age);
	void setName(string name = "길냥이"); // 디폴트 매개변수 선언시
	void meow(int count = 1);
};

string Cat::getName() const { return name; }// 외부구현
void Cat::setAge(int age) { this->age = age; }
void Cat::setName(string name) { this->name = name; } // 디폴트 매개변수를 사용한 함수 외부구현(디폴트 값을 안적어도 된다)
void Cat::meow(int count) {
	for (int i = 0; i < count; i++) cout << name << " 야옹~!\n";
}

int main()
{
	Cat nabi(1, "나비"), yaong(1, "야옹"), * pNabi;
	int num, age;

	cout << nabi.getName() << " 출생 나이는 " << nabi.getAge() << "살이다.\n";
	cout << yaong.getName() << " 출생 나이는 " << yaong.getAge() << "살이다.\n";
	pNabi = &nabi;
	cout << pNabi->getName() << " 출생 나이는 " << pNabi->getAge() << "살이다\n";

	nabi.setName("Nabi");
	nabi.setAge(3);
	cout << nabi.getName() << "나이는 " << nabi.getAge() << "살이다\n";

	yaong.meow();
	nabi.meow();
	yaong.meow();
	nabi.meow(2);

	cout << "\n 동적으로 생성할 고양이 수==";
	cin >> num;
	Cat* pCat = new Cat[num];
	if (!pCat) { cout << "동적으로 메모리 할당이 되지 않았습니다.\n"; exit(1); }

	for (int i = 0; i < num; i++)
	{
		cout << "pCat[" << i << "] 객체의 나이를 입력하십시오";
		cin >> age;
		pCat[i].setAge(age);
	}

	for (int i = 0; i < num; i++)
	{
		cout << "pCat[" << i << "] 고양이 나이는 " << (pCat + i)->getAge() << "살 입니다.\n";
	}
	delete[] pCat;
}


