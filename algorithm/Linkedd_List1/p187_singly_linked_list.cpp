#include<iostream>

using std::cout;
using std::endl;
using std::cin;

typedef int element;

class ListNode {
public:
	ListNode* link;
	element data;
	void insert_first(element value) {
		ListNode* old_head = new ListNode;	//����� data�� link(������� �ּ�)�� ���� ��� ����
		if (old_head == NULL) { cout << "���ο� ��带 �Ҵ���� ���߽��ϴ�." << endl; }
		else {
			old_head->link = link;			//������� link(������� �ּ�)�� ���(��)�� link(��������ּ�)�� ����
			old_head->data = data;			//������忡 ���(��)�� data���� �Է�
			
			link = old_head;				//���(��)�� link(������� �ּ�)�� ��������� �ּ� ����
			data = value;					//���(��)���� ���ο� ��尪(value)�� �Է�
		}
	}
	~ListNode() {
		delete this;
	}
};

int main()
{
	ListNode* node = new ListNode;
	node->data = 10;
	cout << node->data << endl;
	node->insert_first(20);
	cout << node->data << " " << node->link->data << endl;
	node->insert_first(30);
	cout << node->data << " " << node->link->data << " " << node->link->link->data << endl;
	return 0;
}