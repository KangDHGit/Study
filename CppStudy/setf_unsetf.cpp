#include<iostream>

using namespace std;

int main()
{
	cout << "디폴트" << endl;
	cout << 100 << ':' << -50 << endl; // 100:-50;
	cout << 0.5 << ':' << 100.123 << endl; // 0.5:100.123
	cout << endl;

	cout.unsetf(ios::dec); // 10진수 해제
	cout.setf(ios::hex | ios::showbase | ios::uppercase); // 16진수 | 0x추가 표시 | 대문자표시 0x->0X
	cout << "hex, showbase, upperbase\n";
	cout << 100 << ':' << -50 << endl; // 0X64 : 0XFFFFFFCE
	cout << endl;

	cout.setf(ios::scientific); // 과학적 표기
	cout << "scientfic\n";
	cout << 0.5 << ':' << 100.123 << endl; // 5.000000E-01 : 1.00123E+02
	cout << endl;

	cout.unsetf(ios::hex | ios::scientific);
	cout << "hex, scientfic unsetting" << endl;
	cout << 100 << ':' << -50 << endl;
	cout << 0.5 << ':' << 100.123 << endl;

	return 0;
}