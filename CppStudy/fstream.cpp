#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	// ���� ���
	ofstream hout("test.txt"); // ������� ��Ʈ�� ��ü hout ����
	if (!hout) {
		cout << "��������� �� �� �����ϴ�." << endl;
		return 1;
	}
	//hout << "Han\n";
	//hout << 200 << endl << hex << 100 << endl;
	hout << "Han S. H. \n";
	hout.close();

	// ���� �Է�
	//fstream hin("test.txt"); // �Է����� ��Ʈ�� ��ü hin ����
	//if (!hin)
	//{
	//	cout << "�Է������� ���� �����ϴ�." << endl;
	//	return 1;
	//}
	//char str[50];
	//int i, j;
	////hin >> str >> i >> j; // ���ڿ��� ������ �����͸� �о�帲
	////cout << str << "	" << i << "		" << j << endl;

	//hin >> str; // ������������ �о�帲
	//cout << str << endl;
	//hin.close();

	// ���� �Է� ����
	// ����� ������ �о�鿩 ������ '*'�� ä�� ȭ�鿡 ���
	char ch;
	fstream hin("fstream.cpp");
	if (!hin)
	{
		cout << "�Է������� ���� �����ϴ�." << endl;
		return 1;
	}
	hin.unsetf(ios::skipws); // ���鹫�� x
	while (!hin.eof()) // end of file ���ϳ��� �ƴϸ�
	{
		hin >> ch;
		if (ch == ' ')
			ch = '*';
		cout << ch;
	}
	hin.close();

	return 0;
}