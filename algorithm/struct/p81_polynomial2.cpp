#include<iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

#define MAX_TERMS 101

struct polynomial
{
	float coef; // ���	
	int expon;	// ����
};

polynomial terms[MAX_TERMS] = { {8,3}, {7,1}, {3,0},{10,3},{3,2},{1,0} };
int avail = 6; // ����ִ� �ε���

// �ΰ��� ������ �� �� �ε�ȣ ����
char compare(int a, int b)
{
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

// ���ο� ���� ���׽Ŀ� �߰�
void attach(float coef, int expon)
{
	if (avail > MAX_TERMS)
		cout << "���� ������ �ʹ� ����" << endl;
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}

// As : A�� ���� �ε���, Ae : A�� �� �ε���
static void poly_add(int As, int Ae, int Bs, int Be, int* Cs, int* Ce)
{
	int Apos = As;
	int Bpos = Bs;
	*Cs = avail;

	while (Apos <= Ae && Bpos <= Be)
	{
		switch (compare(terms[Apos].expon, terms[Bpos].expon))
		{
		case'>':	// A�� ���� > B�� ����
			attach(terms[Apos].coef, terms[Apos].expon);
			Apos++;	break;
		case '<':	// A�� ���� < B�� ����
			attach(terms[Bpos].coef, terms[Bpos].expon);
			Bpos++;	break;
		case '=':	// A�� ���� == B�� ����
			float c_coef = terms[Apos].coef + terms[Bpos].coef;
			if(c_coef != 0.0)
				attach(c_coef, terms[Apos].expon);
			Apos++; Bpos++; break;
		}
	}
	// ������ ���� ���� ����������� ������ �� ����
	for (; Apos <= Ae; Apos++)
		attach(terms[Apos].coef, terms[Apos].expon);
	for (; Bpos <= Be; Bpos++)
		attach(terms[Bpos].coef, terms[Bpos].expon);
	*Ce = avail - 1;
}

void print_poly(int s, int e)
{
	string oper = " + ";
	cout << (int)terms[s].coef << "^" << terms[s].expon;
	for (int i = s + 1; i < e; i++)
	{
		if (terms[i].coef > 0.0)
		{
			oper = " + ";
			cout << oper << (int)terms[i].coef << "^" << terms[i].expon;
		}
		else if (terms[i].coef < 0.0)
		{
			oper = " ";
			cout << (int)terms[i].coef << "^" << terms[i].expon;
		}
		else
			continue;
	}

	if (terms[e].coef != 0.0)
	{
		if (terms[e].coef > 0.0)
		{
			oper = " + ";
			cout << oper << (int)terms[e].coef << endl;
		}
		else
		{
			oper = " ";
			cout << oper << (int)terms[e].coef << endl;
		}
	}
}

polynomial poly_read(int index)
{
	if (terms[index].coef != NULL)
	{
		return polynomial{ terms[index].coef, terms[index].expon };
	}
	else
		cout << "�ش� �ε����� ���� �������� �ʽ��ϴ�." << endl;
}

double power(int x, int n)
{
	if (x == 0) return 0;
	else if (x == 1)return 1;

	if (n == 0) return 1;
	else if (n % 2 == 0)
		return power((x * x), n / 2);
	else
		return x * power((x * x), (n - 1) / 2);
}

double poly_eval(int x, int s, int e)
{
	double total = 0;
	for (; s <= e; s++)
	{
		total += terms[s].coef * power(x, terms[s].expon);
	}
	return total;
}
int main()
{
	int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
	poly_add(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As, Ae);
	print_poly(Bs, Be);
	print_poly(Cs, Ce);

	cout << poly_eval(2, 0, 2) << endl;
	cout << poly_eval(4, 0, 2) << endl;
	return 0;
}