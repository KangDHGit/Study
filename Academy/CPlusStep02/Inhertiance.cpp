#include <iostream>

/*
* »ó¼Ó..
* public, private, protected
*
*/

class Base
{
private:
    int PrivateNum;
    void PrivateBasePrint()
    {

    }

protected:
    int ProtectedNum;
    void BasePrint()
    {

    }

public:
    int PublicNum;
    void PublicBasePrint()
    {

    }
};

class Child : public Base
{
public:
    void Print()
    {
        BasePrint();
        PublicBasePrint();

        std::cout << ProtectedNum << std::endl;
        std::cout << PublicNum << std::endl;
    }
};

int main()
{
    Child c1;
    Child c2;

    c1.PublicNum = 10;
    c2.PublicNum = 10;

    c1.Print();
    c2.Print();

    c1.PublicBasePrint();

    return 0;
}