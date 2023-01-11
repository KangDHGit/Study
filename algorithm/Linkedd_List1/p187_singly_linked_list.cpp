#include<iostream>

using std::cout;
using std::endl;
using std::cin;

typedef int Data;

class ListNode {
public:
	ListNode* link;
	Data data;
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
	static ListNode* insert_first(ListNode* head, Data data) {
		ListNode* new_head = new ListNode;
		new_head->data = data;
		new_head->link = head;
		head = new_head;
		return head;
	}

	static ListNode* insert(ListNode* head, ListNode* pre, Data data) {
		ListNode* new_Node = new ListNode;
		new_Node->data = data;
		new_Node->link = pre->link;
		pre->link = new_Node;
		return head;
	}

	static ListNode* delete_first(ListNode* head) {
		ListNode* removed = head;
		if (removed == NULL) {
			cout << "�Ű������� NULL �Դϴ�." << endl;
			return NULL;
		}
		head = head->link;
		delete removed;
		return head;
	}

	static ListNode* delete_Node(ListNode* head, ListNode* pre) {
		ListNode* removed = pre->link;
		pre->link = removed->link;
		delete removed;
		return head;
	}

	static void print_list(ListNode* head) {
		for (ListNode* iter = head; iter != NULL; iter = iter->link)
			cout << iter->data << "->";
		cout << "NULL" << endl;
	}
	//��������
	static Data get_entry(ListNode* head, int index) {
		if (head == NULL) { cout << "����Ʈ�� NULL �Դϴ�." << endl; return Data{ -1 }; }
		ListNode* resultNode = head;
		for (int i = 0; i < index; i++)
		{
			if (resultNode == NULL) { cout << "�߸��� �ε��� ���Դϴ�." << endl; return Data{ -1 }; }
			resultNode = resultNode->link;
		}
		return resultNode->data;
	}
};

int main()
{
	ListNode* head = NULL;
	for (int i = 0; i < 5; i++) {
		head = ListNode::insert_first(head, i);
		ListNode::print_list(head);
	}

	ListNode* pre = head->link->link;		//4->3->2, �� 2�� ����ִ� ���
	head = ListNode::insert(head, pre, 10);	//2�� ����ִ� ���ڿ� 10 ����
	ListNode::print_list(head);				//4->3->2->10->1->0
	Data data = ListNode::get_entry(head, 3);
	cout << "3��° �ε����� : " << data << "�Դϴ�." << endl;

	head = ListNode::delete_first(head);
	ListNode::print_list(head);				//3->2->10->1->0;
	ListNode::delete_Node(head, pre);		//pre�� ������� ����
	ListNode::print_list(head);				//3->2->1->0

	return 0;
}