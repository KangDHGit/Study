#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*
* 오버라이드(재정의)
* 반복문
*/

class Unit {
protected:
	int speed;
public:
	Unit(int _speed) : speed(_speed) {
	}
	virtual void Move() {
		cout << "Unit Move(speed : " << speed << ")" << endl;
	}
	virtual void Attack() {
		cout << "Unit Attack" << endl;
	}
	//void virtual Patrol() = 0;	//순수 가상함수, 순수가상함수를 가지는 클래스는 객체를 만들 수 없다.
};

class Marin : public Unit {
public:
	Marin(int _speed) : Unit(_speed) {
		cout << "마린 생성" << endl;
	}
	virtual void Move() {
		cout << "Marin Move(speed : " << speed << ")" << endl;
	}
	void Attack() override {	//최근 추세
		cout << "Marin Attack" << endl;
	}
};

class Tank : public Unit {
public:
	Tank(int _speed) : Unit(_speed) {
		cout << "탱크 생성" << endl;
	}
	virtual void Move() {
		cout << "Tank Move(speed : " << speed << ")" << endl;
	}
	virtual void Attack() {
		cout << "Tank Attack" << endl;
	}
	void Bomb() {
		cout << "Tank Bomb" << endl;
	}
};

void MoveAll(Unit* ptrUnit[]) {
	
}

void Move(Unit ptrUnit) {
	ptrUnit.Move();
}

void Attack(Unit* ptrUnit) {
	ptrUnit->Attack();
	if (dynamic_cast<Tank*>(ptrUnit) != nullptr)	//형변환
	{
		Tank* tankPtr = dynamic_cast<Tank*>(ptrUnit);
		tankPtr->Bomb();
	}
}

int main()
{
	Unit* units[5];
	units[0] = new Marin(100);
	units[1] = new Marin(50);
	units[2] = new Tank(120);
	units[3] = new Marin(80);
	units[4] = new Tank(90);

	for (Unit* unit : units) {
		unit->Move();
	}
	cout << endl;
	for (Unit* unit : units) {
		Attack(unit);
	}

	return 0;
}