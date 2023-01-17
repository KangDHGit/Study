#include<iostream>

using std::cout;
using std::endl;
using std::cin;

//���� ���Ḯ��Ʈ ���� �� Ư���� ���� Ž���ϰ� ��带 ��ȯ�ϴ� search �Լ� �ۼ�
typedef int element;
#pragma region question_3
struct NodeType {
	element data;
	NodeType* link;
};

class CircularList {
	NodeType* head;
	int size;
	void Init();
public:
	CircularList() { Init(); }
	void InsertFirst(element item);
	void InsertLast(element	item);
	NodeType* Search(element data);
	void Clear();
	~CircularList() { Clear(); cout << "�����Ҵ� �޸� ���� �Ϸ�" << endl; }
};

void CircularList::Init() {
	head = nullptr; size = 0;
}

void CircularList::InsertFirst(element item) {
	NodeType* new_node = new NodeType{ item, nullptr };
	if (new_node == nullptr) { cout << "�޸� �Ҵ� ����" << endl; return; }
	if (head == nullptr) { head = new_node; new_node->link = head; }
	else {
		new_node->link = head->link;
		head->link = new_node;
	}
	size++;
}
void CircularList::InsertLast(element item) {
	NodeType* new_node = new NodeType{ item, nullptr };
	if (new_node == nullptr) { cout << "�޸� �Ҵ� ����" << endl; return; }
	if (head == nullptr) { head = new_node; new_node->link = head; }
	else {
		new_node->link = head->link;
		head->link = new_node;
		head = new_node;
	}
}
#pragma endregion


int main()
{
	return 0;
}