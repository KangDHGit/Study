#include<iostream>

using std::cout;
using std::endl;
using std::cin;

class stackType
{
	char* data;		//�����Ҵ��� ���� �����ͷ� ����
	int capacity;	//����ũ��
	int top;
public:
	void delete_stack() { delete[] data; cout << "������ ����" << endl; }
	void init_stack();
	bool resize_stack(int& cap);
	stackType() { init_stack(); };
	bool is_full() const;
	bool is_empty() const;
	void push(char item);
	char pop();
	char peek();
	bool not_oper(char& item) const;
	int eval(const char* exp);
	~stackType() { delete_stack(); }
};
#pragma region stackType define
void stackType::init_stack() {
	if (data != NULL) {
		delete[] data; cout << "���� �����͸� ���� �߽��ϴ�." << endl;
	}
	data = new char[1];
	capacity = 1; top = -1;
	/*cout << "������ �ʱ�ȭ �߽��ϴ�." << endl;*/
}
bool stackType::resize_stack(int& cap) {
	char* new_mem = new char[cap];
	if (new_mem == NULL) { return false; }
	else {
		std::copy(&data[0], &data[top + 1], new_mem);
		delete[] data;
		data = new_mem;
		return true;
	}
}
bool stackType::is_full() const { return (top == capacity - 1); }
bool stackType::is_empty() const { cout << "top : " << top << endl; return (top == -1); }
void stackType::push(char item) {
	if (is_full()) {
		/*cout << "���� ������ �߰�Ȯ�� �մϴ�." << endl;*/
		int cap = capacity * 2;
		if (resize_stack(cap)) {
			/*cout << "���� �߰�Ȯ���� �����߽��ϴ�." << endl;*/
			capacity = cap;
		}
		else { /*cout << "���� �߰�Ȯ���� �����߽��ϴ�." << endl;*/ return; }
	}
	top++;
	data[top] = item;
	/*cout << item << " �߰� ����" << endl;
	cout << "====================" << endl;*/
}
char stackType::pop() {
	if (is_empty()) { cout << "���� ���� ����!" << endl; exit(1); }
	else { return data[top--]; }
}
char stackType::peek() {
	if (is_empty()) { cout << "���� ���� ����!" << endl; exit(1); }
	else { return data[top]; }
}
#pragma endregion

int prec(char op)
{
	switch (op)
	{
	case '(':
	case ')':
		return 0;
	case'+':
	case'-':
		return 1;
	case'*':
	case'/':
	case'%':
		return 2;
	default:
		return -1;
	}
}

void infix_to_postfix(const char exp[])
{
	char ch, top_op;
	int len = strlen(exp);
	stackType stack;

	for (int i = 0; i < len; i++)
	{
		// 1. �ǿ����� �ϰ�� �ٷ���� default
		// 2. ��Ģ�������ϰ�� if(�� �� �����ڶ� ��)
		//	true. �� �� ������ �� ũ�ų� ������ �� �� ������ ���
		//	false. �ƴϸ� ���ÿ� ���� 
		// 3. ���� ��ȣ �ϰ�� ������ ���ÿ� ����
		// 4. �ݴ� ��ȣ �ϰ�� ���� �����ڰ� pop�ɶ����� ���
		ch = exp[i];
		switch (ch)
		{
		case '+':
		case '-':
		case'*':
		case '/':
		case'%':
			while (!stack.is_empty() && prec(stack.peek()) >= prec(ch)) { cout << stack.pop(); break; }
			stack.push(ch); break;
		case'(':
			stack.push(ch);
			break;
		case')':
			top_op = stack.pop();
			while (top_op != '(')
			{
				cout << top_op;
				top_op = stack.pop();
			}
			break;
		default:
			cout << ch;
			break;
		}
	}
	while (!stack.is_empty())
		cout << stack.pop();
	cout << endl;
}

int main()
{
	const char* s = "(2+3)*4+9";
	cout << "����ǥ����� : " << s << endl;
	cout << "����ǥ����� : "; infix_to_postfix(s);
	return 0;
}