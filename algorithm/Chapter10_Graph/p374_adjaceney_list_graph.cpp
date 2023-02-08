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
	GraphNode* adj_list[max_vertices];	//정점별 헤더노드를 저장할 배열

public:
	GraphType() { Init(); }
	void Init() {
		n = 0;
		for (int v = 0; v < max_vertices; v++)
			adj_list[v] = nullptr;
	}
};

int main()
{
	return 0;
}