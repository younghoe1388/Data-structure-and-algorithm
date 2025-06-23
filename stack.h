#pragma once
#include <iostream>
#define MAX_SIZE 100
using namespace std;
template <class T>
class Stack {
private:
	int top;
	T data[MAX_SIZE];

public:
	Stack();
	~Stack();

	// 判断栈是否为空
	int isEmpty();

	// 压栈操作
	void push(T x);
	// 出栈操作
	void pop();

    // 获取栈顶元素
    T getTop();

    void print();
};
