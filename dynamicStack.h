#pragma once
#include <iostream>
#define MAX_SIZE 100
using namespace std;

class dynamicStack {
private:
	int top;
	int* data;
	int capacity;

public:
	dynamicStack();
	~dynamicStack();

	void expandOrNot();
};
