# include <iostream>
# include "circular_linked_list.h"
using namespace std;

CircularLinkedList::CircularLinkedList() {
	this->length = 0;
	this->head = nullptr;
	this->tail = nullptr;
}

CircularLinkedList::~CircularLinkedList() {
	if (head == nullptr) {
		return;
	}

	// 断开环形链表，成为线性链表
	this->head->prev = nullptr;
	this->tail->next = nullptr;

	Node* current = this->head;
	while (current != nullptr) {
		Node* temp = current;
		current = current->next;
		
		delete temp;
	}
	this->head = nullptr;
	this->tail = nullptr;
	this->length = 0;
}

void CircularLinkedList::prepend(int data) {
	Node* newNode = new Node();
	newNode->data = data;

	if (this->head == nullptr) {
		newNode->next = newNode;
		newNode->prev = newNode;
		this->head = newNode;
		this->tail = newNode;
	}

	else {
		newNode->next = this->head;
		newNode->prev = this->tail;

		this->head->prev = newNode;
		this->tail->next = newNode;

		head = newNode;
	}
	this->length++;
}

void CircularLinkedList::append(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	if (this->head == nullptr) {
		newNode->next = newNode;
		newNode->prev = newNode;
		this->head = newNode;
		this->tail = newNode;
	}

	else {
		newNode->next = this->head;
		newNode->prev = this->tail;
		this->tail->next = newNode;
		this->head->prev = newNode;

		this->tail = newNode;
	}

	this->length++;
}

void CircularLinkedList::insert(int data, int index) {
	if (index < 0 || index > this->length) {
		cout << "Invalid index, the linked list have no enough space to insert the element" << endl;
		return;
	}

	if (index == 0) {
		this->prepend(data);
		return;
	}

	if (index == this->length) {
		this->append(data);
		return;
	}

	Node* newNode = new Node();
	newNode->data = data;
	Node* current = this->head;
	for (int i = 0; i < index - 1; i++) {
		current = current->next;
	}
	newNode->next = current->next;
	newNode->prev = current;
    current->next = newNode;
	current->next->prev = newNode;
	this->length++;
}

void CircularLinkedList::delete_byvalue(int data) {
	if (this->length == 0) {
		cout << "The linked list is empty, cannot delete" << endl;
	}

	Node* current = this->head;
	bool found = false;
	bool firstIteration = true; // 表示这是第一次循环，确保至少循环一次

	while (current != this->head || firstIteration) {
		firstIteration = false; //后续为false，只判断循环是否到了头节点

		if (current->data == data) {
			found = true;

			// 处理单节点信息
			if (this->length == 1) {
				delete current;
				this->head = nullptr;
				if (this->tail) { this->tail = nullptr; };
				this->length = 0;
				return;
			}

			current->prev->next = current->next;
			current->next->prev = current->prev;

			// 更新头指针（如有需要）
			if (current == this->head) {
				this->head = this->head->next;
			}

			// 更新尾指针（如有需要）
			if (current == this->tail && this->tail) {
				this->tail = current->prev;
			}

			Node* temp = current;
			current = current->next;
			delete temp;
			this->length--;
		}

		else {
			current = current->next;
		}
	}

	if (!found) {
		cout << "The data " << data << " you found is not exist" << endl;
	}
}

void CircularLinkedList::delete_byindex(int index) {
	if (this->length == 0) {
		cout << "The list is empty, cannot delete" << endl;
		return;
	}

	if (index < 0 || index >= this->length) {
		cout << "The index is not found, cannot delete" << endl;
		return;
	}

	Node* current = this->head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}

	// 处理单节点情况
	if (this->length == 1) {
		delete current;
		this->head = nullptr;
		if (this->tail) { tail = nullptr; };
		this->length = 0;
		return;
	}

	current->next->prev = current->prev;
	current->prev->next = current->next;

	// 更新头节点（如有需要）
	if (current == this->head) {
		this->head = current->next;
	}

	// 更新尾指针
	if (current == this->tail && this->tail) {
		this->tail = current->prev;
	}

	delete current;
	this->length--;
}

void CircularLinkedList::clearList() {
	if (this->head == nullptr) {
		cout << "The linked list is already empty" << endl;
		return;
	}

	Node* current = this->head;
	bool firstIteration = true;
	while (current != this->head || firstIteration) {
        firstIteration = false;
		Node* temp = current;
		current = current->next;
		delete temp;
	}

	this->head = nullptr;
	this->tail = nullptr;
	this->length = 0;
}

void CircularLinkedList::modifyValue(int index, int data) {
	if (this->length == 0) {
		cout << "The linked list is empty, no value can be modified" << endl;
		return;
	}

	if (index < 0 || index > this->length - 1) {
        cout << "The index is not found, cannot modify" << endl;
		return;
	}

	Node* current = this->head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}

	current->data = data;
}

int CircularLinkedList::getValue(int index) { 
	if (this->length == 0) {
		cout << "The linked list is empty" << endl;
		return -1;
	}

	if (index < 0 || index > this->length - 1) {
		cout << "The index is not found, cannot get the value" << endl;
		return -1;
	}

	Node* current = this->head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	return current->data;
}

void CircularLinkedList::printList() { 
	bool firstIteration = true;
	Node* current = this->head;
	while (current != this->head || firstIteration) {
        firstIteration = false;
        cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

int main() {
	system("chcp 65001");
	CircularLinkedList* list = new CircularLinkedList();
	list->append(1);
	list->append(2);
	list->append(3);
	list->printList();

	system("pause");
	return 0;
}