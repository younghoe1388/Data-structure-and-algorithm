# include <iostream>
# include "circularQueue.h"
using namespace std;

template <class T>
circularQueue<T>::circularQueue() {
	front = 0;
	rear = 0;
}

template <class T>
circularQueue<T>::~circularQueue() {

}

template <class T>
bool circularQueue<T>::isEmpty() {
	if (front == rear) {
		cout << "Queue is empty" << endl;
		return true;
	}

	cout << "Queue is not empty" << endl;
    return false;
}

template <class T>
bool circularQueue<T>::isFull() {
	if ((rear + 1) % MAX_SIZE == front) {
		cout << "Queue is full" << endl;
		return true;
	}

	cout << "Queue is not full" << endl;
	return false;
}

template <class T>
void circularQueue<T>::equeue(T data) {
	if ((rear + 1) % MAX_SIZE == front) {
		cout << "Queue is full, unable to add" << endl;
		return;
	}

	queues[rear] = data;
	rear = (rear + 1) % MAX_SIZE; // 插环形入，满了再由第一个元素覆盖原数据
}

template <class T>
void circularQueue<T>::dequeue() {
	if (front == rear) {
		cout << "Queue is empty, cannot dequeue" << endl;
		return;
	}

	T deleted = queues[front];
	front = (front + 1) % MAX_SIZE;
}

template <class T>
void circularQueue<T>::getFront() {
	if (front == rear) {
		cout << "Queue is empty, cannot get front elem" << endl;
		return;
	}

    cout << "Front elem is: " << queues[front] << endl;
}

template <class T>
void circularQueue<T>::print() {
	for (int i = front; i < rear; i++) {
        cout << queues[i] << " ";
	}
	cout << endl;
}

// 测试
int main() {
	system("chcp 65001");

	circularQueue<int> cq;
	cq.equeue(1);
	cq.equeue(2);
	cq.equeue(3);
	cq.equeue(4);
	cq.equeue(5);
	cq.print();

	cq.getFront();
	cq.dequeue();
	cq.print();
	cq.dequeue();
	cq.print();

	system("pause");
	return 0;
}