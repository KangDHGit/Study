#include<iostream>

using std::cout;
using std::endl;
using std::cin;

struct GraphNode {
	int vertex;
	GraphNode* link;
};

class GraphType {
	const static int max_vertices = 4;
	GraphNode* adj_list[max_vertices];
	int n;
	bool visited[max_vertices];
	void Init();
public:
	GraphType() { Init(); }
	int GetVertexCount() { return n; }
	GraphNode* GetHeadNode(int vertex);
	void VisitInit();
	void AddVertex();
	bool GetVisit(int vertex);
	void SetVisit(int vertex, bool visit);
	void InsertEdge(int start, int end);
};

void GraphType::Init() {
	n = 0;
	for (int i = 0; i < max_vertices; i++)
	{
		adj_list[i] = nullptr;
		visited[i] = false;
	}
}
GraphNode* GraphType::GetHeadNode(int vertex) {
	return adj_list[vertex];
}

void GraphType::VisitInit() {
	for (int i = 0; i < max_vertices; i++)
		visited[i] = false;
}

void GraphType::AddVertex() {
	if(n + 1 > max_vertices)
		cout << "그래프의 최대 정점 개수를 초과했습니다." << endl;
	else {
		n++;
		cout << "정점을 추가했습니다. 현재 정점 개수 : " << n << endl;
	}
}

bool GraphType::GetVisit(int vertex) {
	return visited[vertex];
}

void GraphType::SetVisit(int vertex, bool visit) {
	visited[vertex] = visit;
}

void GraphType::InsertEdge(int start, int end) {
	if (start >= n || end >= n || start < 0 || end < 0) { cout << "입력 정점번호 오류" << endl; return; }
	GraphNode* newNode = new GraphNode{ end, nullptr };
	if (newNode == nullptr) { cout << "메모리 할당 오류" << endl; return; }
	newNode->link = adj_list[start];
	adj_list[start] = newNode;
}

//연결 그래프일경우만 가능
void DfsList(GraphType* graph, int vertex) {
	if (graph == nullptr) { cout << "그래프가 nullptr 입니다." << endl; return; }
	if (vertex < 0 || vertex >= graph->GetVertexCount()) { cout << "입력 정점번호 오류" << endl; return; }

	//adj_list[vertex]는 vertex의 인접노드로 되있기 때문에 자신의 vertex부터 출력
	cout << "정점 " << vertex << " -> ";	
	//방문표시
	graph->SetVisit(vertex, true);

	//인접노드를 가져옴
	GraphNode* node = graph->GetHeadNode(vertex);
	while (node != nullptr)
	{
		cout << "정점 " << node->vertex << " -> ";
		node = node->link;
		if (node != nullptr && graph->GetVisit(node->vertex))
			DfsList(graph, node->vertex);
	}
}

int main()
{
	GraphType graph;
	for (int i = 0; i < 4; i++)
		graph.AddVertex();

	graph.InsertEdge(0, 1);
	graph.InsertEdge(1, 0);
	graph.InsertEdge(0, 2);
	graph.InsertEdge(2, 0);
	graph.InsertEdge(0, 3);
	graph.InsertEdge(3, 0);
	graph.InsertEdge(1, 2);
	graph.InsertEdge(2, 1);
	graph.InsertEdge(2, 3);
	graph.InsertEdge(3, 2);

	cout << "깊이 우선탐색 시작" << endl;
	DfsList(&graph, 0);
	cout << endl;

	graph.VisitInit();
	cout << "깊이 우선탐색 시작" << endl;
	DfsList(&graph, 1);
	cout << endl;

	graph.VisitInit();
	cout << "깊이 우선탐색 시작" << endl;
	DfsList(&graph, 2);
	cout << endl;

	graph.VisitInit();
	cout << "깊이 우선탐색 시작" << endl;
	DfsList(&graph, 3);
	cout << endl;

	return 0;
}