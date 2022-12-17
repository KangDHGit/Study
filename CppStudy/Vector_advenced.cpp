#include<iostream>
#include<vector>
#include<algorithm> // sort
#include<functional> // 함수자, less<>, greater<>

using namespace std;

int main()
{
	vector<int> v(5); // vector container
	cout << v.size() << " : " << v.capacity() << endl; // 5 : 5
	for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
	// capacity는 할당된 메모리 공간의 크기, size는 저장된 데이터 요소의 개수
	cout << endl;
	for (size_t i = 0; i < v.size(); i++) v[i] = i + 1;
	for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
	cout << endl;

	for (int i = 0; i < 5; i++)	v.push_back(10 - i);
	vector<int>::iterator iter; // iterator
	for (iter = v.begin(); iter != v.end(); iter++) cout << *iter << ' ';
	sort(v.begin(), v.end()); cout << endl; // algorithm
	for (iter = v.begin(); iter != v.end(); iter++) cout << *iter << ' ';
	cout << endl;

	sort(v.begin(), v.end(), greater<int>()); //functor
	for (iter = v.begin(); iter != v.end(); iter++) cout << *iter << ' ';
	cout << endl;
	
	return 0;
}