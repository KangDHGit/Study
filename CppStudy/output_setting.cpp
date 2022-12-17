#include<iostream>

using namespace std;

int main()
{
	cout << "디폴트\n";
	cout.width(10);
	cout << -50 << endl;
	cout << endl;

	cout << "[ * fill ]" << endl;
	cout.fill('*');	//빈공간 *으로 채움
	cout.width(10);
	cout << -50 << endl;
	cout.width(10);
	cout << 100.25 << endl;
	cout.width(10);
	cout << "HanSH" << endl;
	cout << endl;

	cout.precision(6); //  정수부분을 포함한 전체자리수 지정(다음자리 반올림)
	cout << 12.345678 << endl;
	cout.precision(3); // 소수점 이하의 자리수만 다루게 함(다음자리 반올림)
	cout << fixed << 12.34567 << endl;

	return 0;
}