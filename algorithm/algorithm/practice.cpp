#include<iostream>

using std::cout;
using std::endl;
using std::cin;

// 8번
int recursive_8(int n)
{
	cout << n << endl;
	if (n < 1) return 2;
	else return (2 * recursive_8(n - 1) + 1);
}
// 9번
int recursive_9(int n)
{
	cout << n << endl;
	if (n < 1) return -1;
	else return(recursive_9(n - 3) + 1);
}

void recursive_10(int n)
{
	if (n != 1) recursive_10(n - 1);
	cout << n << endl;
}

void asterisk_11(int i, int& count)
{
	if (i > 1)
	{
		asterisk_11(i / 2, count);
		asterisk_11(i / 2, count);
	}
	cout << "*"; count++;
}

void unknown()
{
	int ch;
	if ((ch = getchar()) != '\n')
		unknown();
	putchar(ch);
}

int sum0toN(int n)
{
	if (n == 1) return 1;
	else return n + sum0toN(n - 1);
}

double divSum(int n)
{
	if (n == 1) return 1;
	else return ((double)1 / n) + (divSum(n - 1));
}

int fib_15(int n)
{
	cout << "fib_15(" << n << ") is call" << endl;
	if (n == 1) return 1;
	if (n == 0) return 0;
	return fib_15(n - 1) + fib_15(n - 2);
}

int sum_iter(int n)
{
	int result = 0;
	for (int i = 1; i <= n; i++)
		result += i;
	return result;
}

int bc(int n, int k)
{
	if (k == 0 || k == n) return 1;
	else return (bc(n - 1, k - 1) + bc(n - 1, k));
}

int Ackermann_18_recu(int m, int n, int& count)
{
	++count;
	cout << "m : " << m << " n : " << n << endl;
	if (m == 0) return n + 1;
	else if (n == 0) return Ackermann_18_recu(m - 1, 1,count);
	else
		return Ackermann_18_recu(m - 1, Ackermann_18_recu(m, n - 1,count),count);
}

int Ackermann_18_iter(int m, int n)
{
	int list[1000];
	int esp = 0;

	list[esp] = m;	// [0 인덱스]에 m
	esp++;			// 인덱스를 뒤로 이동
	list[esp] = n;	// [1 인덱스]에 n

	while (true) {
		if (esp == 0) {							// 인덱스가 0이면 [0 인덱스 값]을 리턴
			return list[esp];
		}
		else if (list[esp - 1] == 0) {			// [전 인덱스 값]이 0일경우
			list[esp - 1] = list[esp] + 1;		// [전 인덱스 값]에 [현 인덱스 값 + 1] 입력

			esp = esp - 1;						// 인덱스를 앞으로 이동
		}
		else if (list[esp] == 0) {				// [현 인덱스 값]이 0인경우
			list[esp - 1] = list[esp - 1] - 1;	// [전 인덱스 값] -1
			list[esp] = 1;						// [현 인덱스 값] +1
		}
		else {									// [전 인덱스 값]과 [현 인덱스 값이] 0이 아닌경우 
			list[esp + 1] = list[esp] - 1;		// [다음 인덱스 값]에 [현 인덱스 값 - 1] 입력
			list[esp] = list[esp - 1];			// [현 인덱스 값]에 [전 인덱스 값] 입력
			list[esp - 1] = list[esp - 1] - 1;	// [전 인덱스 값]에 [전 인덱스 값 - 1] 입력

			esp = esp + 1;						// 인덱스를 뒤로 이동
		}
	}
}

int main()
{
	cout << "recursive_8 : " << recursive_8(5) << endl;
	cout << "recursive_9 : " << recursive_9(10) << endl;
	recursive_10(5);
	cout << "recursive_10 : " << endl;
	int asterCount = 0;
	asterisk_11(5, asterCount); cout << endl;
	cout << "asterisk(5) : " << asterCount << endl;
	//unknown();
	cout << "sum0toN(5) : " << sum0toN(5) << endl;
	cout << "divSum(5) : " << divSum(5) << endl;
	//fib_15(6);
	cout << "sum_iter(5) : " << sum_iter(5) << endl;
	cout << "bc(5,3) : " << bc(5, 3) << endl;

	int ackerCount = 0;
	cout << "Ackermaan_18(3,2) : " << Ackermann_18_recu(1, 2, ackerCount); cout << " count : " << ackerCount << endl;
	ackerCount = 0;
	cout << "Ackermaan_18(1,1) : " << Ackermann_18_iter(1, 1) << endl;
	return 0;
}