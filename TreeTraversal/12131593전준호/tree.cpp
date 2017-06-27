#include <iostream>
using namespace std;

class Node {
public:
	Node() {
		element = 0;
		leftEle = NULL;
		rightEle = NULL;
	}
private:
	friend class BST;
	
	int element;
	Node* leftEle;
	Node* rightEle;
};

class BST {
public :
	BST();
	void insertNode(Node* node = NULL, int ele = 0);

	//print
	void inOrder(Node* node);
	void preOrder(Node* node);
	void postOrder(Node* node);
	void descendOrder(Node* node);
	
	Node* tree;
};

BST::BST() {
	tree = NULL;
}

void BST::insertNode(Node* node, int ele) {
	if (node == NULL) {
		tree = new Node;
		tree->element = ele;
	}
	else {
		if (node->element > ele) {
			if (node->leftEle == NULL) {
				node->leftEle = new Node;
				node->leftEle->element = ele;
			}
			else {
				insertNode(node->leftEle, ele);
			}
		}
		else if (node->element < ele) {
			if (node->rightEle == NULL) {
				node->rightEle = new Node;
				node->rightEle->element = ele;
			}
			else {
				insertNode(node->rightEle, ele);
			}
		}
	}
}

void BST::inOrder(Node* node) {
	if (NULL == node) {
		return;
	}

	if (NULL != node->leftEle) {
		this->inOrder(node->leftEle);
	}
	cout << node->element << " ";
	if (NULL != node->rightEle) {
		this->inOrder(node->rightEle);
	}
}

void BST::preOrder(Node* node) {
	if (NULL == node) {
		return;
	}

	cout << node->element << " ";
	this->preOrder(node->leftEle);
	this->preOrder(node->rightEle);
}

void BST::postOrder(Node* node) {
	if (NULL == node) {
		return;
	}

	if (NULL != node->leftEle) {
		this->postOrder(node->leftEle);
	}
	if (NULL != node->rightEle) {
		this->postOrder(node->rightEle);
	}
	cout << node->element << " ";
}

void BST::descendOrder(Node* node) {
	if (NULL == node) {
		return;	
	}
	this->descendOrder(node->rightEle);
	cout << node->element << " ";
	this->descendOrder(node->leftEle);
}

int main() {
	BST bst;
	
	bst.insertNode(bst.tree, 15);
	bst.insertNode(bst.tree, 5);
	bst.insertNode(bst.tree, 16);
	bst.insertNode(bst.tree, 3);
	bst.insertNode(bst.tree, 12);
	bst.insertNode(bst.tree, 20);
	bst.insertNode(bst.tree, 10);
	bst.insertNode(bst.tree, 13);
	bst.insertNode(bst.tree, 18);
	bst.insertNode(bst.tree, 23);
	bst.insertNode(bst.tree, 6);
	bst.insertNode(bst.tree, 7);
	cout << "Inorder Traversal : ";
	bst.inOrder(bst.tree);
	cout << endl << "Preorder Traversal : ";
	bst.preOrder(bst.tree);
	cout << endl << "Postorder Traversal : ";
	bst.postOrder(bst.tree);
	cout << endl << "Descending Order : ";
	bst.descendOrder(bst.tree);
	cout << endl;
}