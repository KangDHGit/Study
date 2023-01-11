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
	//	ListNode* old_head = new ListNode;	//헤드의 data와 link(다음노드 주소)를 받을 노드 생성
	//	if (old_head == NULL) { cout << "새로운 노드를 할당받지 못했습니다." << endl; }
	//	else {
	//		old_head->link = link;			//생성노드 link(다음노드 주소)에 헤드(나)의 link(다음노드주소)를 연결
	//		old_head->data = data;			//생성노드에 헤드(나)의 data값을 입력

	//		link = old_head;				//헤드(나)의 link(다음노드 주소)에 생성노드의 주소 연걸
	//		data = value;					//헤드(나)에게 새로운 헤드값(value)을 입력
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
			cout << "매개변수가 NULL 입니다." << endl;
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
	//도전과제
	static Data get_entry(ListNode* head, int index) {
		if (head == NULL) { cout << "리스트가 NULL 입니다." << endl; return Data{ -1 }; }
		ListNode* resultNode = head;
		for (int i = 0; i < index; i++)
		{
			if (resultNode == NULL) { cout << "잘못된 인덱스 값입니다." << endl; return Data{ -1 }; }
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

	ListNode* pre = head->link->link;		//4->3->2, 즉 2가 들어있는 노드
	head = ListNode::insert(head, pre, 10);	//2가 들어있는 노드뒤에 10 삽입
	ListNode::print_list(head);				//4->3->2->10->1->0
	Data data = ListNode::get_entry(head, 3);
	cout << "3번째 인덱스는 : " << data << "입니다." << endl;

	head = ListNode::delete_first(head);
	ListNode::print_list(head);				//3->2->10->1->0;
	ListNode::delete_Node(head, pre);		//pre의 다음노드 삭제
	ListNode::print_list(head);				//3->2->1->0

	return 0;
}