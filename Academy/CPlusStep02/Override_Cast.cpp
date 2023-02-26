#include<iostream>

using std::cout;
using std::endl;
using std::cin;

/*
* �������̵�(������)
* �ݺ���
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
	//void virtual Patrol() = 0;	//���� �����Լ�, ���������Լ��� ������ Ŭ������ ��ü�� ���� �� ����.
};

class Marin : public Unit {
public:
	Marin(int _speed) : Unit(_speed) {
		cout << "���� ����" << endl;
	}
	virtual void Move() {
		cout << "Marin Move(speed : " << speed << ")" << endl;
	}
	void Attack() override {	//�ֱ� �߼�
		cout << "Marin Attack" << endl;
	}
};

class Tank : public Unit {
public:
	Tank(int _speed) : Unit(_speed) {
		cout << "��ũ ����" << endl;
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
	if (dynamic_cast<Tank*>(ptrUnit) != nullptr)	//����ȯ
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