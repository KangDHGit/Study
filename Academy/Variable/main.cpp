#include<iostream>

void main()
{
	//ctrl + shift + 좌우 (문단단위 선택)
	//ctrl + L (줄 지우기)
	int num; num = 100;
	std::cout << "num : " << num << std::endl;
	num = 200;
	std::cout << "num: " << num << std::endl;
	{
		int number = 10000;
		std::cout << "number : " << number << std::endl;
	}
}