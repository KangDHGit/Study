#include<iostream>

using std::cout;
using std::endl;
using std::cin;

struct GraphNode {
	int vertex;			//���� ��ȣ
	GraphNode* link;	//���� ��������
};

class GraphType {
	static const int max_vertices = 50;
	int n;								//������ ����
	GraphNode* adj_list[max_vertices];	//������ �����带 ������ �迭

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