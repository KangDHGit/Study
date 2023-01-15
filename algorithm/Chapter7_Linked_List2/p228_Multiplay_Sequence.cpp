#include<iostream>

using std::cout;
using std::endl;
using std::cin;

typedef char element[100];

struct ListNode {
	element data;
	ListNode* link;
	ListNode(element item, ListNode* link) {
		strcpy(data, item); this->link = link;
	}
};

class CircularList {
	ListNode* head;
	int size;
public:
	void Init() { size == 0; head = nullptr; }
	CircularList() { Init(); }
	void InsertFirst(element item);
	void Print();
};
void CircularList::InsertFirst(element item) {
	ListNode* new_node = new ListNode(item, nullptr);
	if (new_node == nullptr) { cout << "�޸� �Ҵ� ����" << endl; return; }
	if (head == nullptr) { 
		head = new_node; 
		new_node->link = head;
		size++;
		return;
	}
	new_node->link = head->link;
	head->link = new_node;
	size++;
}
void CircularList::Print() {
	if (head == nullptr) { cout << "����Ʈ�� ����ֽ��ϴ�." << endl; return; }

	ListNode* iter = head->link;
	do
	{
		if (iter == nullptr) { cout << "����Ʈ NULL ����" << endl; return; }
		cout << iter->data << " ";
		iter = iter->link;
	} while (iter != head->link);
}

int main()
{
	return 0;
}