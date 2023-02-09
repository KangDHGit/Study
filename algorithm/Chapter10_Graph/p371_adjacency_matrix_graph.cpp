#include<iostream>

using std::cout;
using std::endl;
using std::cin;

class GraphType {
	static const int max_vertices = 4;
	int n;		//������ ����
	int adj_mat[max_vertices][max_vertices];
public:
	GraphType() { Init(); }
	void Init() {
		n = 0;
		for (int r = 0; r < max_vertices; r++)
		{
			for (int c = 0; c < max_vertices; c++)
			{
				adj_mat[r][c] = 0;
			}
		}
	}

	void AddVertex() {
		if (n + 1 > max_vertices) 
			cout << "�׷����� �ִ� ���� ������ �ʰ��߽��ϴ�." << endl;
		else {
			n++;
			cout << "������ �߰��߽��ϴ�. ���� ������ ���� : " << n << endl;
		}
	}
	//������(start, end)�� ����(���� ����)
	void InsertEdge(int start, int end) {
		if (start >= n || end >= n)
			cout << "�Է� ���� ����" << endl;
		else {
			adj_mat[start][end] = 1;
			adj_mat[end][start] = 1;
		}
	}
	//������� ����Լ�
	void PrintAdjmat(){
		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < n; c++)
			{
				cout << adj_mat[r][c] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	GraphType graph;
	for (int i = 0; i < 4; i++)
	{
		graph.AddVertex();
	}
	graph.InsertEdge(0, 1);
	graph.InsertEdge(0, 2);
	graph.InsertEdge(0, 3);
	graph.InsertEdge(1, 2);
	graph.InsertEdge(2, 3);

	graph.PrintAdjmat();
	return 0;
}