#include<iostream>

using std::cout;
using std::endl;
using std::cin;

struct GraphNode {
	int vertex;			//정점 번호
	GraphNode* link;	//다음 인접정점
};

class GraphType {
	static const int max_vertices = 50;
	int n;								//정점의 개수
	GraphNode* adj_list[max_vertices];	//정점별 헤더노드를 저장할 배열(인덱스 번호가 정점번호)

public:
	GraphType() { Init(); }
	void Init() {
		n = 0;
		for (int v = 0; v < max_vertices; v++)
			adj_list[v] = nullptr;
	}
	void AddVertex() {
		if(n + 1 > max_vertices)
			cout << "그래프의 최대 정점 개수를 초과했습니다." << endl;
		else
		{
			n++;
			cout << "정점을 추가했습니다. 현재 정점의 개수 : " << n << endl;
		}
	}
	//u인접리스트(정점)에 v를 삽입(간선연결)
	void InsertEdge(int u, int v) {
		if (u >= n || v >= n)
			cout << "입력 정점번호 오류" << endl;
		else {
			GraphNode* node = new GraphNode{ v, nullptr };
			if (node == nullptr) { cout << "메모리 할당 오류" << endl; return; }
			node->vertex = v;
			node->link = adj_list[u];
			adj_list[u] = node;
		}
	}

	void PrintAdjlist() {
		for (int i = 0; i < n; i++)
		{
			GraphNode* p = adj_list[i];
			cout << "정점 " << i << "의 인접리스트 -> ";
			while (p != nullptr)
			{
				cout << p->vertex << " -> ";
				p = p->link;
			}
			cout << endl;
		}
	}
	void DeleteAdjlist() {
		for (int i = 0; i < n; i++)
		{
			GraphNode* p = adj_list[i];
			cout << "정점 " << i << "의 인접리스트 삭제 -> ";
			while (p != nullptr)
			{
				GraphNode* removed = p;
				cout << removed->vertex << " -> ";
				p = p->link;
				delete removed;
			}
			cout << endl;
		}
	}
	~GraphType() { DeleteAdjlist(); cout << "삭제 완료" << endl; }
};

int main()
{
	GraphType g;
	for (int i = 0; i < 4; i++)
		g.AddVertex();
	g.InsertEdge(0, 1);
	g.InsertEdge(1, 0);
	g.InsertEdge(0, 2);
	g.InsertEdge(2, 0);
	g.InsertEdge(0, 3);
	g.InsertEdge(3, 0);
	g.InsertEdge(1, 2);
	g.InsertEdge(2, 1);
	g.InsertEdge(2, 3);
	g.InsertEdge(3, 2);

	g.PrintAdjlist();

	return 0;
}