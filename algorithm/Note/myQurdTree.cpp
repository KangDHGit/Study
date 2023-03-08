#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define MAX 64

int map[MAX][MAX];

void Compress(int n, int y, int x) {
    //기저사례 : 영역의 크기가 1일경우
    if (n == 1) {
        cout << map[y][x];
        return;
    }

    //영역이 같은 데이터로 이루어져 있는지 판단할 변수
    bool allIsOne = true;
    bool allIsZero = true;

    for (int c = y; c < y + n; c++)
    {
        for (int r = x; r < x + n; r++) {
            if (map[c][r] == 0)
                allIsOne = false;
            else
                allIsZero = false;

            //영역이 같은 데이터로 이루어져 있지 않을경우
            if (!allIsOne && !allIsZero)
                break;
        }
        if (!allIsOne && !allIsZero)
            break;
    }

    //출력
    //모두 같은 데이터로 이루어져 있을경우
    if (allIsZero)
        cout << 0;
    else if (allIsOne)
        cout << 1;
    else {  //다른데이터로 이루어져 있을경우 공간을 4개로 분할해서 재귀호출
        cout << "(";
        Compress(n / 2, y, x);                       //2사분면
        Compress(n / 2, y, x + (n / 2));             //1사분면
        Compress(n / 2, y + (n / 2), x);             //3사분면
        Compress(n / 2, y + (n / 2), x + (n / 2));   //4사분면
        cout << ")";
    }

    return;
}

void RevCompress(int n, int y, int x) {
    //기저사례 : 영역의 크기가 1일경우
    if (n == 1) {
        cout << map[y][x];
        return;
    }

    //영역이 같은 데이터로 이루어져 있는지 판단할 변수
    bool allIsOne = true;
    bool allIsZero = true;

    for (int c = y; c < y + n; c++)
    {
        for (int r = x; r < x + n; r++) {
            if (map[c][r] == 0)
                allIsOne = false;
            else
                allIsZero = false;

            //영역이 같은 데이터로 이루어져 있지 않을경우
            if (!allIsOne && !allIsZero)
                break;
        }
        if (!allIsOne && !allIsZero)
            break;
    }

    //출력
    //모두 같은 데이터로 이루어져 있을경우
    if (allIsZero)
        cout << 0;
    else if (allIsOne)
        cout << 1;
    else {  //다른데이터로 이루어져 있을경우 공간을 4개로 분할해서 재귀호출
        cout << "(";
        RevCompress(n / 2, y, x);                       //2사분면
        RevCompress(n / 2, y, x + (n / 2));             //1사분면
        RevCompress(n / 2, y + (n / 2), x);             //3사분면
        RevCompress(n / 2, y + (n / 2), x + (n / 2));   //4사분면
        cout << ")";
    }

    return;
}

int main() {
    //영상의 크기(n X n)
    int n;
    cin >> n;

    //길이 n의 문자열 n개 입력
    string line;
    for (int c = 0; c < n; c++) {
        cin >> line;

        for (int r = 0; r < n; r++)
            map[c][r] = line[r] - '0';
    }
    
    Compress(n, 0, 0); //(영역크기, 영역시작y좌표, 영역시작x좌표)
    cout << endl;
    return 0;
}