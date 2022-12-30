#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

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
	else {
		std::copy(&data[0], &data[top + 1], new_mem);	//�Ҵ�� ������ ���������� ����
		delete[] data;									//���������� ����
		data = new_mem;									//���ο� �����̶� �ּ� ����
		return true;
	}
}
bool stackType::is_full()const { if (top == capacity - 1) return true; else return false; }
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
	cout << (int)item << " �߰� ����" << endl;
	cout << "====================" << endl;
}
char stackType::pop()
{
	if (is_empty()) { cout << "���� ���� ����! �ǿ����ڰ� �������� �ʽ��ϴ�." << endl; exit(1); }
	else { return data[top--]; }
}
char stackType::peek()
{
	if (is_empty()) { cout << "���� ���� ����! �ǿ����ڰ� �������� �ʽ��ϴ�." << endl; exit(1); }
	else { return data[top]; }
}
bool stackType::not_oper(char& item) const
{
	return item != '+' && item != '-' && item != '*' && item != '/' && item != '%';
}
int stackType::eval(const char* exp)
{
	int op1, op2;				//����Ҷ� ����� �ǿ����� ����
	int value = 0;				//�ǿ����� �ϰ�� ���ÿ� ������ ����
	int len = strlen(exp);		//���ڹ迭 exp�� ����
	char ch;					//exp���� �ϳ��� ���ڸ� ���� ����;

	for (int i = 0; i < len; i++)
	{
		ch = exp[i];
		if (not_oper(ch))		//�����ڰ� �ƴҰ��(�ǿ����� �ϰ��)
		{
			value = ch - '0';	//���ڸ� ���ڷ� ��ȯ(�ƽ�Ű �ڵ�)
			push(value);		//���ÿ� ����
		}
		else
		{
			op2 = pop(); op1 = pop();		//���߿� ����� �ǿ����ں��� �����´�.
			cout << "������ ����! : " << op1 << ' ' << ch << ' ' << op2 << endl;
			switch (ch)
			{
			case'+':
				value = op1 + op2; push(value);	//����� �ٽ� ���ÿ� ����
				break;
			case'-':
				value = op1 - op2; push(value);
				break;
			case'*':
				value = op1 * op2; push(value);
				break;
			case'/':
				value = op1 / op2; push(value);
				break;
			case'%':
				value = op1 % op2; push(value);
				break;
			}
		}
	}
	return pop();
}
#pragma endregion

int main()
{
	stackType stack;
	int result;
	cout << "(8 / 2) - 3 + (3 * 2)" << endl;
	cout << "����ǥ����� 82/3-32*+" << endl;
	result = stack.eval("82/3-32*+");
	cout << "����� : " << result << endl;
}