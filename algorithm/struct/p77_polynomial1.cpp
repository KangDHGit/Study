#include<iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

#define MAX(a,b) (((a) > (b))? (a) : (b))
#define MAX_DEGREE 101

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
		for (int i = degree; i > 0; i--)
		{
			string oper;
			if (coef[degree - i] > 0)
				oper = " + ";
			else if (coef[degree - i] < 0)
				oper = " - ";
			else
				continue;
			cout << (int)coef[degree - i] << "^" << i << oper;
			//cout << (int)coef[degree - i] << "^" << i << "+";
		}
		if(coef[degree] != 0.0)
			cout << (int)coef[degree] << endl;
	}
};

int main()
{
	polynomial a = { 5, {3,6,0,0,0,10} }; // 3x^5 + 6x^4 + 10
	polynomial b = { 4, {-7,0,5,0,1} };
	polynomial c;

	a.print_poly();
	b.print_poly();
	c = polynomial::poly_add1(a, b);
	c.print_poly();

	return 0;
}