#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define MAX 64

int map[MAX][MAX];

void Compress(int n, int y, int x) {
    //������� : ������ ũ�Ⱑ 1�ϰ��
    if (n == 1) {
        cout << map[y][x];
        return;
    }

    //������ ���� �����ͷ� �̷���� �ִ��� �Ǵ��� ����
    bool allIsOne = true;
    bool allIsZero = true;

    for (int c = y; c < y + n; c++)
    {
        for (int r = x; r < x + n; r++) {
            if (map[c][r] == 0)
                allIsOne = false;
            else
                allIsZero = false;

            //������ ���� �����ͷ� �̷���� ���� �������
            if (!allIsOne && !allIsZero)
                break;
        }
        if (!allIsOne && !allIsZero)
            break;
    }

    //���
    //��� ���� �����ͷ� �̷���� �������
    if (allIsZero)
        cout << 0;
    else if (allIsOne)
        cout << 1;
    else {  //�ٸ������ͷ� �̷���� ������� ������ 4���� �����ؼ� ���ȣ��
        cout << "(";
        Compress(n / 2, y, x);                       //2��и�
        Compress(n / 2, y, x + (n / 2));             //1��и�
        Compress(n / 2, y + (n / 2), x);             //3��и�
        Compress(n / 2, y + (n / 2), x + (n / 2));   //4��и�
        cout << ")";
    }

    return;
}

void RevCompress(int n, int y, int x) {
    //������� : ������ ũ�Ⱑ 1�ϰ��
    if (n == 1) {
        cout << map[y][x];
        return;
    }

    //������ ���� �����ͷ� �̷���� �ִ��� �Ǵ��� ����
    bool allIsOne = true;
    bool allIsZero = true;

    for (int c = y; c < y + n; c++)
    {
        for (int r = x; r < x + n; r++) {
            if (map[c][r] == 0)
                allIsOne = false;
            else
                allIsZero = false;

            //������ ���� �����ͷ� �̷���� ���� �������
            if (!allIsOne && !allIsZero)
                break;
        }
        if (!allIsOne && !allIsZero)
            break;
    }

    //���
    //��� ���� �����ͷ� �̷���� �������
    if (allIsZero)
        cout << 0;
    else if (allIsOne)
        cout << 1;
    else {  //�ٸ������ͷ� �̷���� ������� ������ 4���� �����ؼ� ���ȣ��
        cout << "(";
        RevCompress(n / 2, y, x);                       //2��и�
        RevCompress(n / 2, y, x + (n / 2));             //1��и�
        RevCompress(n / 2, y + (n / 2), x);             //3��и�
        RevCompress(n / 2, y + (n / 2), x + (n / 2));   //4��и�
        cout << ")";
    }

    return;
}

int main() {
    //������ ũ��(n X n)
    int n;
    cin >> n;

    //���� n�� ���ڿ� n�� �Է�
    string line;
    for (int c = 0; c < n; c++) {
        cin >> line;

        for (int r = 0; r < n; r++)
            map[c][r] = line[r] - '0';
    }
    
    Compress(n, 0, 0); //(����ũ��, ��������y��ǥ, ��������x��ǥ)
    cout << endl;
    return 0;
}