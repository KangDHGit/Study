#include<iostream>

using std::cout;
using std::endl;
using std::cin;

//Alt + Enter(���̵� ����)
//�Ķ����(X), ���ϰ�(X)
//�Ķ����(X), ���ϰ�(O)
//�Ķ����(O), ���ϰ�(X)
//�Ķ����(O), ���ϰ�(O)

//�Ķ����(X), ���ϰ�(X)
void PrintData();

//�Ķ����(X), ���ϰ�(O)
int GetMax();

//�Ķ����(O), ���ϰ�(X)
void Add(int a, int b);

//�Ķ����(O), ���ϰ�(O)
int Sum(int a, int b, int c);

int main()
{
    PrintData();

    int getMax = GetMax();
    std::cout << "getMax: " << getMax << std::endl;

    Add(10, 20);

    int total = Sum(10, 20, 30);
    std::cout << "total: " << total << std::endl;

    return 0;
}

void PrintData()
{
    std::cout << "==========" << std::endl;
    std::cout << "Method" << std::endl;
    std::cout << "==========" << std::endl;
}

int GetMax()
{
    int max = INT_MAX;
    return max;
}

void Add(int a, int b)
{
    int sum = a + b;
    std::cout << "sum: " << sum << std::endl;
}

int Sum(int a, int b, int c)
{
    int sum = a + b + c;
    return sum;
}