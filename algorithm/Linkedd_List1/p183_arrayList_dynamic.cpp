#include<iostream>

using std::cout;
using std::endl;
using std::cin;

typedef int Data;

class ArrayListType {
	Data* arr;						//��������
	int capacity;
	int size;
public:
	void error(const char* messege) {
		cout << messege << endl; exit(1);
	}
	void init();
	ArrayListType() { init(); }
	bool is_empty() { return size == 0; }
	bool is_full() { return size >= capacity; }
	bool is_indexOver(int index) { return (index < 0 || index > size); }
	bool resize(int cap);					//��������
	void print_list();
	void insert_first(Data item);		//��������
	void insert_last(Data item);
	void insert(int index, Data item);
	Data get_entry(int index);
	Data deleteItem(int index);
	void clear();							//����(�����͸� ����, size�ʱ�ȭ, capacity�� �״��)
	void replace(int indexA, int indexB);	//���� A�� B ��ȯ
	int get_length() { return size; }		//����
	~ArrayListType() { delete[] arr; }
};

#pragma region ArrayListType_define
void ArrayListType::init() {
	if (arr != NULL) { delete[] arr; cout << "���� ����Ʈ�� ���� �߽��ϴ�." << endl; }
	arr = new Data[1];
	if (arr == NULL) { cout << "����Ʈ �ʱ�ȭ�� �ʿ��� �޸𸮸� �Ҵ���� ���߽��ϴ�." << endl;}
	else {
		size = 0; capacity = 1;
		cout << "����Ʈ�� �ʱ�ȭ �߽��ϴ�." << endl;
	}
}
bool ArrayListType::resize(int cap) {
	Data* new_mem = new Data[cap];
	if (new_mem == NULL) { cout << "����Ʈ Ȯ�忡 �ʿ��� �޸𸮸� �Ҵ���� ���߽��ϴ�." << endl; return false; }
	else {
		std::copy(&arr[0], &arr[size], new_mem);
		delete[] arr;
		arr = new_mem;
		return true;
	}
}
void ArrayListType::print_list() {
	for (int i = 0; i < size; i++)
		cout << arr[i] << "->";
	cout << endl;
}
void ArrayListType::insert_first(Data item) {
	if (is_full()) {
		int new_cap = capacity * 2;
		if (resize(new_cap)) {
			capacity = new_cap;
			cout << "����Ʈ Ȯ�忡 �����߽��ϴ�." << endl;
			cout << "copyȮ�� : "; print_list();
		}
		else
			return;
	}
	for (int i = size; i > 0; i--)
		arr[i] = arr[i - 1];
	arr[0] = item; size++;
}
void ArrayListType::insert_last(Data item) {
	if (is_full()) {
		int new_cap = capacity * 2;
		if (resize(new_cap)) {
			capacity = new_cap;
			cout << "����Ʈ Ȯ�忡 �����߽��ϴ�." << endl;
			cout << "copyȮ�� : "; print_list();
		}
		else
			return;
	}
	arr[size] = item; size++;
}
void ArrayListType::insert(int index, Data item) {
	if (is_indexOver(index)) {
		cout << "�߸��� �ε��� ���Դϴ�." << endl; return;
	}
	if (is_full()) {
		int new_cap = capacity * 2;
		if (resize(new_cap)) {
			capacity = new_cap;
			cout << "����Ʈ Ȯ�忡 �����߽��ϴ�." << endl;
			cout << "copyȮ�� : "; print_list();
		}
		else
			return;
	}
	for (int i = size; i > index; i--)
		arr[i] = arr[i - 1];
	arr[index] = item; size++;
}
Data ArrayListType::get_entry(int index) {
	if (is_indexOver(index)) {
		cout << "�߸��� �ε��� ���Դϴ�." << endl; return Data{ 0 };
	}
	return arr[index];
}
Data ArrayListType::deleteItem(int index) {
	if (is_indexOver(index)) {
		cout << "�߸��� �ε��� ���Դϴ�." << endl; return Data{ 0 };
	}
	Data result = arr[index];
	for (int i = index; i < size; i++)
		arr[i] = arr[i + 1];
	size--;
	return result;
}
void ArrayListType::clear() {
	Data* new_mem = new Data[capacity];
	if (new_mem == NULL) {
		cout << "clear�� �ʿ��� �޸𸮸� �Ҵ���� ���߽��ϴ�." << endl; return;
	}
	else{
		delete[] arr;
		arr = new_mem; size = 0;
	}
}
void ArrayListType::replace(int indexA, int indexB) {
	bool aCheck = is_indexOver(indexA);
	bool bCheck = is_indexOver(indexB);
	if (aCheck || bCheck) {
		cout << "�߸��� �ε��� ���Դϴ�." << endl; return;
	}
	int temp = *(arr + indexA);
	*(arr + indexA) = *(arr + indexB);
	*(arr + indexB) = temp;
}
#pragma endregion

int main()
{
	ArrayListType list;
	list.insert(0, 10); list.print_list();		//10
	list.insert(0, 20); list.print_list();		//20 10
	list.insert(0, 30); list.print_list();		//30 20 10
	list.insert_last(40); list.print_list();	//30 20 10 40
	list.insert_first(50); list.print_list();	//50 30 20 10 40
	list.deleteItem(0); list.print_list();		//30 20 10 40
	list.deleteItem(2); list.print_list();		//30 20 40
	list.replace(1, 2); list.print_list();		//30 40 20
	int a;
	return 0;
}