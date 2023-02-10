#include<iostream>

using std::cout;
using std::endl;
using std::cin;

typedef int vertex;

class GraphType {
	const static int max_vertices = 10;
	int n;
	int adj_mat[max_vertices][max_vertices];
	bool visited[max_vertices];
	void Init();
public:
	GraphType() { Init(); }
	void AddVertex();
	int GetSize() { return n; }
	void InsertEdge(vertex start, vertex end);
	int GetEdge(vertex start, vertex end);
	void SetVisited(vertex v, bool visit);
	bool GetVisited(vertex v);
	void PrintMat();
};

void GraphType::Init() {
	n = 0;
	for (vertex r = 0; r < max_vertices; r++)
	{
		visited[r] = 0;
		for (vertex c = 0; c < max_vertices; c++)
			adj_mat[r][c] = 0;
	}
}
void GraphType::AddVertex() {
	if (n + 1 > max_vertices) { cout << "그래프의 최대 정점 개수를 초과했습니다." << endl; }
	else {
		n++;
		cout << "정점을 추가 했습니다. 현재 정점 개수 : " << n << endl;
	}
}
void GraphType::SetVisited(vertex v, bool visit) {
	visited[v] = visit;
}
bool GraphType::GetVisited(vertex v) {
	return visited[v];
}
void GraphType::InsertEdge(vertex start, vertex end) {
	if (start >= n || end >= n || start < 0 || end < 0)
		cout << "입력 정점번호 오류" << endl;
	else {
		adj_mat[start][end] = 1;
		adj_mat[end][start] = 1;
	}
}
int GraphType::GetEdge(vertex start, vertex end) {
	if (start >= n || end >= n || start < 0 || end < 0) {
		cout << "입력 정점번호 오류" << endl; return 0;
	}
	else
		return adj_mat[start][end];
}
void GraphType::PrintMat() {
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
			cout << adj_mat[r][c] << " ";
		cout << endl;
	}
}

//방문하지 않은 정점을 담을 스택
class StackType {
	const static int max_size = 10;
	vertex data[max_size];
	int top;
	void Init() { top = -1; }
public:
	StackType() { Init(); }
	bool IsFull() { return top == max_size; }
	bool IsEmpty() { return top == -1; }
	void Push(vertex v);
	vertex Pop();
};
void StackType::Push(vertex v) {
	if (IsFull()) { cout << "스택 포화 에러" << endl; }
	else {
		top++;
		data[top] = v;
	}
}
vertex StackType::Pop() {
	if (IsEmpty()) { cout << "스택 공백 에러" << endl; return -9999; }
	else
		return data[top--];
}

void DfsStack(StackType* stack, GraphType* graph) {
	stack->Push(0);
	while (!stack->IsEmpty())
	{
		//스택에서 방문하지 않은 정점 하나를 꺼냄
		vertex v = stack->Pop();
		graph->SetVisited(v, true);
		cout << "정점 " << v << " -> ";

		//인접정점 확인 반복문
		for (vertex other = 0; other < graph->GetSize(); other++)
		{	// 인접정점이고
			if (graph->GetEdge(v, other))
				if (!graph->GetVisited(other)) {	//방문하지 않았을경우
					stack->Push(other);				//스택에 정점 추가
				}
		}
	}
}

//			0
//		1   2	3
//      4	5
int main()
{
	GraphType graph;
	for (int i = 0; i < 6; i++)
		graph.AddVertex();

	graph.InsertEdge(0, 1);
	graph.InsertEdge(1, 0);

	graph.InsertEdge(0, 2);
	graph.InsertEdge(2, 0);

	graph.InsertEdge(0, 3);
	graph.InsertEdge(3, 0);

	graph.InsertEdge(4, 1);
	graph.InsertEdge(1, 4);

	graph.InsertEdge(2, 5);
	graph.InsertEdge(5, 2);

	StackType stack;

	cout << "깊이 우선탐색 시작" << endl;
	DfsStack(&stack, &graph);
	cout << endl;
	return 0;
}