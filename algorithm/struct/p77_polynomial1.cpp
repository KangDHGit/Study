#include<iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

#define MAX(a,b) (((a) > (b))? (a) : (b))
#define MAX_DEGREE 101

double power(double x, int n);

struct polynomial {			// 다항식 구조체 타입 선언
	int degree;				// 다항식의 최고 차수
	float coef[MAX_DEGREE];	// 다항식의 각 차수별 계수 배열(인덱스0부터 최고차수)

	//다항식 덧샘 함수
	static polynomial poly_add1(polynomial A, polynomial B)
	{
		polynomial C;						// 결과를 반환할 변수
		int Apos = 0, Bpos = 0, Cpos = 0;	// A,B,C의 coef배열 인덱스 변수
		int degree_a = A.degree;			// 현재 A의 차수
		int degree_b = B.degree;			// 현재 B의 차수
		C.degree = MAX(degree_a, degree_b); // 반환할 변수의 최고 차수

		// 최고 차수부터 더해서 내려옴
		while (Apos <= A.degree && Bpos <= B.degree)
		{
			if (degree_a > degree_b) // A의 차수가 더 높을때
			{
				C.coef[Cpos] = A.coef[Apos];
				Cpos++; Apos++;
				degree_a--;
			}
			else if (degree_a == degree_b) // A B의 차수가 같을때
			{
				C.coef[Cpos] = A.coef[Apos] + B.coef[Bpos];
				Cpos++; Apos++; Bpos++;
				degree_a--; degree_b--;
			}
			else // B의 차수가 더 높을때
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
			cout << "해당 차수의 계수가 존재하지 않습니다." << endl;
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
			if (coef[i] == 0.0) // 해당 차수에 계수가 0일경우
				continue;
			total += coef[i] * power(x, degree - i);
		}
		total += coef[degree]; // 상수항 더하기

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