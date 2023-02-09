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
	GraphNode* adj_list[max_vertices];	//������ �����带 ������ �迭(�ε��� ��ȣ�� ������ȣ)

public:
	GraphType() { Init(); }
	void Init() {
		n = 0;
		for (int v = 0; v < max_vertices; v++)
			adj_list[v] = nullptr;
	}
	void AddVertex() {
		if(n + 1 > max_vertices)
			cout << "�׷����� �ִ� ���� ������ �ʰ��߽��ϴ�." << endl;
		else
		{
			n++;
			cout << "������ �߰��߽��ϴ�. ���� ������ ���� : " << n << endl;
		}
	}
	//u��������Ʈ(����)�� v�� ����(��������)
	void InsertEdge(int u, int v) {
		if (u >= n || v >= n)
			cout << "�Է� ������ȣ ����" << endl;
		else {
			GraphNode* node = new GraphNode{ v, nullptr };
			if (node == nullptr) { cout << "�޸� �Ҵ� ����" << endl; return; }
			node->vertex = v;
			node->link = adj_list[u];
			adj_list[u] = node;
		}
	}

	void PrintAdjlist() {
		for (int i = 0; i < n; i++)
		{
			GraphNode* p = adj_list[i];
			cout << "���� " << i << "�� ��������Ʈ -> ";
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
			cout << "���� " << i << "�� ��������Ʈ ���� -> ";
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
	~GraphType() { DeleteAdjlist(); cout << "���� �Ϸ�" << endl; }
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