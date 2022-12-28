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
	int rows;	// ���� ����	
	int cols;	// ���� ����	
	int terms;	// ���� ����
};


SparseMatrix matrix_transpose2(SparseMatrix a)
{
	// ��ġ����� ������ ���� ���� ������ ������ �ٲ۴�
	
	SparseMatrix b;
	int b_index;
	b.rows = a.cols;
	b.cols = a.rows;
	b.terms = a.terms;
	
	if (a.terms > 0)
	{
		b_index = 0;
		for (int c = 0; c < a.cols; c++)
		{	// ����� ������ ���� �ݺ�
			for (int index = 0; index < a.terms; index++)
			{	// ���� ������ŭ �ݺ��ϸ� �׿� �ش� ���� �ִ��� Ȯ��
				if (a.data[index].col == c)
				{	// ������ ��ġ��Ŀ� ��� ��ȯ �� ���� �ְ� ��ġ��� �ε��� ����
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
				{	// a, b ���� ������ ���� �ʰ�, �Ѵ� ���� ���� �ִ°��
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