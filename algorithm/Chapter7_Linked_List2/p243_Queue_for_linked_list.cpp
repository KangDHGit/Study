#include<iostream>

using std::cout;
using std::endl;
using std::cin;

typedef int element;

struct QueueNode {
	element data;
	QueueNode* link;
};

class LinkedQueueType {
	QueueNode* front;
	QueueNode* rear;
	int size;
	void Init();
public:
	LinkedQueueType() { Init(); }
	bool IsEmpty() { return front == nullptr; }
	bool IsFull() { return false; }
	int GetSize() { return size; }
	void Enqueue(element item);
	element Dequeue();
	element Peek();
	void Print();
	void Clear();
	~LinkedQueueType() { Clear(); cout << "동적 할당 메모리 삭제 완료" << endl; }
};

void LinkedQueueType::Init() {
	size = 0; front == nullptr; rear = nullptr;
}

void LinkedQueueType::Enqueue(element item) {
	QueueNode* new_node = new QueueNode{ item, nullptr };
	if (new_node == nullptr) { cout << "메모리 할당 에러" << endl; }
	if (IsEmpty()) { front = new_node; rear = new_node; }
	else {
		rear->link = new_node;
		rear = new_node;
	}
	size++;
}

element LinkedQueueType::Dequeue() {
	if (IsEmpty()) { cout << "리스트가 비어있습니다." << endl; return element{ -9999 }; }
	else {
		QueueNode* removed = front;
		element pop_data = removed->data;
		front = front->link;
		size--;
		delete removed;
		return pop_data;
	}
}

element LinkedQueueType::Peek() {
	if (IsEmpty()) { cout << "리스트가 비어있습니다." << endl; return element{ -9999 }; }
	else
		return front->data;
}

void LinkedQueueType::Clear() {
	if (!IsEmpty()) {
		QueueNode* iter = front;
		QueueNode* removed = nullptr;
		while (iter != nullptr)
		{
			removed = iter;
			iter = iter->link;
			delete removed;
		}
		Init();
	}
}

void LinkedQueueType::Print() {
	QueueNode* iter = front;
	while (iter != nullptr)
	{
		cout.width(2); cout << iter->data << "->";
		iter = iter->link;
	}
	cout << "NULL" << endl;
}

int main()
{
	LinkedQueueType* queue = new LinkedQueueType;
	for (int i = 0; i < 5; i++)
		queue->Enqueue(i);
	cout << "size : " << queue->GetSize() << endl;
	queue->Print();

	for (int i = 0; i < 2; i++)
		queue->Dequeue();
	cout << "size : " << queue->GetSize() << endl;
	queue->Print();

	delete queue;
	return 0;
}