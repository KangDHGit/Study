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
		cout << "�׷����� �ִ� ���� ������ �ʰ��߽��ϴ�." << endl;
	else {
		n++;
		cout << "������ �߰��߽��ϴ�. ���� ���� ���� : " << n << endl;
	}
}

bool GraphType::GetVisit(int vertex) {
	return visited[vertex];
}

void GraphType::SetVisit(int vertex, bool visit) {
	visited[vertex] = visit;
}

void GraphType::InsertEdge(int start, int end) {
	if (start >= n || end >= n || start < 0 || end < 0) { cout << "�Է� ������ȣ ����" << endl; return; }
	GraphNode* newNode = new GraphNode{ end, nullptr };
	if (newNode == nullptr) { cout << "�޸� �Ҵ� ����" << endl; return; }
	newNode->link = adj_list[start];
	adj_list[start] = newNode;
}

//���� �׷����ϰ�츸 ����
void DfsList(GraphType* graph, int vertex) {
	if (graph == nullptr) { cout << "�׷����� nullptr �Դϴ�." << endl; return; }
	if (vertex < 0 || vertex >= graph->GetVertexCount()) { cout << "�Է� ������ȣ ����" << endl; return; }

	//adj_list[vertex]�� vertex�� �������� ���ֱ� ������ �ڽ��� vertex���� ���
	cout << "���� " << vertex << " -> ";	
	//�湮ǥ��
	graph->SetVisit(vertex, true);

	//������带 ������
	GraphNode* node = graph->GetHeadNode(vertex);
	while (node != nullptr)
	{
		cout << "���� " << node->vertex << " -> ";
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

	cout << "���� �켱Ž�� ����" << endl;
	DfsList(&graph, 0);
	cout << endl;

	graph.VisitInit();
	cout << "���� �켱Ž�� ����" << endl;
	DfsList(&graph, 1);
	cout << endl;

	graph.VisitInit();
	cout << "���� �켱Ž�� ����" << endl;
	DfsList(&graph, 2);
	cout << endl;

	graph.VisitInit();
	cout << "���� �켱Ž�� ����" << endl;
	DfsList(&graph, 3);
	cout << endl;

	return 0;
}