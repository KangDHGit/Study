#include <iostream>

class AA
{
private:
    int numPrivate;
public:
    int numPublic;

public:
    void SetNum(int num)
    {
        numPrivate = num;
    }

    int GetNum()
    {
        return numPrivate;
    }
};

class Actor
{
public:
    void BeginPlay()
    {

    }
};

int main()
{
    //int num;
    AA aa;

    aa.SetNum(10);
    std::cout << aa.GetNum();

    Actor actor;
    actor.BeginPlay();

    //int* ptrNum;
    Actor* ptrActor;
    //(*ptrActor).BeginPlay();
    ptrActor->BeginPlay();

    return 0;
}