#include<iostream>

using namespace std;

void Div(double ja, double mo)
{
	try
	{
		if (!mo) throw mo; // 0�̸� !false, �ƴϸ� !true
		cout << "��� : " << ja / mo << endl; // if���� throw�� �߻����� ������ ���� ���
	}
	catch (double) // mo�� double ��
	{
		cout << "���� : ������ ���� �� ����";
	}
}

int main()
{
	double x, y;
	cout << "���ڸ� �Է��ϼ��� : " << endl;
	cin >> x;
	cout << "�и� �Է��ϼ��� : " << endl;
	cin >> y;
	Div(x, y);

	return 0;
}