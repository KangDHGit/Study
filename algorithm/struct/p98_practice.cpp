#include<iostream>
#include<algorithm>

using std::cout;
using std::endl;
using std::cin;

#define MAX 10
#define ITEMS 7

int power(int x, int n)
{
	if (n == 0) return 1;

	if (n % 2 == 0) return power(x * x, n / 2);
	else return x * power(x * x, (n - 1) / 2);
}
//4��
void print_two_power()
{
	int two[10];
	for (int i = 0; i < 10; i++)
		two[i] = power(2, i);

	for (int i = 0; i < 10; i++)
		cout << two[i] << ", ";
	cout << endl;
}

//5��
struct person {
	char name[10];
	int age;
	float pay;
};

//6��
struct Complex {
	float real;
	float imag;
};

//7��
Complex complex_add(Complex a, Complex b)
{
	Complex result;
	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;
	return result;
}

//8��
void insert(int array[], int loc, int value)
{
	if (loc < 0 && loc > MAX - 1) { cout << "�߸��� �ε��� �����Դϴ�." << endl; return; }
	// �ڿ������� ��ĭ�� ����
	for (int i = ITEMS; i > loc; i--)
		array[i] = array[i - 1];
	array[loc] = value;

	for (int i = 0; i < ITEMS + 1; i++)
		cout << array[i] << ", ";

	cout << endl;
}

//10��
void delete_loc(int array[], int loc)
{
	if (loc < 0 && loc > MAX) { cout << "�߸��� �ε��� �����Դϴ�." << endl; return; }
	else if (loc == MAX) { array[loc] = NULL; return; }

	for (int i = loc; i < ITEMS - 1; i++)
		array[i] = array[i + 1];

	array[ITEMS] = NULL;

	for (int i = 0; i < ITEMS - 1; i++)
		cout << array[i] << ", ";

	cout << endl;
}

//11��
struct t_struct
{
	int num;
	char chr[20];
};

void new_delete_test()
{
	t_struct *test = new t_struct{ 100, "just testing" };
	cout << test->chr << ", " << test->num << endl;
	delete test;
}

int main()
{
	//4��
	print_two_power();

	//6��
	Complex c1 = { 3, 10 }, c2 = { 4, 13 };
	
	//7��
	Complex c3 = complex_add(c1, c2);

	//8��
	int array[MAX] = { 0,1,2,3,4,5,6 };
	insert(array, 3, 3);

	//9��
	int array2[MAX] = { 0,1,2,3,4,5,6 };
	delete_loc(array2, 3);

	//10��
	new_delete_test();
	return 0;
}