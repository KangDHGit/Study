#include <iostream>

namespace AA
{
    void Print()
    {

    }
}

namespace MyStd
{
    void cout(const char* str)
    {
        std::cout << str << std::endl;
    }
}

using std::cout;
using std::endl;

//using namespace std;

int main()
{
    AA::Print();

    cout << "Hello" << endl;

    MyStd::cout("Hello World");

    return 0;
}