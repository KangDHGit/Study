#include<iostream>

using std::cout;
using std::endl;
using std::cin;

struct element {
	char word[20];
};

class ListNode {
public:
	element data;
	ListNode* Link;
	ListNode() { Link = NULL; }
	static ListNode* insert_first(ListNode* head, element data) {
		ListNode* new_head = new ListNode;
		new_head->data = data;
		new_head->Link = head;
		head = new_head;
		return head;
	}
	static ListNode* delete_first(ListNode* head) {
		ListNode* removed = head;
		if (removed == NULL) { cout << "매개변수가 NULL 입니다." << endl; return head; }
		head = head->Link;
		return head;
	}

	static ListNode* insert(ListNode* head, element data, int index) {
		if (index == 0)
			head = insert_first(head, data);

		ListNode* pre = head;			//BANANA
		for (int i = 1; i < index; i++) //1,2,3 //ORANGE->APPLE->MELON
		{
			if (pre->Link == NULL) { cout << "잘못된 인덱스 입니다." << endl; return head; }
			pre = pre->Link;
		}

		if (pre->Link == NULL) { cout << "잘못된 인덱스 입니다." << endl; return head; }

		ListNode* new_Node = new ListNode;
		new_Node->data = data;
		new_Node->Link = pre->Link;
		pre->Link = new_Node;
		return head;
	}
	static ListNode* add(ListNode* head, element data) {
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
			if (pre_Node->Link == NULL) { cout << "잘못된 인덱스 입니다." << endl; return head; }
		}

		if (pre_Node->Link == NULL) { cout << "잘못된 인덱스 입니다." << endl; return head; }

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
};

int main()
{
	ListNode* head = NULL;
	element data{ "APPLE" };
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

	strcpy_s(data.word, "BERRY");;
	head = ListNode::insert(head, data, 3);
	ListNode::print_list(head);					//BANANA->ORANGE->APPLE->BERRY->MELON

	head = ListNode::delete_Node(head, 3);
	ListNode::print_list(head);					//BANANA->ORANGE->APPLE->MELON

	return 0;
}