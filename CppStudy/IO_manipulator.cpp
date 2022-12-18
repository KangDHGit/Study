#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
	//int num = 100;
	//cout << "10진수 : " << num << endl;
	//cout << "16진수 : " << hex << num << endl;
	//cout << "8진수 : " << oct << num << endl;

	//cout << "abcdefg\n";
	//cout << 12345 << endl;
	//cout << 123.45 << endl;
	//cout << "10칸\n" << endl;
	//cout << setfill('*'); // 지속적으로 적용
	//cout << setw(10) << "abcdefg" << endl; // 연속적으로 기술 가능 1회성
	//cout << setw(10) << 12345 << endl;
	//cout << setw(10) << 123.45 << endl;

	cout << 1234567890 << 1234567890 << 1234567890 << 1234567890 << endl;
	cout << "10칸씩 오른쪽 정렬" << endl;
	cout << setw(10) << "abcdefg" << setw(10) << "abcdefg" << setw(10) << 12345 << setw(10) << 12345;
	cout << setw(10) << 123.45 << setw(10) << 123.45 << endl;

	cout << setiosflags(ios::left);
	cout << "10칸식 왼쪽 정렬" << endl;
	cout << setw(10) << "abcdefg" << setw(10) << "abcdefg" << setw(10) << 12345 << setw(10) << 12345;
	cout << setw(10) << 123.45 << setw(10) << 123.45 << endl;

	cout << setiosflags(ios::adjustfield);
	cout << "초기화" << endl;
	cout << setw(10) << "abcdefg" << setw(10) << "abcdefg" << setw(10) << 12345 << setw(10) << 12345;
	cout << setw(10) << 123.45 << setw(10) << 123.45 << endl;

	return 0;
}