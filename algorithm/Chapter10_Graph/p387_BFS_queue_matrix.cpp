#include<iostream>

using std::cout;
using std::endl;
using std::cin;

typedef int vertex;

//�湮�� ������ ���� ť �ڷᱸ��
class QueueType {
	const static int maxSize = 10;
	vertex queue[maxSize];
	int front;
	int rear;
	void Init() { front = 0; rear = 0; }
public :
	QueueType() { Init(); }
	bool IsEmpty() { return front == rear; }
	bool IsFull() { return (rear + 1) % maxSize == front; }
	void Enqueue(vertex data);
	vertex Dequeue();
};
void QueueType::Enqueue(vertex data) {
	if (IsFull()) { cout << "ť ��ȭ ����" << endl; return; }
	rear = (rear + 1) % maxSize;
	queue[rear] = data;
}
vertex QueueType::Dequeue() {
	if (IsEmpty()) { cout << "ť ���� ����" << endl; return vertex{ -9999 }; }
	front = (front + 1) % maxSize;
	return queue[front];
}

class GraphType {
	const static int maxVertices = 10;
	int n;
	int adj_mat[maxVertices][maxVertices];
	bool visited[maxVertices];
	void Init();
public:
	GraphType() { Init(); }
	int GetVertexCount() { return n; }
	void AddVertex();
	void InsertEdge(vertex start, vertex end);
	int GetEdge(vertex start, vertex end);
	void SetVisit(vertex v, bool visit);
	bool GetVisit(vertex v);
};
void GraphType::Init() {
	n = 0;
	for (int r = 0; r < maxVertices; r++)
	{
		visited[r] = false;
		for (int c = 0; c < maxVertices; c++)
			adj_mat[r][c] = 0;
	}
}
void GraphType::AddVertex() {
	if (n + 1 > maxVertices)
		cout << "�׷����� �ִ� ���� ������ �ʰ��߽��ϴ�." << endl;
	else {
		n++;
		cout << "������ �߰��߽��ϴ�. ���� ���� ���� : " << n << endl;
	}
}
void GraphType::InsertEdge(vertex start, vertex end) {
	if (start >= n || end >= n || start < 0 || end < 0)
		cout << "�Է� ������ȣ ����" << endl;
	else
	{
		adj_mat[start][end] = 1;
		adj_mat[end][start] = 1;
	}
}
vertex GraphType::GetEdge(vertex start, vertex end) {
	if (start >= n || end >= n || start < 0 || end < 0) {
		cout << "�Է� ������ȣ ����" << endl; return vertex{ -9999 };
	}
	else
		return adj_mat[start][end];
}
void GraphType::SetVisit(vertex v, bool visit) {
	if (v >= n || v < 0)
		cout << "�Է� ������ȣ ����" << endl;
	else
		visited[v] = visit;
}
bool GraphType::GetVisit(vertex v) {
	if (v >= n || v < 0) {
		cout << "�Է� ������ȣ ����" << endl; return false;
	}
	else
		return visited[v];
}

void BfsMat(GraphType* graph, vertex startV) {
	QueueType queue;
	//���� ������ �湮�ϰ� ť�� �߰�
	graph->SetVisit(startV, true);
	queue.Enqueue(startV);

	//ť�� ������ ������ �ݺ�
	while (!queue.IsEmpty())
	{	
		//ť���� �湮�� ��������
		vertex v = queue.Dequeue();
		cout << v << " �湮 -> ";
		//���� ������ �������� �׷����� �ٸ� �������� ������������ and �湮���� Ȯ��
		for (vertex otherV = 0; otherV < graph->GetVertexCount(); otherV++)
		{
			if (graph->GetEdge(v, otherV) && !graph->GetVisit(otherV)) {	//���������̰� �湮 ���������
				graph->SetVisit(otherV, true);	//�湮�ϰ�
				queue.Enqueue(otherV);			//�湮�� ������ ť�� �߰�
			}
		}
	}
	cout << endl;
}

int main()
{
	GraphType g;
	for (int i = 0; i < 6; i++)
		g.AddVertex();
	
	g.InsertEdge(0, 2);
	g.InsertEdge(2, 1);
	g.InsertEdge(2, 3);
	g.InsertEdge(2, 5);
	g.InsertEdge(0, 4);
	g.InsertEdge(4, 5);
	g.InsertEdge(3, 5);
	g.InsertEdge(1, 5);

	BfsMat(&g, 0);

	return 0;
}