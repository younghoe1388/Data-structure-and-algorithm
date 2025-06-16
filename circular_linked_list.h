#pragma once
# include <iostream>
using namespace std;

class CircularLinkedList {
private:
	int length;
	struct Node {
		int data;
		Node* next;
		Node* prev;
	};

	Node* head;
	Node* tail;

public:
	CircularLinkedList();
	~CircularLinkedList();

	// 插入数据
	void prepend(int data);
	void append(int data);
	void insert(int data, int index);

	// 删除数据
	void delete_byvalue(int data);
	void delete_byindex(int index);

	// 清空
	void clearList();

	// 修改数据
	void modifyValue(int index, int data);

	// 获取数据
	int getValue(int index);

	void printList();
};
