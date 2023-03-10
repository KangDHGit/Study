#include<iostream>

using std::cout;
using std::endl;
using std::cin;

typedef int Data;

class ArrayListType {
	const static int MAX_LIST_SIZE = 100;
	Data arr[MAX_LIST_SIZE];
	int size;

public:
	void error(const char* messege) {
		cout << messege << endl; exit(1); }
	void init() { size = 0; }
	ArrayListType() { init(); }
	bool is_empty() { return size == 0; }
	bool is_full() { return size == MAX_LIST_SIZE; }
	Data get_entry(int index);
	void print_list();
	void insert_Last(Data item);
	void insert(int index, Data item);
	Data deleteItem(int index);
};

#pragma region ArrayListType_Define
//해당 인덱스 자료 가져오기
Data ArrayListType::get_entry(int index) {
	if (index < 0 || index > MAX_LIST_SIZE)
		error("위치 입력오류");
	else
		return arr[index];
}
void ArrayListType::print_list() {
	for (int i = 0; i < size; i++)
		cout << arr[i] << "->";
	cout << endl;
}
void ArrayListType::insert_Last(Data item) {
	if (size >= MAX_LIST_SIZE)
		error("리스트 오버플로우");
	arr[size] = item; size++;
}
void ArrayListType::insert(int index, Data item) {
	if (!is_full() && index >= 0 && index <= size) {	//2 3 4, 0 1 3 4 
		for (int i = size - 1; i >= index; i--)
			arr[i + 1] = arr[i];
		arr[index] = item;
		size++;
	}
}

Data ArrayListType::deleteItem(int index) {
	Data result;
	if (index >= 0 && index < size) {
		Data result = arr[index];
		for (int i = index; i < size - 1; i++) // 3, 0 1 2 3 4 , 0 1 2 4
			arr[i] = arr[i + 1];
		size--;
		return result;
	}
	else
		error("위치 입력오류");
}
#pragma endregion


int main()
{
	ArrayListType list;
	list.insert(0, 10); list.print_list();
	list.insert(0, 20); list.print_list();
	list.insert(0, 30); list.print_list();
	list.insert_Last(40); list.print_list();
	list.deleteItem(0); list.print_list();

	return 0;
}