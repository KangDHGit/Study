#include<iostream>

using std::cout;
using std::endl;
using std::cin;

typedef int element;

struct TreeNode {
	element data;
	TreeNode* l_node;
	TreeNode* r_node;
};

class LinkedBinaryTree {
	TreeNode* headroot;
public:
	TreeNode* GetHeadRoot() { return headroot; }
	LinkedBinaryTree() { headroot = nullptr; }
	void SetHeadRoot(element item);
	static void InsertChild(TreeNode* const parent, element item);
	static void DeleteChild(TreeNode* const parent);
	static element GetChildData(const TreeNode* parent, bool isleft) {
		if (parent == nullptr) { cout << "Parent가 NULL 입니다." << endl; return -9999; }
		TreeNode* result = isleft ? parent->l_node : parent->r_node;
		return result != nullptr ? result->data : -9999;
	}
	~LinkedBinaryTree() { delete headroot; cout << "Headroot Delete Complete" << endl; }
};

void LinkedBinaryTree::SetHeadRoot(element item) {
	TreeNode* new_node = new TreeNode{ item, nullptr, nullptr };
	if (new_node == nullptr) { cout << "메모리 할당 에러" << endl; return; }
	headroot = new_node;
}

void LinkedBinaryTree::InsertChild(TreeNode* const parent, element item) {
	if (parent == nullptr) { cout << "Parent가 NULL 입니다." << endl; return; }
	TreeNode* new_node = new TreeNode{ item, nullptr, nullptr };
	if (new_node == nullptr) { cout << "메모리 할당 에러" << endl; return; }

	if (parent->l_node == nullptr)
		parent->l_node = new_node;
	else if (parent->r_node == nullptr)
		parent->r_node = new_node;
	else {
		cout << "자식노드가 포화상태 입니다." << endl; delete new_node;
	}
}

void LinkedBinaryTree::DeleteChild(TreeNode* const parent) {
	if (parent == nullptr) { cout << "Parent가 NULL 입니다." << endl; return; }
	delete parent->l_node; parent->l_node = nullptr;
	delete parent->r_node; parent->r_node = nullptr;
	cout << "Child Delete Complete" << endl;
}

int main()
{
	LinkedBinaryTree* tree = new LinkedBinaryTree;
	tree->SetHeadRoot(10);
	LinkedBinaryTree::InsertChild(tree->GetHeadRoot(), 20);
	LinkedBinaryTree::InsertChild(tree->GetHeadRoot(), 30);
	cout << tree->GetHeadRoot()->data << endl;
	cout << LinkedBinaryTree::GetChildData(tree->GetHeadRoot(), true) << " " << LinkedBinaryTree::GetChildData(tree->GetHeadRoot(), false) << endl;
	LinkedBinaryTree::DeleteChild(tree->GetHeadRoot());
	delete tree;
	return 0;
}