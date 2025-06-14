# include <iostream>
# include "LinkedList.h"
using namespace std;

template <class T>
LinkedList<T>::LinkedList() {
	length = 0;
	head = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	cout << "The linked list is already deleted" << endl;
}

template <class T>
void LinkedList<T>::prepend(T data) {
	Node* new_node = new Node();
	(*new_node).data = data;
	(*new_node).next = head;
	head = new_node;

	length++;
}

template <class T>
void LinkedList<T>::append(T data) {
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = nullptr;

	if (head == nullptr) {
		head = new_node;
	}
	else {
		Node* p = head;
		while (p->next != nullptr) {
			p = p->next;
		}
		p->next = new_node;
	}
	length++;
}

template <class T>
void LinkedList<T>::add_by_index(int index, T data) {
	if (index > length) {
		cout << "The list have not enough space to add the data" << endl;
		return;
	}

	if (index <= 0) {
		prepend(data);
		return;
	}

	if (index == length) {
		append(data);
		return;
	}

	int current_index = 0;
	Node* p = head;
	while (p != nullptr && current_index < index - 1) {
		p = p->next;
		current_index++;
	}
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = p->next;
	p->next = new_node;
	length++;
}
template <class T>
void LinkedList<T>::delete_byvalue(T data) {
	if (length == 0) {
		cout << "The linked list is empty" << endl;
		return;
	}

	if (head->data == data) {
		Node* h = head;
		head = head->next;
		delete h;
		length--;
		return;
	}

	Node* p = head;
	Node* q = nullptr;
	while (p != nullptr) {
		if (p->next == nullptr) {
			cout << "The value you want to delete does not exists" << endl;
		}

		if ((p->next)->data == data) {
			q = p->next;
			p->next = q->next;
			delete q;
			length--;
			return;
		}
		p = p->next;
	}
}

template <class T>
void LinkedList<T>::delete_byindex(int index) {
	if (head == nullptr) {
		cout << "The linked list is empty" << endl;
	}

	if (index == 0) {
		Node* h = head;
		head = head->next;
		delete h;
		length--;
		return; 
	}

	Node* p = head;
	Node* q = nullptr;
	int current_index = 0;
	while (p != nullptr) {
		if (p->next == nullptr) {
			cout << "The index does not exists" << endl;
		}

		q = p->next;
		if (current_index == index - 1) {
			p->next = q->next;
			delete q;
			length--;
			break;
		}
		p = p->next;
		current_index++;
	}
}

template <class T>
void LinkedList<T>::clearlist() {
	if (head == nullptr) {
		cout << "The linked list have been cleared" << endl;
	}

	Node* p = head;
	Node* current;
	while (p != nullptr) {
		current = p->next;
		delete p;
		p = current;
	}
	cout << "The list had been cleared" << endl;
}

template <class T>
void LinkedList<T>::modify_value(int index, T data) {
	Node* p = head;
	int current_index = 0;
	while (p != nullptr) {
		if (p->next == nullptr) {
			cout << "The index you input does not exists" << endl;
		}

		if (current_index == index) {
			p->data = data;
			return;
		}

		p = p->next;
		current_index++;
	}
}

template <class T>
T LinkedList<T>::get_data(int index) {
	Node* p = head;
	int current_index = 0;
	while (p != nullptr) {
		if (current_index == index) {
			return (p->data);
		}

		p = p->next;
		current_index++;
	}
	return T();
}

template <class T>
int LinkedList<T>::get_index(T data) {
	Node* p = head;
	int index = 0;
	while (p != nullptr) {
		if (p->next == nullptr) {
			cout << "Failed to find the index" << endl;
			return -1;
		}
		if (p->data == data) {
			return index;
		}

		p = p->next;
		index++;
	}
	return -1;
}

template <class T>
void LinkedList<T>::reverse_list() {
	if (head == nullptr) {
		cout << "Empty linked list cannot be reversed" << endl;
	}

	Node* new_head = nullptr;
	while (head != nullptr) {
		Node* temp = head;
		head = head->next;

		temp->next = new_head;
		new_head = temp;
	}
	head = new_head;
	cout << "Reversed successfully" << endl;
}

template <class T>
void LinkedList<T>::sort(bool accending) {
	if (head == nullptr) {
		cout << "This is an empty linked list, cannot sort" << endl;
	}

	Node* p = head;
	for (int i = 0; i < length; i++) {
		while (p->next != nullptr) {
			if (p->data > p->next->data) {
				T temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
			}
			p = p->next;
		}
		p = head;
	}
	if (!accending) {
		this->reverse_list();
	}
}

template <class T>
void LinkedList<T>::print() {
	Node* p = head;
	if (head == nullptr) {
		cout << "Empty list" << endl;
	}
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

