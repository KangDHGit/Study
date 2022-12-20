#include<iostream>

using std::cout;
using std::endl;
using std::cin;

// ¼ıÀÚ xÀÇ n°ÅµìÁ¦°ö °ª
double power_iter(double x, int n)
{
	double total = 1.0;
	for (int i = 0; i < n; i++)
		total *= x;
	return total;
}

double power_recu(double x, int n)
{
	if (n == 0) return 1;
	else if (n % 2 == 0) { 
		cout << "power(" << x * x << ", " << n/2 << ")" << endl;
		return power_recu(x * x, n / 2); }
	else if (n % 2 == 1) { 
		cout << x << "*" << "power(" << x * x << ", " << n / 2 << ")" << endl; 
		return x * power_recu(x * x, (n - 1) / 2); }
}

int main()
{
	cout << "power_iter(3,4) : " << power_iter(3, 4) << endl;
	cout << "power_recu(3,4) : " << power_recu(3, 4) << endl;
	cout << "power_recu(2,6) : " << power_recu(2, 6) << endl;
	return 0;
}