#include<iostream>

int main()
{
	// ������ ������ Ȱ�� x % 10�� 10���� ������ ���� ���´�
	// Ctrl + RR �̸��ٲٱ�

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

	// �ǽ� : 5678���ڿ��� �� �ڸ��� ���ڸ� ����ϼ���
	// ex) �ڸ������� �ٸ� ȿ���� �ְ������

	int num3 = 5678;
	
	int result2 = num3 % 10;
	std::cout << "result2 : " << result2 << std::endl;

	result2 = (num3 % 100) / 10;
	std::cout << "result2 : " << result2 << std::endl;

	result2 = (num3 % 1000) / 100;
	std::cout << "result2 : " << result2 << std::endl;

	result2 = (num3 / 1000);
	std::cout << "result2 : " << result2 << std::endl;

	// ������ Ǯ�� >> �����丵�� ���������� ��������
	{
		int num = 5678;

		int data = num;
		std::cout << "data : " << data % 10 << std::endl;
		// int Ư���� �̿� : �Ҽ����� ǥ�ð� �ȵ�
		data /= 10; // 567
		std::cout << "data : " << data % 10 << std::endl;
		data /= 10; //56
		std::cout << "data : " << data % 10 << std::endl;
		data /= 10; //5
		std::cout << "data : " << data % 10 << std::endl;
	}

	// ���׿�����
	//++, -- : ����������, ��ġ(��), ��ġ(��) ������
	{
		//�߿� : �ڱ� �ڽ��� ���� �ٲ��.
		int num = 0;
		std::cout << "num++ " << num++ << std::endl; //0
		std::cout << "++num " << ++num << std::endl; //2
		//���� ��� : ��ȣ���� ������ ����
		num++;
		std::cout << "num " << num << std::endl;
		--num;
		std::cout << "num " << num << std::endl;
	}
	// +=, -=, *=, /=, %=
	{
		//�߿� : �ڱ� �ڽ��� ���� �ٲ��.
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