#include<iostream>

using std::cout;
using std::endl;
using std::cin;

typedef int element;

class ArrayListType {
	const static int MAX_LIST_SIZE = 100;
	element arr[MAX_LIST_SIZE];
	int size;

public:
	void error(const char* messege) {
		cout << messege << endl; exit(1); }
	void init() { size = 0; }
	ArrayListType() { init(); }
	bool is_empty() { return size == 0; }
	bool is_full() { return size == MAX_LIST_SIZE; }
	element get_entry(int index);
	void print_list();
	void insert_Last(element item);
	void insert(int index, element item);
	element deleteItem(int index);
};

#pragma region ArrayListType_Define
//�ش� �ε��� �ڷ� ��������
element ArrayListType::get_entry(int index) {
	if (index < 0 || index > MAX_LIST_SIZE)
		error("��ġ �Է¿���");
	else
		return arr[index];
}
void ArrayListType::print_list() {
	for (int i = 0; i < size; i++)
		cout << arr[i] << "->";
	cout << endl;
}
void ArrayListType::insert_Last(element item) {
	if (size >= MAX_LIST_SIZE)
		error("����Ʈ �����÷ο�");
	arr[size] = item; size++;
}
void ArrayListType::insert(int index, element item) {
	if (!is_full() && index >= 0 && index <= size) {	//2 3 4, 0 1 3 4 
		for (int i = size - 1; i >= index; i--)
			arr[i + 1] = arr[i];
		arr[index] = item;
		size++;
	}
}

element ArrayListType::deleteItem(int index) {
	element result;
	if (index >= 0 && index < size) {
		element result = arr[index];
		for (int i = index; i < size - 1; i++) // 3, 0 1 2 3 4 , 0 1 2 4
			arr[index] = arr[index + 1];
		size--;
		return result;
	}
	else
		error("��ġ �Է¿���");
}
#pragma endregion


int main()
{
	ArrayListType list;
	list.insert(0, 10); list.print_list();
	list.insert(0, 20); list.print_list();
	list.insert(0, 30); list.print_list();
	//list.insert_Last(40); list.print_list();
	list.deleteItem(0); list.print_list();

	return 0;
}