#include<iostream>

using std::cout;
using std::endl;
using std::cin;

#define ROWS 3
#define COLS 3

// 행렬 전치 함수
void matrix_transpose(int A[ROWS][COLS], int B[ROWS][COLS])
{
	for (int r = 0; r < ROWS; r++)
		for (int c = 0; c < COLS; c++)
			B[r][c] = A[c][r];
}

void matrix_print(int A[ROWS][COLS])
{
	cout << "=========================" << endl;
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
			cout << A[r][c] << ", ";
		cout << endl;
	}
	cout << "=========================" << endl;		
}

void matrix_print(int *A)
{
	cout << "=========================" << endl;
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
			cout << *(A + (r * ROWS) + c) << ", ";
		cout << endl;
	}
	cout << "=========================" << endl;
}

void add_matrix(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS])
{
	for (int r = 0; r < ROWS; r++)
		for (int c = 0; c < COLS; c++)
			C[r][c] = A[r][c] + B[r][c];

}

int main()
{
	int array1[ROWS][COLS] = {	{2,3,0},
								{8,9,1},
								{7,0,5} };
	int array2[ROWS][COLS];
	matrix_transpose(array1, array2);
	matrix_print(array1);
	matrix_print(array2);

	int array3[ROWS][COLS];
	add_matrix(array1, array2, array3);
	matrix_print((int*)array3);
	return 0;
}