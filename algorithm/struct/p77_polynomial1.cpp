#include<iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

#define MAX(a,b) (((a) > (b))? (a) : (b))
#define MAX_DEGREE 101

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