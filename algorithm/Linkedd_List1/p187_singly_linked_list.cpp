#include<iostream>

using std::cout;
using std::endl;
using std::cin;

typedef int element;

class ListNode {
public:
	ListNode* link;
	element data;
#pragma region My
	//void insert_first(element value) {
	//	ListNode* old_head = new ListNode;	//����� data�� link(������� �ּ�)�� ���� ��� ����
	//	if (old_head == NULL) { cout << "���ο� ��带 �Ҵ���� ���߽��ϴ�." << endl; }
	//	else {
	//		old_head->link = link;			//������� link(������� �ּ�)�� ���(��)�� link(��������ּ�)�� ����
	//		old_head->data = data;			//������忡 ���(��)�� data���� �Է�

	//		link = old_head;				//���(��)�� link(������� �ּ�)�� ��������� �ּ� ����
	//		data = value;					//���(��)���� ���ο� ��尪(value)�� �Է�
	//	}
	//}
	//~ListNode() {
	//	delete this;
	//}
#pragma endregion
	static ListNode* insert_first(ListNode* head, element data) {
		ListNode* new_head = new ListNode;
		new_head->data = data;
		new_head->link = head;
		head = new_head;
		return head;
	}

};

int main()
{
	/*ListNode* node = new ListNode;
	node->data = 10;
	cout << node->data << endl;
	node->insert_first(20);
	cout << node->data << " " << node->link->data << endl;
	node->insert_first(30);
	cout << node->data << " " << node->link->data << " " << node->link->link->data << endl;*/

	ListNode* node0 = new ListNode;
	node0->data = 10;
	cout << node0->data << endl;
	ListNode* node1 = ListNode::insert_first(node0, 20);
	cout << node1->data << endl;
	return 0;
}