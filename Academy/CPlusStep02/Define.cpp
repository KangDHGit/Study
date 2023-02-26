/*
* inline, define
* ������: �Լ��� ��ü�Ѵ�.
* [ inline ]
* inlineŰ���带 ������ �Լ��� ȣ���� �ƴϰ� �״�� ����Ǿ �ڵ尡 ����ȴ�.
* inline�� �߸� ����Ͽ� �����ϵ� �ڵ��� ���� �ʹ� ������� �����簡 ������ �� ������
* ª�� �ڵ带 ��� �ִ� �Լ��� ����ϰ� ����� ���� inline
* ������ Ÿ���� ����
*
* [ define ]
* ������ ����ϰ� �� ����� ���ڷ� ǥ���Ͽ� ����ÿ��� ���ϰ� ���
* ��ũ�θ� �̿��Ͽ� �Լ��� ������ ��� �ϴ� ��
* ������ Ÿ���� �������� ����
* ��ũ�� ���(#define MAX_LEN 20)
*/
#include <iostream>

//#define _CONSTEXPR20_CONTAINER inline
using namespace std;

#define Plus(a)(a + a)
#define MUL(a, b) (a * b)
#define MUL_SAFE(a, b) ((a) * (b))

//�ڵ�� ª�� ���, ����ϰ� ���Ǵ� ��쿡�� ����Ѵ�.
//������: �����ϵ� �ڵ� ���� ������� ���� �߻�
inline int Add(int a)
{
    return a + a;
}

int main()
{
    cout << Add(10) << endl;
    cout << Plus(10) << endl;
    cout << Plus(10.2f) << endl;

    //10 + 10 * 20 + 10 //10 + (10 * 20) + 10 
    std::cout << "MUL: " << MUL(10 + 10, 20 + 10) << std::endl;
    //(10 + 10) * (20 + 10)
    std::cout << "MUL: " << MUL_SAFE(10 + 10, 20 + 10) << std::endl;

    return 0;
}