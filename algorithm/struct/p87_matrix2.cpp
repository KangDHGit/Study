#include<iostream>

using std::cout;
using std::endl;
using std::cin;

#define MAX_TERMS 100

struct element {
	int row;
	int col;
	int value;
};

struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;	// 행의 개수	
	int cols;	// 열의 개수	
	int terms;	// 항의 개수
};


SparseMatrix matrix_transpose2(SparseMatrix a)
{
	// 전치행렬의 정렬을 위해 낮은 열부터 행으로 바꾼다
	
	SparseMatrix b;
	int b_index;
	b.rows = a.cols;
	b.cols = a.rows;
	b.terms = a.terms;
	
	if (a.terms > 0)
	{
		b_index = 0;
		for (int c = 0; c < a.cols; c++)
		{	// 행렬의 열개수 까지 반복
			for (int index = 0; index < a.terms; index++)
			{	// 항의 개수만큼 반복하며 항에 해당 열이 있는지 확인
				if (a.data[index].col == c)
				{	// 있으면 전치행렬에 행렬 교환 후 값을 넣고 전치행렬 인덱스 증가
					b.data[b_index].row = c;
					b.data[b_index].col = a.data[index].row;
					b.data[b_index].value = a.data[index].value;
					b_index++;
				}
			}
		}
	}
	return b;
}

SparseMatrix add_matrix(SparseMatrix a, SparseMatrix b)
{
	SparseMatrix mat;
	int mat_index;
	int bigger_terms = (a.terms > b.terms) ? a.terms : b.terms;
	mat.rows = (a.rows > b.rows) ? a.rows : b.rows;
	mat.cols = (a.cols > b.cols) ? a.cols : b.cols;
	

	if (a.terms > 0 && b.terms > 0)
	{
		mat_index = 0;
		for (int r = 0; r < mat.rows; r++)
		{
			for (int index = 0; index < bigger_terms; index++)
			{
				if (index > a.terms && index > b.terms)
				{	// a, b 항의 개수를 넘지 않고, 둘다 열에 값이 있는경우
					if ((a.data[index].row == r) && (b.data[index].row == r))
					{
						for (int c = 0; c < mat.rows; c++)
						{
						}
					}
				}
			}
		}
	}
	return mat;
}

void matrix_print(SparseMatrix a)
{
	cout << "=========================" << endl;
	for (int r = 0; r < a.rows; r++)
	{
		for (int i = 0; i < a.terms; i++)
		{
			if(a.data[i].row == r)
				cout << "(" << a.data[i].row << ", " << a.data[i].col << "," << a.data[i].value << "), ";
		}
		cout << endl;
	}
	cout << "=========================" << endl;
	/*cout << "=========================" << endl;

	for (int i = 0; i < a.terms; i++)
	{
		cout << "(" << a.data[i].row << ", " << a.data[i].col << "," << a.data[i].value << ")\n";
	}
	cout << "=========================" << endl;*/
}

int main()
{
	SparseMatrix m = {
		{{0,3,7}, {1,0,9}, {1,5,8}, {3,0,6}, {3,1,5},{4,5,1},{5,2,2}},
		6,
		6,
		7,
	};
	SparseMatrix result;
	result = matrix_transpose2(m);
	matrix_print(m);
	matrix_print(result);
	return 0;
}