#include<iostream>
#include<list>
#include<forward_list>
#include<algorithm>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	std::list<int> lst{ 1,2,3,4,5 };
	auto it = std::find(lst.begin(), lst.end(), 3);

	lst.insert(it, 10);	//1,2,10,3,4,5
	std::for_each(lst.begin(), lst.end(), [](int x) {cout << x << " "; });
	cout << endl;
	lst.erase(it);		//1,2,10,4,5
	std::for_each(lst.begin(), lst.end(), [](int x) {cout << x << " "; });
	cout << endl;
	
	return 0;
}