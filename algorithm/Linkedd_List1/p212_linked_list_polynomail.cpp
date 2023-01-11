#include<iostream>

using std::cout;
using std::endl;
using std::cin;

struct ListNode {
	int coef;	//계수
	int expon;	//지수
	struct ListNode* Link;
	~ListNode() { delete this; }
};

class ListType {
	int size;
public:
	ListNode* head;
	ListNode* tail;
public:
	int GetSize() { return size; }
	ListType() :size(0) { head = NULL; tail = NULL; }
	void Add(const int coef, const int expon) {
		ListNode* new_node = new ListNode{ coef, expon, NULL };
		if (new_node == NULL) { cout << "메모리 할당 에러" << endl; return; }

		if (head == NULL) { head = new_node; tail = new_node; }
		else {
			tail->Link = new_node;
			tail = tail->Link;
		}
		size++;
	}
	~ListType() { delete this; }
};

class PolyCal {
public:
	static int CompareExpon(const ListNode* iterA, const ListNode* iterB) {
		if (iterA->expon > iterB->expon)
			return 1;
		if (iterA->expon == iterB->expon)
			return 0;
		if (iterA->expon < iterB->expon)
			return -1;
	}

	static ListType* Poly_add(ListType* polyA, ListType* polyB) {
		ListNode* iterA = polyA->head;
		ListNode* iterB = polyB->head;
		ListType* resultList = new ListType;

		while (iterA != NULL && iterB != NULL)
		{
			switch (CompareExpon(iterA, iterB))
			{
			case 1:	//A의 지수가 B의 지수보다 클때
				resultList->Add(iterA->coef, iterA->expon);
				iterA = iterA->Link;
				break;
			case 0: //A와 B의 지수가 같을때
			{
				int sumCoef = iterA->coef + iterB->coef;
				if (sumCoef == 0) break;
				else {
					resultList->Add(sumCoef, iterA->expon);
					iterA = iterA->Link;
					iterB = iterB->Link;
					break;
				}
				break;
			}
			case -1: //A의 지수가 B의 지수보다 작을때
				resultList->Add(iterB->coef, iterB->expon);
				iterB = iterB->Link;
				break;
			default:
				cout << "비정상적인 비교 값입니다." << endl;
				break;
			}
		}

		while (iterA != NULL)
		{
			resultList->Add(iterA->coef, iterA->expon);
			iterA = iterA->Link;
		}

		while (iterB != NULL)
		{
			resultList->Add(iterB->coef, iterB->expon);
			iterB = iterB->Link;
		}

		return resultList;
	}

	static void Print_poly(const ListType* poly) {
		ListNode* iter = poly->head;
		cout << "polynomial :";
		while (iter != NULL)
		{
			char oper = iter->coef > 0 ? '+' : '-';
			cout.width(2); cout << oper;
			cout << abs(iter->coef) << "^" << iter->expon;
			iter = iter->Link;
		}
		cout << endl;
	}
};

int main()
{
	ListType* listA = new ListType , * listB = new ListType, * listC = new ListType;

	listA->Add(3, 12);
	listA->Add(2, 8);
	listA->Add(1, 0);

	listB->Add(8, 12);
	listB->Add(-3, 10);
	listB->Add(-5, 8);
	listB->Add(10, 6);

	PolyCal::Print_poly(listA);
	PolyCal::Print_poly(listB);

	listC = PolyCal::Poly_add(listA, listB);
	PolyCal::Print_poly(listC);
	
	return 0;
}