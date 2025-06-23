# include <iostream>
# include "stack.h"
using namespace std;
template <class T>
Stack<T>::Stack() {
	this->top = -1;
}

template <class T>
Stack<T>::~Stack() {
	// 静态数组无需释放内存
}

template <class T>
int Stack<T>::isEmpty() {
	if (this->top == -1) {
		cout << "The stack is empty" << endl;
		return -1;
	}

	else {
		cout << "The stack is not empty" << endl;
		return 1;
	}
}

template <class T>
void Stack<T>::push(T data) {
	if (this->top >= MAX_SIZE - 1) {
		cout << "Stack is full, unable to push elem" << endl;
		return;
	}

	this->top++;
	this->data[this->top] = data;
}

template <class T>
void Stack<T>::pop() {
	if (this->top == -1) {
		cout << "Stack is empty, unable to pop elem" << endl;
		return;
	}

	// 直接长度减一，其后压栈时覆盖原数据即可
	T deleted = this->data[this->top]; // 保存被删除的元素
    this->top--;
}

template <class T>
T Stack<T>::getTop() {
	if (this->top == -1) {
		cout << "Stack is empty, unable to get top elem" << endl;
        return -1;
	}

	cout << "Stack top elem is: " << this->data[this->top] << endl;
	return this->data[this->top];
}

template <class T>
void Stack<T>::print() {
	if (this->top == -1) {
		cout << "Stack is empty, unable to print" << endl;
        return;
	}

	// 由栈顶到栈底打印
	for (int i = this->top; i >= 0; i--) {
		cout << this->data[i] << " ";
	}
	cout << endl;
}

int main() {
	system("chcp 65001");
    Stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.push(6);
	stack.print();

	stack.getTop();
    stack.pop();
	stack.getTop();
    stack.print();

	system("pause");
	return 0;
}