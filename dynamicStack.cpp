# include <iostream>
# include "dynamicStack.h"
using namespace std;

dynamicStack::dynamicStack() {
	this->capacity = MAX_SIZE;
	this->data = new int[MAX_SIZE];
	this->top = -1;
}

dynamicStack::~dynamicStack() {
	delete[] data;
	if (this->data != nullptr) {
        delete[] this->data;
		this->data = nullptr;
	}
	this->top = -1;
    this->capacity = 0;
}

void dynamicStack::expandOrNot() { 
	if (this->top < this->capacity - 1) {
		return;
	}

	int* newData = new int[capacity * 2];
	for (int i = 0; i < this->capacity; i++) {
		newData[i] = this->data[i];
	}

	this->capacity *= 2;
	int* oldData = this->data;
	this->data = newData;
	delete[] oldData;
}

// 其余操作与静态栈相同，无需赘述