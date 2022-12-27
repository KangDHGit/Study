#include<iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

#define MAX(a,b) (((a) > (b))? (a) : (b))
#define MAX_DEGREE 101

double power(double x, int n);

struct polynomial {			// ���׽� ����ü Ÿ�� ����
	int degree;				// ���׽��� �ְ� ����
	float coef[MAX_DEGREE];	// ���׽��� �� ������ ��� �迭(�ε���0���� �ְ�����)

	//���׽� ���� �Լ�
	static polynomial poly_add1(polynomial A, polynomial B)
	{
		polynomial C;						// ����� ��ȯ�� ����
		int Apos = 0, Bpos = 0, Cpos = 0;	// A,B,C�� coef�迭 �ε��� ����
		int degree_a = A.degree;			// ���� A�� ����
		int degree_b = B.degree;			// ���� B�� ����
		C.degree = MAX(degree_a, degree_b); // ��ȯ�� ������ �ְ� ����

		// �ְ� �������� ���ؼ� ������
		while (Apos <= A.degree && Bpos <= B.degree)
		{
			if (degree_a > degree_b) // A�� ������ �� ������
			{
				C.coef[Cpos] = A.coef[Apos];
				Cpos++; Apos++;
				degree_a--;
			}
			else if (degree_a == degree_b) // A B�� ������ ������
			{
				C.coef[Cpos] = A.coef[Apos] + B.coef[Bpos];
				Cpos++; Apos++; Bpos++;
				degree_a--; degree_b--;
			}
			else // B�� ������ �� ������
			{
				C.coef[Cpos] = B.coef[Bpos];
				Cpos++; Bpos++;
				degree_b--;
			}
		}
		return C;
	}
	void print_poly()
	{
		string oper;
		cout << (int)coef[0] << "^" << degree;
		for (int i = degree - 1; i > 0; i--)
		{
			if (coef[degree - i] > 0)
				oper = " + ";
			else if (coef[degree - i] < 0)
				oper = " ";
			else
				continue;
			cout << oper << (int)coef[degree - i] << "^" << i;
			//cout << (int)coef[degree - i] << "^" << i << "+";
		}
		if (coef[degree] != 0.0)
		{
			if(coef[degree] > 0.0)
				cout << " + " <<  (int)coef[degree] << endl;
			else
				cout << (int)coef[degree] << endl;
		}
	}

	int poly_read(int degree)
	{
		if (degree > this->degree || coef[this->degree - degree] == 0.0)
		{
			cout << "�ش� ������ ����� �������� �ʽ��ϴ�." << endl;
			return 0;
		}
		else
			return (int)coef[degree];
	}

	double poly_eval(int x)
	{
		double total = 0;
		for (int i = 0; i < degree; i++)
		{
			if (coef[i] == 0.0) // �ش� ������ ����� 0�ϰ��
				continue;
			total += coef[i] * power(x, degree - i);
		}
		total += coef[degree]; // ����� ���ϱ�

		return total;
	}
};

double power(double x, int n)
{
	if (x == 1) return 1;
	else if (x == 0) return 0;

	if (n == 0)
		return 1;
	else if ((n % 2) == 0)
		return power(x * x, n / 2);
	else
		return x * power(x * x, (n -1)/ 2);
}

int main()
{
	polynomial a = { 5, {3,6,0,0,0,10} }; // 3x^5 + 6x^4 + 10
	polynomial b = { 4, {-7,0,5,0,1} };
	polynomial c;

	a.print_poly();
	b.print_poly();
	c = polynomial::poly_add1(a, b);
	c.print_poly();

	int degree = a.poly_read(3);

	
	polynomial d = { 3, {2, 3, 0, 10} };
	cout << d.poly_eval(4) << endl;


	return 0;
}