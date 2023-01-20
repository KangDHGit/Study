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
	LinkedBinaryTree() { headroot == nullptr; }
	void SetHeadRoot(element item);
	TreeNode* GetHeadRoot() { return headroot; }
	static void InsertChild(TreeNode* const parent, element item, bool isleft);
	static void DeleteTree(TreeNode* node);
	static void PreOrder(const TreeNode* node);
	static void InOrder(const TreeNode* node);
	static void PostOrder(const TreeNode* node);
};

void LinkedBinaryTree::SetHeadRoot(element item) {
	if (headroot == nullptr) {
		TreeNode* new_node = new TreeNode{ item, nullptr, nullptr };
		if (new_node == nullptr) { cout << "메모리 할당 에러" << endl; return; }
		headroot = new_node;
	}
	else
		headroot->data = item;
}
void LinkedBinaryTree::InsertChild(TreeNode* const parent, element item, bool isleft) {
	if (parent == nullptr) { cout << "Parent가 NULL 입니다." << endl; return; }
	TreeNode* new_node = new TreeNode{ item, nullptr, nullptr };
	if (new_node == nullptr) { cout << "메모리 할당 에러" << endl; return; }

	if (isleft && parent->l_node == nullptr)
		parent->l_node = new_node;
	else if (!isleft && parent->r_node == nullptr)
		parent->r_node = new_node;
	else
		cout << "자식노드가 포화상태 입니다." << endl;
}

void LinkedBinaryTree::DeleteTree(TreeNode* node) {
	if (node != nullptr) {
		TreeNode* l_node = node->l_node;
		TreeNode* r_node = node->r_node;
		DeleteTree(l_node);
		DeleteTree(r_node);
		cout << node->data << "삭제 ";
		delete node;
	}
}

void LinkedBinaryTree::PreOrder(const TreeNode* node) {
	if (node != nullptr) {
		cout << "[" << node->data << "] ";
		PreOrder(node->l_node);
		PreOrder(node->r_node);
	}
}

void LinkedBinaryTree::InOrder(const TreeNode* node) {
	if (node != nullptr) {
		InOrder(node->l_node);
		cout << "[" << node->data << "] ";
		InOrder(node->r_node);
	}
}

void LinkedBinaryTree::PostOrder(const TreeNode* node) {
	if (node != nullptr) {
		PostOrder(node->l_node);
		PostOrder(node->r_node);
		cout << "[" << node->data << "] ";
	}
}

//		15
//	4		20
//1		 16	   25

int main()
{
	LinkedBinaryTree* tree = new LinkedBinaryTree;
	tree->SetHeadRoot(15);
	LinkedBinaryTree::InsertChild(tree->GetHeadRoot(), 4, true);
	LinkedBinaryTree::InsertChild(tree->GetHeadRoot(), 20, false);
	LinkedBinaryTree::InsertChild(tree->GetHeadRoot()->l_node, 1, true);
	LinkedBinaryTree::InsertChild(tree->GetHeadRoot()->r_node, 16, true);
	LinkedBinaryTree::InsertChild(tree->GetHeadRoot()->r_node, 25, false);
	cout << "전위 순회 = "; LinkedBinaryTree::PreOrder(tree->GetHeadRoot()); cout << endl;
	cout << "중위 순회 = "; LinkedBinaryTree::InOrder(tree->GetHeadRoot()); cout << endl;
	cout << "후위 순회 = "; LinkedBinaryTree::PostOrder(tree->GetHeadRoot()); cout << endl;
	LinkedBinaryTree::DeleteTree(tree->GetHeadRoot()); cout << endl;
	return 0;
}