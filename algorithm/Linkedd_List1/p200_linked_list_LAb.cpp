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
		if (removed == NULL) { cout << "매개변수가 NULL 입니다." << endl; return head; }
		head = head->Link;
		return head;
	}

	static ListNode* insert(ListNode* head, Data data, int index) {
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

	//p202 특정한 값을 탐색하는 함수
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
	//p204 두개의 리스트를 하나로 합치기
	static ListNode* Concat_List(ListNode* head1, ListNode* head2) {
		if (head1 == NULL) { return head2; }
		else if (head2 == NULL) { return head1; }
		else {
			ListNode* iter = head1;
			while (iter->Link != NULL)
				iter = iter->Link;
			iter->Link = head2;
			cout << "Concat_List 완료" << endl;
			return head1;
		}
	}
	//p206 리스트를 역순으로 만들기
	static ListNode* Reverse(ListNode* head) {
		ListNode* r_head = NULL;		//역순으로 만든 리스트의 헤드가 될 포인터
		ListNode* r_nodes;				//역순으로 만드는 리스트의 노드들(r_head의 다음애들)
		ListNode* iter = head;			//head부터 정순으로 돌면서 노드들을 넘겨주는 포인터
		// 최종은 r_head->r_nodes.....->NULL 의 모습으로 만들기위함
		while (iter != NULL)		//전부 반전으로 만들었는지 확인
		{
			r_nodes = r_head;		//전부 역순으로 만든것이 아니기때문에 r_nodes에게 노드를 넘김
			r_head = iter;			//반전할 노드를 새로운 헤드에 넘겨주기
			iter = iter->Link;		//반전할 다음 노드로 이동(연결 끊기)
			r_head->Link = r_nodes;	//거꾸로 연결
			//순서주의(잘못된 순서)!
			//r_nodes = r_head;	
			//r_head = iter;		
			//r_head->Link = r_nodes; //아직 iter이 r_head랑 같은 값의 주소를 가지고 있기 때문에
			//iter = iter->Link;	  
		}
		cout << "Reverse..." << endl;
		return r_head;
	}
};

int main()
{
#pragma region p200 단어를 저장하는 리스트
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

#pragma region p202 특정한 값을 찾는 함수
	strcpy_s(data.word, "ORANGE");
	if (ListNode::contains(head, data))
		cout << "리스트에서 " << data.word << "를 찾았습니다." << endl;
	else
		cout << "리스트에서" << data.word << "를 찾지 못했습니다" << endl;

	strcpy_s(data.word, "BERRY");
	if (ListNode::contains(head, data))
		cout << "리스트에서 " << data.word << "를 찾았습니다." << endl;
	else
		cout << "리스트에서 " << data.word << "를 찾지 못했습니다" << endl;

	if(ListNode::Find(head, data) != NULL)
		cout << "리스트에서 " << data.word << "를 찾았습니다." << endl;
	else
		cout << "리스트에서 " << data.word << "를 찾지 못했습니다" << endl;
#pragma endregion

#pragma region p204 두개의 리스트를 합치는 함수
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
	
#pragma region p206 리스트 반전
	head = ListNode::Reverse(head);
	cout << "head : "; ListNode::print_list(head);
#pragma endregion

	
	return 0;
}