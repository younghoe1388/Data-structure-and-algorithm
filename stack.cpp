# include <iostream>
# include "stack.h"
using namespace std;

template <class T>
Stack<T>::Stack() {
	this->top = -1;
    for (int i = 0; i < MAX_SIZE; i++) {
        this->data[i] = 0;
    }
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
T Stack<T>::pop() {
	if (this->top == -1) {
		cout << "Stack is empty, unable to pop elem" << endl;
		return -1;
	}

	// 直接长度减一，其后压栈时覆盖原数据即可
	T deleted = this->data[this->top]; // 保存被删除的元素
    this->top--;
	return deleted;
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

template <class T>
contentType Stack<T>::getToken(int& index, char& symbol) {
	symbol = expression[index];
	index++;

	switch (symbol) {
	case '(':
		return LEFT_PARE;
		break;
	case ')':
		return RIGHT_PARE;
		break;
	case '+':
		return ADD;
		break;
	case '-':
		return SUB;
		break;
	case '*':
		return MUL;
		break;
	case '/':
		return DIV;
		break;
	case '%':
		return MOD;
		break;
	case '\0':
		return EOS;
		break;
	default:
		return NUM;
	}
}

template <class T>
int Stack<T>::calculate() {
	int op1, op2;
	int index = 0;
	char symbol;
	contentType token = this->getToken(index, symbol);
	int result;

	while (token != EOS) {
		if (token == NUM) {
			this->push(symbol - '0');
		}
		else {
			op2 = this->getTop();
			this->pop();
			op1 = this->getTop();
			this->pop();

			switch (token) {
			case ADD:
				this->push(op1 + op2);
				break;
			case SUB:
				this->push(op1 - op2);
				break;
			case MUL:
				this->push(op1 * op2);
				break;
			case DIV:
				this->push(op1 / op2);
				break;
			case MOD:
				this->push(op1 % op2);
				break;
			default:
				break;
			}
		}

		token = getToken(index, symbol);
	}
	result = this->getTop();
	this->pop();
	cout << "The result is: " << result << endl;
	return result;
}

template <class T>
void Stack<T>::postfix() {
	// 栈内栈外优先级
	int in_stack[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
	int out_stack[] = { 20, 19, 12, 12, 13, 13, 13, 0 };

	contentType token;
	int index = 0;

	this->push(EOS);
	char symbol;
	T e;

	token = getToken(index, symbol);
	while (token != EOS) {
		if (token == NUM) {
			cout << symbol << "";
		}
		else if (token == RIGHT_PARE) {
			while (this->data[this->top] != LEFT_PARE) {
				T elem = pop();
                cout << elem << "";
			}
			pop();
		}
		else {
			while (in_stack[token] >= out_stack[this->data[this->top]]) {
                T elem = pop();
                cout << elem << "";
            }
			push(token);
		}
		token = getToken(index, symbol);
	}
}

int main() {
	system("chcp 65001");
    Stack<int> stack;
	stack.calculate();

	system("pause");
	return 0;
}