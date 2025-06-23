#pragma once
#include <iostream>
using namespace std;

class circularLinkedQueue {
private:
	struct Node {
		int data;
		Node* next;
	};

	Node* front;
	Node* rear;

public:
	circularLinkedQueue();
    ~circularLinkedQueue();

	bool isEmpty();

	void enqueue(int data);
	void dequeue();

	int getFront();
	void print();
};
