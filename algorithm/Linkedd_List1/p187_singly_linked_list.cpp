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