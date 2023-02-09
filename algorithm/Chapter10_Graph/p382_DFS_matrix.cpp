#include<iostream>

using std::cout;
using std::endl;
using std::cin;

class GraphType {
	const static int max_vertices = 50;
	int adj_mat[max_vertices][max_vertices];
	int n;
	bool visited[max_vertices];
	void Init();
public:
	GraphType() { Init(); }
	void VisitInit();
	void AddVertex();
	void InsertEdge(unsigned int start, unsigned int end);
	int GetEdge(int start, int end);
	int GetVertexCount() { return n; }
	bool GetVisited(int vertex);
	void SetVisited(int vertex, bool visit);
};

void GraphType::Init() {
	n = 0;
	for (int r = 0; r < max_vertices; r++)
	{
		visited[r] = false;
		for (int c = 0; c < max_vertices; c++)
		{
			adj_mat[r][c] = 0;

		}
	}
}

void GraphType::VisitInit() {
	for (int i = 0; i < max_vertices; i++)
		visited[i] = false;
}
void GraphType::AddVertex() {
	if (n + 1 > max_vertices)
		cout << "그래프의 최대 정점 개수를 초과했습니다." << endl;
	else {
		n++;
		cout << "정점을 추가했습니다. 현재 정점 개수 : " << n << endl;
	}
}

int GraphType::GetEdge(int start, int end) {
	return adj_mat[start][end];
}

void GraphType::InsertEdge(unsigned int start, unsigned int end) {
	if (start >= max_vertices || end >= max_vertices)
		cout << "입력 정점번호 오류" << endl;
	else {
		adj_mat[start][end] = 1;
		adj_mat[end][start] = 1;
	}
}

bool GraphType::GetVisited(int vertex) {
	return visited[vertex];
}

void GraphType::SetVisited(int vertex, bool visit) {
	visited[vertex] = visit;
}

void DfsMat(GraphType* graph, int vertex) {
	if (graph == nullptr) { cout << "그래프가 nullptr 입니다." << endl; return; }
	if (vertex >= graph->GetVertexCount()) { cout << "입력 정점번호 오류" << endl; return; }
	//방문표시
	graph->SetVisited(vertex, true);
	cout << "정점 " << vertex << " -> ";
	//입력받은 정점에서 다른정점 방문
	for (int other = 0; other < graph->GetVertexCount(); other++)
	{
		//인접정점이고 and 이미 방문한정점이 아닐경우
		if (graph->GetEdge(vertex, other) != 0 && !graph->GetVisited(other))
			DfsMat(graph, other);	//방문한 정점 other에서 DFS 새로 시작
	}
}

int main()
{
	GraphType graph;
	for (int i = 0; i < 4; i++)
		graph.AddVertex();

	graph.InsertEdge(0, 1);
	graph.InsertEdge(0, 2);
	graph.InsertEdge(0, 3);
	graph.InsertEdge(1, 2);
	graph.InsertEdge(2, 3);

	cout << "깊이 우선탐색 시작" << endl;
	DfsMat(&graph, 0);
	cout << endl;

	graph.VisitInit();
	cout << "깊이 우선탐색 시작" << endl;
	DfsMat(&graph, 1);
	cout << endl;

	graph.VisitInit();
	cout << "깊이 우선탐색 시작" << endl;
	DfsMat(&graph, 2);
	cout << endl;

	graph.VisitInit();
	cout << "깊이 우선탐색 시작" << endl;
	DfsMat(&graph, 3);
	cout << endl;
	return 0;
}