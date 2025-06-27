#pragma once
#include <iostream>
#define MAX_SIZE 100
using namespace std;

enum contentType {
	LEFT_PARE, RIGHT_PARE,// 左右括号
	ADD, SUB, MUL, DIV, MOD,
	EOS, NUM // EOS是\0
};
string expression = "82/2+56*-"; // 后缀表达式
string express = "x/(i-j)*y";

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
	T pop();

    // 获取栈顶元素
    T getTop();

    void print();

	// 后缀表达式计算
	contentType getToken(int& index, char& symbol);
    int calculate();
	void postfix(); // 中缀转后缀表达式
};


