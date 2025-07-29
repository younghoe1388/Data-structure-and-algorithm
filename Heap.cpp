#include "Heap.h"
#include <iostream>
using namespace std;

Heap::Heap() {
	this->size = 0;
	this->capacity = MAX_SIZE;
	this->data = new int[MAX_SIZE];
}

Heap::~Heap() {
	if (data != nullptr) {
		delete[] data;
		data = nullptr;
	}
}

void Heap::resize() {
	if (size == capacity) {
		this->capacity *= 2;
		int* newArr = new int[capacity];

		for (int i = 0; i < size; i++) {
			newArr[i] = this->data[i];
		}
		delete[] data;
		data = newArr;
	}
}

void Heap::insert(int value) {
	if (size == capacity) {
		resize(); //若有需要，进行扩容
	}

	// 插入数据
	data[size] = value;
	int index = size; // 当前插入数据的索引
	size++;

	// 判断数据在堆的位置
	int parent_index = (index - 1) / 2; //父节点索引
	while (parent_index >= 0 && data[parent_index] < data[index]) {
		int temp = data[parent_index];
		data[parent_index] = data[index];
		data[index] = temp;
		if (parent_index == 0) {
			break;
		}

		index = parent_index;
		parent_index /= 2;
	}
}

void Heap::pop() {
	if (this->size == 0) {
		cout << "The heap is empty" << endl;
	}

	data[0] = data[size - 1];
	size--;

	// 由堆顶下滤
	int index = 0;
	while (true) {
		int leftChild = index * 2 + 1; //左子节点索引
        int rightChild = index * 2 + 2; //右子节点索引
		int largest = index;

		if (leftChild < size && data[leftChild] > data[largest]) {
			largest = leftChild;
		}

		if (rightChild < size && data[rightChild] > data[largest]) {
			largest = rightChild;
		}

		if (index == largest) {
            break;
		}

		int temp = data[index];
		data[index] = data[largest];
        data[largest] = temp;

		index = largest;
	}
}

