#include<iostream>

using namespace std;

int main()
{
	cout << "����Ʈ\n";
	cout.width(10);
	cout << -50 << endl;
	cout << endl;

	cout << "[ * fill ]" << endl;
	cout.fill('*');	//����� *���� ä��
	cout.width(10);
	cout << -50 << endl;
	cout.width(10);
	cout << 100.25 << endl;
	cout.width(10);
	cout << "HanSH" << endl;
	cout << endl;

	cout.precision(6); //  �����κ��� ������ ��ü�ڸ��� ����(�����ڸ� �ݿø�)
	cout << 12.345678 << endl;
	cout.precision(3); // �Ҽ��� ������ �ڸ����� �ٷ�� ��(�����ڸ� �ݿø�)
	cout << fixed << 12.34567 << endl;

	return 0;
}