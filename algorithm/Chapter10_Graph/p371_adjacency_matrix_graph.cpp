#include<iostream>

using std::cout;
using std::endl;
using std::cin;

class GraphType {
	static const int max_vertices = 4;
	int n;		//정점의 개수
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
			cout << "그래프의 최대 정점 개수를 초과했습니다." << endl;
		else {
			n++;
			cout << "정점을 추가했습니다. 현재 정점의 개수 : " << n << endl;
		}
	}
	//정점쌍(start, end)를 연결(간선 삽입)
	void InsertEdge(int start, int end) {
		if (start >= n || end >= n)
			cout << "입력 정점 오류" << endl;
		else {
			adj_mat[start][end] = 1;
			adj_mat[end][start] = 1;
		}
	}
	//인접행렬 출력함수
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