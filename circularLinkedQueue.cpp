# include <iostream>
# include "circularLinkedQueue.h"
using namespace std;

circularLinkedQueue::circularLinkedQueue() {
	Node* head = new Node();
	head->data = 0;
	head->next = nullptr;
	front = rear = head;
}

circularLinkedQueue::~circularLinkedQueue() {
	if (front == nullptr && rear == nullptr) {
        return;
	}

	rear->next = nullptr;
	Node* current = front;
	while (current != nullptr) {
		Node* temp = current;
		current = current->next;
		delete temp;
	}

	if (front != nullptr) {
		front = nullptr;
	}

	if (rear != nullptr) {
		rear = nullptr;
	}
}

bool circularLinkedQueue::isEmpty() {
	if (front == rear) {
		cout << "Queue is empty" << endl;
		return true;
	}

	cout << "Queue is not empty" << endl;
	return false;
}

void circularLinkedQueue::enqueue(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = nullptr;

	rear->next = newNode;
    rear = newNode;
}

void circularLinkedQueue::dequeue() {
	if (front == rear) {
        cout << "Queue is empty, cannot deque" << endl;
		return;
	}

	Node* temp = front->next;
	front->next = temp->next;
	if (rear == temp) {
		rear = front;
	}
	delete temp;
}

int circularLinkedQueue::getFront() {
	if (front == rear) {
		cout << "Queue is empty, cannot get front" << endl;
		return -1;
	}

	return front->next->data;
}

void circularLinkedQueue::print() {
	if (isEmpty()) {  // 使用 isEmpty() 更安全
		cout << "Queue is empty" << endl;
		return;
	}

	Node* current = front->next;
    while (current != rear) {
        cout << current->data << " ";
        current = current->next;
    }
	cout << endl;
}

int main() {
	system("chcp 65001");
    circularLinkedQueue queues;

    queues.enqueue(1);
	queues.enqueue(2);
	queues.enqueue(3);
	queues.enqueue(4);
	queues.enqueue(5);
	queues.print();

	queues.dequeue();
	queues.print();
	queues.dequeue();
	queues.print();
	queues.getFront();

	system("pause");
	return 0;
}