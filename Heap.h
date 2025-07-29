#pragma once
#include <iostream>
using namespace std;

class Heap {
public:
	Heap();
	~Heap();

	void resize();

	void insert(int value);
	void pop();
private:
	static const int MAX_SIZE = 100;

	int* data; // 堆数组
	int size;
	int capacity;
};
