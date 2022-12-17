#include<iostream>
//#include<string>
#include<vector>

using namespace std;

int main()
{
	vector<int> x;
	x.push_back(1);
	x.push_back(2);
	for (size_t i = 0; i < x.size(); i++)
	{
		cout << x[i] << ", ";
	}
	cout << endl;

	string str = "¾È³ç!";
	str.push_back('H');
	str.push_back('i');

	cout << str << endl;
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
	}
	cout << endl;
	return 0;
}