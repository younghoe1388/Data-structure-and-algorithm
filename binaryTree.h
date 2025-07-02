#pragma once
#include <iostream>
using namespace std;

template <class T>
class binaryTree {
private:
	struct treeNode {
		T data;
        treeNode* lChild;
		treeNode* rChild;

		treeNode(const T& val = T()) : data(val), lChild(nullptr), rChild(nullptr) {}
	};

	int index = 0; // 用於建立樹

	treeNode* root;

    // 二叉樹的遍歷
	void preOrder(treeNode* node);
	void inOrder(treeNode* node);
	void postOrder(treeNode* node);

	// 二叉樹的建立
	void createTree(treeNode*& node);

public:
	binaryTree();
	~binaryTree();
	void destroyTree(treeNode* node); // 銷毀樹（用於析構函數）

	// 二叉樹的遍歷
	void preOrder(); // 前置遍歷（按範圍搜索）
    void inOrder(); // 中置遍歷（按深度搜索）
	void postOrder(); // 後置遍歷（按廣度搜索）

	// 二叉樹的建立
	void createTreeByStr();


};
