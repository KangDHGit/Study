#include<iostream>

using std::cout;
using std::endl;
using std::cin;

typedef int element;

class ArrayListType {
	const static int MAX_LIST_SIZE = 100;
	element array[MAX_LIST_SIZE];
	int size;

public:
	void error(const char* messege) {
		cout << messege << endl; exit(1); }

	void init() { size = 0; }
	bool is_empty() { return size == 0; }
	bool is_full() { return size == MAX_LIST_SIZE; }
	element get_entry(int index) {
		if (index < 0 || index > MAX_LIST_SIZE)
			error("위치 입력오류");
		else
			return array[index];
	}
};

int main()
{
	return 0;
}