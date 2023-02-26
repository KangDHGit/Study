/*
* inline, define
* 공통점: 함수를 대체한다.
* [ inline ]
* inline키워드를 가지는 함수는 호출이 아니고 그대로 복사되어서 코드가 실행된다.
* inline을 잘못 사용하여 컴파일된 코드의 수가 너무 길어지는 대참사가 벌어질 수 있으니
* 짧은 코드를 담고 있는 함수를 빈번하게 사용할 때만 inline
* 데이터 타입을 정의
*
* [ define ]
* 여러번 사용하게 될 상수를 문자로 표현하여 변경시에도 편리하게 사용
* 매크로를 이용하여 함수의 역할을 대신 하는 것
* 데이터 타입을 정의하지 않음
* 매크로 상수(#define MAX_LEN 20)
*/
#include <iostream>

//#define _CONSTEXPR20_CONTAINER inline
using namespace std;

#define Plus(a)(a + a)
#define MUL(a, b) (a * b)
#define MUL_SAFE(a, b) ((a) * (b))

//코드는 짧은 경우, 비번하게 사용되는 경우에만 사용한다.
//문제점: 컴파일된 코드 수가 길어지는 문제 발생
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