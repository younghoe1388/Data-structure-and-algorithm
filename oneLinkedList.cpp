# include <iostream>
# include "oneLinkedList.h"
using namespace std;

template <class T>
LinkedList<T>::LinkedList() {
	length = 0;
	head = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {
	Node* current = head;
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
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
void LinkedList<T>::reverse2() {
	if (this->head == nullptr || this->head->next == nullptr) {
		return;
	}

	Node* first = nullptr;
	Node* second = this->head;
	Node* third = nullptr;
	while (second != nullptr) {
		third = second->next;
		second->next = first;

		first = second;
		second = third;
	}

	this->head = first;
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

template <class T>
T LinkedList<T>::findElem(int k) {
	// 利用快慢指针寻找倒数第k个元素
	Node* fast = this->head;
	Node* slow = this->head;

	// 先让快指针走k步
	for (int i = 0; i < k; i++) {
		fast = fast->next;
	}

	while (fast != nullptr) {
		fast = fast->next;
		slow = slow->next;
	}

	cout << "The last " << k << "th element is " << slow->data << endl;
	return slow->data;
}

template <class T>
T LinkedList<T>::findStart(Node* second) {
	Node* p1 = this->head;
	Node* p2 = second;

	// 利用快慢指针寻找两个链表的相交点
	// 先找出两个链表之长度
	int len1 = 0;
	int len2 = 0;

	while (p1 != nullptr) {
		p1 = p1->next;
        len1++;
	}

    while (p2 != nullptr) {
        p2 = p2->next;
        len2++;
    }

	// 重置双指针，否则此时指向nullptr
    p1 = this->head;
	p2 = second;

	int diff = abs(len1 - len2);
	if (len1 > len2) {
		for (int i = 0; i < diff; i++) {
			p1 = p1->next;
		}
	}
    else {
        for (int i = 0; i < diff; i++) {
            p2 = p2->next;
        }
    }

	// 当p1和p2不指向同一节点时，往下遍历
	while (p1 != p2 && p1 != nullptr && p2 != nullptr) {
        p1 = p1->next;
		p2 = p2->next;
    }

	if (p1 == nullptr || p2 == nullptr) {
		cout << "No same data" << endl;
		throw std::runtime_error("No intersection found");
	}

	cout << "The first same data that shared by two linked list is " << p1->data << endl;
	return p1->data;
}

template <class T>
void LinkedList<T>::removeNode(int n) {
	Node* p = head;
	int index; // 记录数组下标
	int* arr = new int[n + 1];

	// 初始化数组
	for (int i = 0; i < n + 1; i++) {
		arr[i] = 0;
	}

	while (p->next != nullptr) {
		index = abs(p->next->data);
		if (arr[index] == 0) {
            arr[index] = 1;
			p = p->next;
		}
		else {
			Node* temp = p->next;
			p->next = temp->next;
			delete temp;
		}
	}
	delete[] arr;
}

template <class T>
void LinkedList<T>::removeMid() {
	Node* fast = this->head->next;
	Node* slow = this->head;

	while (fast != nullptr && fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
	}

    Node* mid = slow->next;
	slow->next = mid->next;
    delete mid;
}

template <class T>
void LinkedList<T>::reOrderList() {
	// 先将链表由中间断开
	Node* fast = this->head->next;
	Node* slow = this->head;
	while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
		slow = slow->next;
	}

	Node* mid = slow->next;
	slow->next = nullptr; // 断开链表

	Node* first = nullptr;
	Node* second = mid;
	Node* third;
	while (second != nullptr) { 
		third = second->next;
		second->next = first;

		first = second;
		second = third;
    }

	Node* p1 = this->head;
	Node* q1 = first;
	while (p1 != nullptr && q1 != nullptr) {
		Node* p2 = p1->next;
        Node* q2 = q1->next;

		p1->next = q1;
		q1->next = p2;
		p1 = p2;
		q1 = q2;
	}
}

template <class T>
bool LinkedList<T>::haveCycle() {
	Node* fast = this->head;
	Node* slow = this->head;
	while (fast != nullptr && fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow) {
            cout << "There is a cycle in the linked list" << endl;
			return true;
		}
	}
	return false;
}

template <class T>
void LinkedList<T>::cycleStart() {
    if (this->head == nullptr || this->head->next == nullptr) {
        cout << "This is an empty list" << endl;
        return;
    }
	// 判断是否有环
	Node* fast = this->head;
    Node* slow = this->head;
	bool hasCycle = false;

	while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;

		if (fast == slow) {
            hasCycle = true;
			break;
		}
	}

	if (!hasCycle) {
        cout << "There is no cycle in the linked list" << endl;
		return;
	}

	int count = 1; // 记录环的长度
	while (fast->next != slow) {
        fast = fast->next;
        count++;
	}

	// 找到环的入口点，利用环的入口步数 = 总长度 - 环的长度
	fast = this->head;
	slow = this->head;

	// 让快指针先走count步
    for (int i = 0; i < count; i++) {
        fast = fast->next;
    }

	// 快慢指针同步行走
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }

	cout << "The start point of the cycle is " << slow->data << endl;
}

