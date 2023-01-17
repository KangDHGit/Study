#include<iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

typedef string element;

struct ListNode {
	element data;
	ListNode* l_link;
	ListNode* r_link;
};

class Mp3Player {
	ListNode* phead;
	ListNode* current;	//현재 재생중인 노래
	int size;
	void Init();
public:
	Mp3Player() { Init(); }
	void Insert(element music, int index = 0);
	void Delete(int index = 0);
	void Print();
	void Play();
	void Clear();
	~Mp3Player() { Clear(); delete phead; cout << "동적 할당 메모리 삭제 완료" << endl; }
};

void Mp3Player::Init() {
	size = 0;
	current == nullptr;
	if (phead == nullptr) { phead = new ListNode{ "ListHead", nullptr, nullptr }; }
	if (phead == nullptr) { cout << "초기화 오류" << endl; return; }
	phead->r_link = phead;
	phead->l_link = phead;
}

void Mp3Player::Insert(element music, int index) {
	if (index < 0 || index > size) { cout << "옳바르지 않은 인덱스 입니다." << endl; return; }
	if (phead == nullptr) { cout << "리스트가 NULL 입니다." << endl; return; }

	ListNode* new_node = new ListNode{ music, nullptr, nullptr };
	if (new_node == nullptr) { cout << "메모리 할당 에러" << endl; return; }

	ListNode* iter = phead->r_link;
	for (int i = 0; i < index; i++) {
		if (iter == nullptr) { cout << "노드가 NULL 입니다." << endl; return; }
		iter = iter->r_link;
	}

	ListNode* l_node = iter;
	ListNode* r_node = iter->r_link;
	new_node->l_link = l_node;
	new_node->r_link = r_node;
	l_node->r_link = new_node;
	r_node->l_link = new_node;
	size++;
}

void Mp3Player::Delete(int index) {
	if (index < 0 || index > size) { cout << "옳바르지 않은 인덱스 입니다." << endl; return; }
	if (phead == nullptr) { cout << "리스트가 NULL 입니다." << endl; return; }

	ListNode* removed = phead->r_link;
	for (int i = 0; i < index; i++) {
		if (removed == nullptr) { cout << "노드가 NULL 입니다." << endl; return; }
		removed = removed->r_link;
	}

	ListNode* l_node = removed->l_link;
	ListNode* r_node = removed->r_link;
	l_node->r_link = r_node;
	r_node->l_link = l_node;
	delete removed;
	size--;
}

void Mp3Player::Print() {
	if (phead == nullptr) { cout << "리스트가 NULL 입니다." << endl; return; }
	if (phead->r_link != nullptr && size != 0) {
		ListNode* iter = phead->r_link;
		while (iter != phead)
		{
			if (iter != current)
				cout << "<-|  " << iter->data << "  |-> ";
			else
				cout << "<-| #" << iter->data << "# |-> ";
			iter = iter->r_link;
		}
		cout << endl;
	}
}

void Mp3Player::Play() {
	cout << "==========재생 시작==========" << endl;;
	char command;
	current = phead->r_link;
	while (current != nullptr)
	{
		Print(); cout << endl;
		cout << "명령어를 입력하시오(<, >, q) : "; cin >> command;
		switch (command)
		{
		case '<':
			current = current->l_link;
			if (current == phead) { current = current->l_link; }
			break;
		case '>':
			current = current->r_link;
			if (current == phead) { current = current->r_link; }
			break;
		case 'q':
			cout << "==========재생 종료==========" << endl;
			return;
		default:
			cout << "잘못된 명령어 입니다." << endl;
			break;
		}
	}
}

void Mp3Player::Clear() {
	if (phead == nullptr) { cout << "리스트가 NULL 입니다." << endl; return; }
	if (phead->r_link != nullptr && size != 0) {
		ListNode* removed = phead->r_link;
		ListNode* r_node = nullptr;
		while (removed != phead)
		{
			if (removed == nullptr) { cout << "노드가 NULL 입니다." << endl; return; }
			r_node = removed->r_link;
			delete removed;
			removed = r_node;
		}
		size = 0;
	}
}

int main()
{
	Mp3Player* player = new Mp3Player;
	player->Insert(element{ "Fernando" });
	player->Insert(element{ "Dancing Queen" });
	player->Insert(element{ "Mamamia" });
	player->Play();

	delete player;
	return 0;
}