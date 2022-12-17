#include<iostream>

using namespace std;

void Div(double ja, double mo)
{
	try
	{
		if (!mo) throw mo; // 0이면 !false, 아니면 !true
		cout << "결과 : " << ja / mo << endl; // if에서 throw가 발생하지 않으면 정상 출력
	}
	catch (double) // mo가 double 형
	{
		cout << "오류 : 영으로 나눌 수 없음";
	}
}

int main()
{
	double x, y;
	cout << "분자를 입력하세요 : " << endl;
	cin >> x;
	cout << "분모를 입력하세요 : " << endl;
	cin >> y;
	Div(x, y);

	return 0;
}