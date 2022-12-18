#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	// 파일 출력
	ofstream hout("test.txt"); // 출력파일 스트림 객체 hout 선언
	if (!hout) {
		cout << "출력파일을 열 수 없습니다." << endl;
		return 1;
	}
	//hout << "Han\n";
	//hout << 200 << endl << hex << 100 << endl;
	hout << "Han S. H. \n";
	hout.close();

	// 파일 입력
	//fstream hin("test.txt"); // 입력파일 스트림 객체 hin 선언
	//if (!hin)
	//{
	//	cout << "입력파일을 열수 없습니다." << endl;
	//	return 1;
	//}
	//char str[50];
	//int i, j;
	////hin >> str >> i >> j; // 문자열과 정수형 데이터를 읽어드림
	////cout << str << "	" << i << "		" << j << endl;

	//hin >> str; // 공백전까지만 읽어드림
	//cout << str << endl;
	//hin.close();

	// 파일 입력 예제
	// 저장된 내용을 읽어들여 공백을 '*'로 채워 화면에 출력
	char ch;
	fstream hin("fstream.cpp");
	if (!hin)
	{
		cout << "입력파일을 열수 없습니다." << endl;
		return 1;
	}
	hin.unsetf(ios::skipws); // 공백무시 x
	while (!hin.eof()) // end of file 파일끝이 아니면
	{
		hin >> ch;
		if (ch == ' ')
			ch = '*';
		cout << ch;
	}
	hin.close();

	return 0;
}