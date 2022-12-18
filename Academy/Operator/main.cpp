#include<iostream>

int main()
{
	// 나머지 연산의 활용 x % 10은 10보다 무조건 적게 나온다
	// Ctrl + RR 이름바꾸기

	int num1 = 11;
	int num2 = 22;

	int result = num1 + num2;
	std::cout << "result : " << result << std::endl;

	result = num1 - num2;
	std::cout << "result : " << result << std::endl;

	result = num1 * num2;
	std::cout << "result : " << result << std::endl;

	result = num1 / num2;
	std::cout << "result : " << result << std::endl;

	result = num1 % num2;
	std::cout << "result : " << result << std::endl;

	// 실습 : 5678숫자에서 각 자리수 숫자를 출력하세요
	// ex) 자리수별로 다른 효과를 주고싶을때

	int num3 = 5678;
	
	int result2 = num3 % 10;
	std::cout << "result2 : " << result2 << std::endl;

	result2 = (num3 % 100) / 10;
	std::cout << "result2 : " << result2 << std::endl;

	result2 = (num3 % 1000) / 100;
	std::cout << "result2 : " << result2 << std::endl;

	result2 = (num3 / 1000);
	std::cout << "result2 : " << result2 << std::endl;

	// 선생님 풀이 >> 리팩토링이 좋은쪽으로 생각하자
	{
		int num = 5678;

		int data = num;
		std::cout << "data : " << data % 10 << std::endl;
		// int 특성을 이용 : 소수점은 표시가 안됨
		data /= 10; // 567
		std::cout << "data : " << data % 10 << std::endl;
		data /= 10; //56
		std::cout << "data : " << data % 10 << std::endl;
		data /= 10; //5
		std::cout << "data : " << data % 10 << std::endl;
	}

	// 단항연산자
	//++, -- : 증감연산자, 전치(앞), 후치(뒤) 연산자
	{
		//중요 : 자기 자신의 값이 바뀐다.
		int num = 0;
		std::cout << "num++ " << num++ << std::endl; //0
		std::cout << "++num " << ++num << std::endl; //2
		//좋은 방법 : 모호성을 만들지 말자
		num++;
		std::cout << "num " << num << std::endl;
		--num;
		std::cout << "num " << num << std::endl;
	}
	// +=, -=, *=, /=, %=
	{
		//중요 : 자기 자신의 값이 바뀐다.
		int num = 5678;

		int data = num;
		std::cout << "data : " << data % 10 << std::endl;
		data /= 10; // data = (data / 10);
	}
	// >, <, >=, <=, ==, !=
	{
		int num = 5678;
		bool result = 5678 < 0;
		std::cout << "result : " << result << std::endl;
		result = 5678 > 0;
		std::cout << "result : " << result << std::endl;
		result = 5678 == 0;
		std::cout << "result : " << result << std::endl;
		result = 5678 != 0;
		std::cout << "result : " << result << std::endl;
	}
	return 0;
}