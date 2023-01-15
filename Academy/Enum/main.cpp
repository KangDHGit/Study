/*
* 열거형(enum)
*/
#include <iostream>

enum State
{
    NONE,    //
    INIT,    //
    PLAY,    //
    FINISH,    //
    END,    //
};

void Init(int* state);
void Play(int* state);
void Finish(int* state);

void InitState(State* state);
void PlayState(State* state);
void FinishState(State* state);

int main()
{
    //0번: Init, 1번: Play, 2번: Finish
    int state = 0;
    State curState = State::INIT;

    while (true)
    {
        switch (state)
        {
        case 0:
            Init(&state);
            break;
        case 1:
            Play(&state);
            break;
        case 2:
            Finish(&state);
            break;
        default:
            break;
        }

        if (state > 2)
        {
            break;
        }
    }

    while (true)
    {
        switch (curState)
        {
        case INIT:
            InitState(&curState);
            break;
        case PLAY:
            PlayState(&curState);
            break;
        case FINISH:
            FinishState(&curState);
            break;

        case END:
        case NONE:
        default:
            break;
        }

        if (curState == State::END)
        {
            break;
        }
    }

    return 0;
}

void Init(int* state)
{
    std::cout << "Init() " << std::endl;
    *state = 1;
}

void Play(int* state)
{
    std::cout << "Play() " << std::endl;
    *state = 2;
}

void Finish(int* state)
{
    std::cout << "Finish() " << std::endl;
    *state = 3;
}

void InitState(State* state)
{
    std::cout << "InitState() " << std::endl;
    *state = State::PLAY;
}

void PlayState(State* state)
{
    std::cout << "PlayState() " << std::endl;
    *state = State::FINISH;
}

void FinishState(State* state)
{
    std::cout << "FinishState() " << std::endl;
    *state = State::END;
}