#include <iostream>
#include <string>
#include "binaryTree.h"
using namespace std;

string trees = "ABDH#K###E##CFI###G#J##";

template <class T>
binaryTree<T>::binaryTree() {
	root = nullptr;
}

template <class T>
void binaryTree<T>::destroyTree(treeNode* node) {
	if (node != nullptr) {
		destroyTree(node->lChild);
		destroyTree(node->rChild);
		delete node;
	}
}

template <class T>
binaryTree<T>::~binaryTree() {
	destroyTree(root);
	root = nullptr;
}

template <class T>
void binaryTree<T>::preOrder(treeNode* node) {
	if (node == nullptr) { return; };
	cout <<  node->data << " ";
	preOrder(node->lChild);
	preOrder(node->rChild);
}

template <class T>
void binaryTree<T>::preOrder() {
	if (root == nullptr) {
		cout << "Tree is empty" << endl;
		return;
	}

	preOrder(root);
	cout << endl;
}

template <class T>
void binaryTree<T>::createTree(treeNode*& node) {
	if (index >= trees.length()) {
		return;
	}

	char ch = trees[index++];
	if (ch == '#') {
        node = nullptr;
	}
	else {
        node = new treeNode(ch);
        createTree(node->lChild);
		createTree(node->rChild);
	}
}

template <class T>
void binaryTree<T>::createTreeByStr() {
    index = 0;
    createTree(root);
}

template <class T>
void binaryTree<T>::inOrder(treeNode* node) {
	if (node == nullptr) { return; };
    inOrder(node->lChild);
	cout << node->data << " ";
    inOrder(node->rChild);
}

template <class T>
void binaryTree<T>::inOrder() {
	if (root == nullptr) {
		cout << "Tree is empty" << endl;
		return;
	}

	inOrder(root);
	cout << endl;
}

template <class T>
void binaryTree<T>::postOrder(treeNode* node) {
	if (node == nullptr) { return; };
    postOrder(node->lChild);
	postOrder(node->rChild);
    cout << node->data << " ";
}

template <class T>
void binaryTree<T>::postOrder() {
	if (root == nullptr) {
        cout << "Tree is empty" << endl;
        return;
	}

	postOrder(root);
    cout << endl;
}


int main() {
	system("chcp 65001");
	binaryTree<char> tree;
	tree.createTreeByStr();
	tree.preOrder();
	tree.inOrder();
	tree.postOrder();

	system("pause");
    return 0;
}


