#pragma once
#include <iostream>
#define MAX_SIZE 100
using namespace std;

template <class T>
class circularQueue {
private:
	T queues[MAX_SIZE];
	int front;
	int rear;

public:
	circularQueue();
	~circularQueue();

	bool isEmpty();
	bool isFull();
	void equeue(T data); // 入队
	void dequeue(); // 出队
	void getFront();
	void print();
};
