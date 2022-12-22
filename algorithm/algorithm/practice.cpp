#include<iostream>

using std::cout;
using std::endl;
using std::cin;

// 8¹ø
int recursive_8(int n)
{
	cout << n << endl;
	if (n < 1) return 2;
	else return (2 * recursive_8(n - 1) + 1);
}
// 9¹ø
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
	return 0;
}