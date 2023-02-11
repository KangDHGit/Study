#include<iostream>

using std::cout;
using std::endl;
using std::cin;

typedef int vertex;

//방문한 정점을 담을 큐 자료구조
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
	if (IsFull()) { cout << "큐 포화 에러" << endl; return; }
	rear = (rear + 1) % maxSize;
	queue[rear] = data;
}
vertex QueueType::Dequeue() {
	if (IsEmpty()) { cout << "큐 공백 에러" << endl; return vertex{ -9999 }; }
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
		cout << "그래프의 최대 정점 개수를 초과했습니다." << endl;
	else {
		n++;
		cout << "정점을 추가했습니다. 현재 정점 개수 : " << n << endl;
	}
}
void GraphType::InsertEdge(vertex start, vertex end) {
	if (start >= n || end >= n || start < 0 || end < 0)
		cout << "입력 정점번호 오류" << endl;
	else
	{
		adj_mat[start][end] = 1;
		adj_mat[end][start] = 1;
	}
}
vertex GraphType::GetEdge(vertex start, vertex end) {
	if (start >= n || end >= n || start < 0 || end < 0) {
		cout << "입력 정점번호 오류" << endl; return vertex{ -9999 };
	}
	else
		return adj_mat[start][end];
}
void GraphType::SetVisit(vertex v, bool visit) {
	if (v >= n || v < 0)
		cout << "입력 정점번호 오류" << endl;
	else
		visited[v] = visit;
}
bool GraphType::GetVisit(vertex v) {
	if (v >= n || v < 0) {
		cout << "입력 정점번호 오류" << endl; return false;
	}
	else
		return visited[v];
}

void BfsMat(GraphType* graph, vertex startV) {
	QueueType queue;
	//시작 정점을 방문하고 큐에 추가
	graph->SetVisit(startV, true);
	queue.Enqueue(startV);

	//큐가 소진될 때까지 반복
	while (!queue.IsEmpty())
	{	
		//큐에서 방문한 정점꺼냄
		vertex v = queue.Dequeue();
		cout << v << " 방문 -> ";
		//꺼낸 정점을 기준으로 그래프내 다른 정점들이 인접정점인지 and 방문여부 확인
		for (vertex otherV = 0; otherV < graph->GetVertexCount(); otherV++)
		{
			if (graph->GetEdge(v, otherV) && !graph->GetVisit(otherV)) {	//인접정점이고 방문 안했을경우
				graph->SetVisit(otherV, true);	//방문하고
				queue.Enqueue(otherV);			//방문한 정점을 큐에 추가
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