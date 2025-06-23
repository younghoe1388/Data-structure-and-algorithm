#pragma once
#include <iostream>
#define MAX_SIZE 100
using namespace std;

template <class T>
class Queue {
private:
	T data[MAX_SIZE];
	int front; // 出队
	int rear; // 入队

public:
	Queue();
	~Queue();

	// 判断队列是否为空
	bool isEmpty();

	// 出队
	void deQueue();
	// 入队
	void enQueue(T x);

	// 判断队列是否为满
	bool isFull();

	// 获取队头元素
    T getFront();
};
