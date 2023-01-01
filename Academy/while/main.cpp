#include<iostream>
using namespace std;

int main()
{
	int num = 5678;
	int data = num;

#pragma region while문으로 바꾸기
	//int data = num;
	//std::cout << "data : " << data % 10 << std::endl;
	//// int 특성을 이용 : 소수점은 표시가 안됨
	//data /= 10; // 567
	//std::cout << "data : " << data % 10 << std::endl;
	//data /= 10; //56
	//std::cout << "data : " << data % 10 << std::endl;
	//data /= 10; //5
	//std::cout << "data : " << data % 10 << std::endl;
	//data /= 10;
	//std::cout << data << endl;

	//// while 문으로 바꾸기
	//while (data != 0)
	//{
	//	std::cout << "data : " << data % 10 << std::endl;
	//	data /= 10;
	//}
	//cout << endl;
#pragma endregion

	return 0;
}