#include<iostream>

using std::cin;
using std::cout;
using std::endl;

using Vector2 = std::pair<int, int>;


struct Rectangle {
	bool Intersect(Rectangle InRectangle)
	{
		return !(InRectangle.Min.first > Max.first || InRectangle.Min.second > Max.second || InRectangle.Max.first < Min.first || InRectangle.Max.second < Min.second);
	}
	Vector2 Min;
	Vector2 Max;
};

int main() {
	Rectangle r1 = { {0,0},{3,3} };
	Rectangle r2 = { {2,2},{5,5} };
	Rectangle r3 = { {4,4},{6,7} };
	cout << r1.Intersect(r2) << endl;	//1
	cout << r1.Intersect(r3) << endl;	//0
	cout << r2.Intersect(r3) << endl;	//1
}