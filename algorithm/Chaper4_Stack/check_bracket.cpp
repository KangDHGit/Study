#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using std::cout;
using std::endl;
using std::cin;

class stackType
{
	char* data;	//�����Ҵ��� ���� �����ͷ� ����
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
	bool close_bracket_check(char& open, char& close) const;
	bool check_matching(const char* in);
	~stackType() { delete_stack(); }
};

#pragma region stackType define
void stackType::init_stack() 
{
	if (data != NULL)
	{
		delete[] data;
		cout << "���� �����͸� �����߽��ϴ�" << endl;
	}
	data = new char[1];
	capacity = 1; top = -1;
	cout << "������ �ʱ�ȭ �߽��ϴ�" << endl;
}
bool stackType::resize_stack(int& cap)
{
	char* new_mem = new char[cap];						//���ο� ���� �Ҵ�
	if (new_mem == NULL) return false;					//�Ҵ�� ������ NULL���� Ȯ��
	else{												
		std::copy(&data[0], &data[top + 1], new_mem);	//�Ҵ�� ������ ���������� ����
		delete[] data;									//���������� ����
		data = new_mem;									//���ο� �����̶� �ּ� ����
		return true;
	}
}
bool stackType::is_full() const { if (top == capacity - 1) return true; else return false; }
bool stackType::is_empty() const { if (top == -1) return true; else return false; }
void stackType::push(char item)
{
	if (is_full())
	{
		cout << "���� ������ �߰� Ȯ�� �մϴ�." << endl;
		int cap = capacity * 2;
		if (resize_stack(cap))
		{
			cout << "���� �߰�Ȯ���� �����߽��ϴ�." << endl;
			capacity = cap;
		}
		else { cout << "���� �߰�Ȯ���� �����߽��ϴ�." << endl; return; }
	}
	top++;
	data[top] = item;
	cout << item << " �߰� ����" << endl;
	cout << "====================" << endl;
}
char stackType::pop()
{
	if (is_empty()) { cout << "���� ���鿡��" << endl; delete_stack(); exit(1); }
	else { return data[top--]; }
}
char stackType::peek()
{
	if (is_empty()) { cout << "���� ���鿡��" << endl; delete_stack(); exit(1); }
	else { return data[top]; }
}

bool stackType::close_bracket_check(char& open, char& close) const
{
	switch (open)
	{
	case '(':
		if (close == ')') return true;
	case '{':
		if (close == '}') return true;
	case'[':
		if (close == ']') return true;
	default:
		return false;
	}
}

bool stackType::check_matching(const char* in)
{
	int length = strlen(in);
	for (int i = 0; i < length; i++)
	{
		char chr = in[i];
		switch (chr)
		{
		case '(':
		case '{':
		case '[':
			push(chr); break;	//���� ��ȣ�ϰ�� ���ÿ� ����
		case ')':
		case '}':
		case ']':				//�ݴ� ��ȣ�ϰ�� �ֱ� ���� Ȯ��
		{
			cout << chr << " �ݴ� ��ȣ �Է� Ȯ��" << endl;
			char open_bracket = pop();
			if (!close_bracket_check(open_bracket, chr))
			{
				cout << "���� ��ȣ�� ������ ���� �ʰų� �������� �ʽ��ϴ�." << endl;
				return false;	//�ٸ���� false
			}
			cout << open_bracket << chr << "Ȯ��" << endl;;
		}
		default:
			break;
		}
	}
	//������ ���������� ����, �� ���� �ݴ� ��ȣ ������ �ȸ´� ���
	if (!is_empty()) { cout << "���� �ݴ� ��ȣ�� ������ ���� �ʽ��ϴ�." << endl; return false; }
	return true; // �� ������ �� ����ϸ� ����
}
#pragma endregion

int main()
{
	stackType bracket_stack;
	const char* p = "{ A[(i+1)] = 0; }";
	cout << "=====��ȣ�˻� ����=====" << endl;
	if (bracket_stack.check_matching(p))
		cout << "��ȣ�˻� ����" << endl;
	else
		cout << "��ȣ�˻� ����" << endl;
	cout << "=====��ȣ�˻� ����=====" << endl;
	
	return 0;
}