#include<iostream>

using std::cout;
using std::endl;
using std::cin;

struct Data {
	char word[20];
};

class ListNode {
public:
	Data data;
	ListNode* Link;
	ListNode() { Link = NULL; }
	static ListNode* insert_first(ListNode* head, Data data) {
		ListNode* new_head = new ListNode;
		new_head->data = data;
		new_head->Link = head;
		head = new_head;
		return head;
	}
	static ListNode* delete_first(ListNode* head) {
		ListNode* removed = head;
		if (removed == NULL) { cout << "�Ű������� NULL �Դϴ�." << endl; return head; }
		head = head->Link;
		return head;
	}

	static ListNode* insert(ListNode* head, Data data, int index) {
		if (index == 0)
			head = insert_first(head, data);

		ListNode* pre = head;			//BANANA
		for (int i = 1; i < index; i++) //1,2,3 //ORANGE->APPLE->MELON
		{
			if (pre->Link == NULL) { cout << "�߸��� �ε��� �Դϴ�." << endl; return head; }
			pre = pre->Link;
		}

		if (pre->Link == NULL) { cout << "�߸��� �ε��� �Դϴ�." << endl; return head; }

		ListNode* new_Node = new ListNode;
		new_Node->data = data;
		new_Node->Link = pre->Link;
		pre->Link = new_Node;
		return head;
	}
	static ListNode* add(ListNode* head, Data data) {
		ListNode* iter = head;			
		if (iter == NULL) { return insert_first(head, data); }

		while (iter->Link != NULL) {
			iter = iter->Link;
		}
		ListNode* new_node = new ListNode;
		new_node->data = data;
		iter->Link = new_node;
		return head;
	}
	static ListNode* delete_Node(ListNode* head, int index) {
		if (index == 0) { return delete_first(head); }
		ListNode* pre_Node = head;			//BANANA

		for (int i = 1; i < index; i++) {	//BANANA
			pre_Node = pre_Node->Link;		//1,2,3 //ORANGE->APPLE->MELON
			if (pre_Node->Link == NULL) { cout << "�߸��� �ε��� �Դϴ�." << endl; return head; }
		}

		if (pre_Node->Link == NULL) { cout << "�߸��� �ε��� �Դϴ�." << endl; return head; }

		ListNode* removed = pre_Node->Link;
		pre_Node->Link = removed->Link;
		delete removed;
		return head;
	}

	static void print_list(ListNode* head) {
		for (ListNode* iter = head; iter != NULL; iter = iter->Link)
			cout << iter->data.word << "->";
		cout << "NULL" << endl;
	}

	//p202 Ư���� ���� Ž���ϴ� �Լ�
	static bool contains(ListNode* head, Data data) {
		ListNode* iter = head;
		while (iter != NULL)
		{
			std::string str(iter->data.word);
			if (str.compare(data.word) == 0)
				return true;
			iter = iter->Link;
		}
		return false;
	}
	static ListNode* Find(ListNode* head, Data data) {
		ListNode* iter = head;
		while (iter != NULL)
		{
			std::string str(iter->data.word);
			if (str.compare(data.word) == 0)
				return iter;
			iter = iter->Link;
		}
		return NULL;
	}
	//p204 �ΰ��� ����Ʈ�� �ϳ��� ��ġ��
	static ListNode* Concat_List(ListNode* head1, ListNode* head2) {
		if (head1 == NULL) { return head2; }
		else if (head2 == NULL) { return head1; }
		else {
			ListNode* iter = head1;
			while (iter->Link != NULL)
				iter = iter->Link;
			iter->Link = head2;
			cout << "Concat_List �Ϸ�" << endl;
			return head1;
		}
	}
	//p206 ����Ʈ�� �������� �����
	static ListNode* Reverse(ListNode* head) {
		ListNode* r_head = NULL;		//�������� ���� ����Ʈ�� ��尡 �� ������
		ListNode* r_nodes;				//�������� ����� ����Ʈ�� ����(r_head�� �����ֵ�)
		ListNode* iter = head;			//head���� �������� ���鼭 ������ �Ѱ��ִ� ������
		// ������ r_head->r_nodes.....->NULL �� ������� ���������
		while (iter != NULL)		//���� �������� ��������� Ȯ��
		{
			r_nodes = r_head;		//���� �������� ������� �ƴϱ⶧���� r_nodes���� ��带 �ѱ�
			r_head = iter;			//������ ��带 ���ο� ��忡 �Ѱ��ֱ�
			iter = iter->Link;		//������ ���� ���� �̵�(���� ����)
			r_head->Link = r_nodes;	//�Ųٷ� ����
			//��������(�߸��� ����)!
			//r_nodes = r_head;	
			//r_head = iter;		
			//r_head->Link = r_nodes; //���� iter�� r_head�� ���� ���� �ּҸ� ������ �ֱ� ������
			//iter = iter->Link;	  
		}
		cout << "Reverse..." << endl;
		return r_head;
	}
};

int main()
{
#pragma region p200 �ܾ �����ϴ� ����Ʈ
	ListNode* head = NULL;
	Data data{ "APPLE" };
	head = ListNode::insert_first(head, data);
	ListNode::print_list(head);

	strcpy_s(data.word, "BANANA");
	head = ListNode::insert_first(head, data);
	ListNode::print_list(head);					//BANANA->APPLE

	strcpy_s(data.word, "MELON");
	head = ListNode::add(head, data);
	ListNode::print_list(head);					//BANANA->APPLE->MELON

	strcpy_s(data.word, "ORANGE");
	head = ListNode::insert(head, data, 1);
	ListNode::print_list(head);					//BANANA->ORANGE->APPLE->MELON

	strcpy_s(data.word, "BERRY");
	head = ListNode::insert(head, data, 3);
	ListNode::print_list(head);					//BANANA->ORANGE->APPLE->BERRY->MELON

	head = ListNode::delete_Node(head, 3);
	ListNode::print_list(head);					//BANANA->ORANGE->APPLE->MELON

#pragma endregion

#pragma region p202 Ư���� ���� ã�� �Լ�
	strcpy_s(data.word, "ORANGE");
	if (ListNode::contains(head, data))
		cout << "����Ʈ���� " << data.word << "�� ã�ҽ��ϴ�." << endl;
	else
		cout << "����Ʈ����" << data.word << "�� ã�� ���߽��ϴ�" << endl;

	strcpy_s(data.word, "BERRY");
	if (ListNode::contains(head, data))
		cout << "����Ʈ���� " << data.word << "�� ã�ҽ��ϴ�." << endl;
	else
		cout << "����Ʈ���� " << data.word << "�� ã�� ���߽��ϴ�" << endl;

	if(ListNode::Find(head, data) != NULL)
		cout << "����Ʈ���� " << data.word << "�� ã�ҽ��ϴ�." << endl;
	else
		cout << "����Ʈ���� " << data.word << "�� ã�� ���߽��ϴ�" << endl;
#pragma endregion

#pragma region p204 �ΰ��� ����Ʈ�� ��ġ�� �Լ�
	ListNode* head2 = NULL;
	Data data2{ "KIWI" };
	head2 = ListNode::insert_first(head2, data2);
	strcpy_s(data2.word, "TOMATO");
	head2 = ListNode::add(head2, data2);
	cout << "head : "; ListNode::print_list(head);
	cout << "head2 : "; ListNode::print_list(head2);
	head = ListNode::Concat_List(head, head2);
	cout << "head : "; ListNode::print_list(head);
#pragma endregion
	
#pragma region p206 ����Ʈ ����
	head = ListNode::Reverse(head);
	cout << "head : "; ListNode::print_list(head);
#pragma endregion

	
	return 0;
}