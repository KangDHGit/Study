#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>

using std::cin;
using std::cout;
using std::endl;;
using std::string;

int main() {
	std::vector<int> vec{ 1, 2, 3 };

	//�ݺ����� �⺻ ����
	//std::vector<int>::iterator it;
	
	//for���� �ݺ���
	//for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
	//	cout << *it << endl;	//�����Ϳ� ���������� �������� ���
	//}

	//���� �����̳��� �ݺ����� ȿ������ ���� �� �ʱ�ȭ ����
	//for (auto it = vec.begin(); it != vec.end(); it++) {
	//	cout << *it << endl;	//�����Ϳ� ���������� �������� ���
	//}

	//������ó�� �ѹ��� ������ �ּ��̵�����
	/*auto it = vec.begin();
	it += 2;
	cout << *it << endl;*/

	//�߻�ȭ : ������ ������ ������� ��� ����
	/*std::set<char> st{ 'A', 'B', 'D'};
	for (auto it = st.begin(); it != st.end(); it++)
		cout << *it << endl;*/

	//���ݺ���
	//vec.rbegin() : ������ ���, vec.rend() : ù��� ��

	//const �ݺ���
	//�� �ݺ��ڸ� ���ؼ� ���� �ٲ��� �ʰڴ�.
	//�Ʒ�ó�� �������ؼ� �����̳ʿ� �����͸� �ٲ� �� ����.
	/*for (auto it = vec.cbegin(); it != vec.end(); it++)
		*it = 2;*/
}