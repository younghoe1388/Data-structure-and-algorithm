#pragma once
#include <iostream>
using namespace std;

template <class T>
class threadTree {
private:
	struct threadNode {
		T data;
		threadNode* lchild;
		threadNode* rchild;
		int ltag; // 0: child node, 1: thread node
		int rtag;
	};

    threadNode* root;
	threadNode* prev;
	threadNode* head;
	int index;


	void destroy(threadNode* node);
	void create(threadNode*& node);
	void threading(threadNode* node); // 中序遍历线索化

public:
	threadTree();
    ~threadTree();

	void createBystr();
	void inOrderThreading();

	void inOrderTraverse();
 };
