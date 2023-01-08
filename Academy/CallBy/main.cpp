#include<iostream>

using std::cout;
using std::endl;
using std::cin;

//CallByValue : 값 호출
//CallByReference : 주소(참조) 호출

void SwapValue(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
void SwapRef(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void SwapPoint(int* const aPtr, int* const bPtr) {
	int temp = *aPtr;
	*aPtr = *bPtr;
	*bPtr = temp;
}


int main()
{
	int num1 = 0;
	int num2 = 9999;

	cout << "Before Swap num1 :	" << num1 << " num2 : " << num2 << endl;
	SwapValue(num1, num2);
	cout << "After Swap num1 :	" << num1 << " num2 : " << num2 << endl;

	cout << "Before Swap num1 :	" << num1 << " num2 : " << num2 << endl;
	SwapRef(num1, num2);
	cout << "After Swap num1 :	" << num1 << " num2 : " << num2 << endl;

	cout << "Before Swap num1 :	" << num1 << " num2 : " << num2 << endl;
	SwapPoint(&num1, &num2); //인자만 보고도 참조로 넘기는지 알 수 있다.
	cout << "After Swap num1 :	" << num1 << " num2 : " << num2 << endl;

	return 0;
}