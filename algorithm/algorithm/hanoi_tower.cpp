#include<iostream>

using std::cout;
using std::endl;
using std::cin;

void hanoi_tower(int n, char from, char tmp, char to)
{
	if (n == 1) cout << n << "�� ������ " << from << "���� " << to << "�� �̵�" << endl;
	else
	{
		hanoi_tower(n - 1, from, to, tmp);
		cout << n << "�� ������ " << from << "���� " << to << "�� �̵�" << endl;
		hanoi_tower(n - 1, tmp, from, to);
	}
}

int main()
{
	hanoi_tower(4, 'A', 'B', 'C');
	return 0;
}