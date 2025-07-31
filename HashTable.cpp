#include <iostream>
#include <vector>
#include "HashTable.h"
using namespace std;

template <class Key, class Value>
HashTable<Key, Value>::HashTable(size_t capacity) {
	table.resize(capacity);
	size = 0;
}

template <class Key, class Value>
HashTable<Key, Value>::~HashTable() {
	for (size_t i = 0; i < table.size(); i++) {
		if (table[i] != nullptr) {
			Node* current = table[i];
			while (current != nullptr) {
				Node* temp = current;
				current = current->next;
				delete temp;
			}
		}
	}
}

template <class Key, class Value>
size_t HashTable<Key, Value>::hashFunc(Key key) const {
	static std::hash<Key> hasher;
	return hasher(key) % table.size();
}

template <class Key, class Value>
void HashTable<Key, Value>::insert(Key key, Value value) {
	size_t index = hashFunc(key);
	Node* current = table[index];

	while (current != nullptr) {
		if (current->key == key) {
			current->value = value;
			return;
		}
		current = current->next;
	}

	Node* newNode = new Node(key, value);
	newNode->next = table[index];
    table[index] = newNode;
	size++;
}

template <class Key, class Value>
Value HashTable<Key, Value>::findKey(Key key) {
	size_t index = hashFunc(key);
	Node* current = table[index];

	while (current != nullptr) {
		if (current->key == key) {
			return current->value;
		}
		current = current->next;
	}

	throw std::runtime_error("Key not found");
}

template <class Key, class Value>
void HashTable<Key, Value>::remove(Key key) { 
	size_t index = hashFunc(key);
	Node* current = table[index];

	Node* prev = nullptr;
	while (current != nullptr) {
		if (current->key == key) {
			if (prev == nullptr) {
                table[index] = current->next;
			}
			else {
				prev->next = current->next;
			}
			delete current;
			size--;
			return;
		}
		prev = current;
		current = current->next;
	}
	throw std::runtime_error("Key not found");
}

template <class Key, class Value>
void HashTable<Key, Value>::print() {
	for (size_t i = 0; i < table.size(); i++) {
		Node* current = table[i];
		if (table[i] != nullptr) {
			Node* current = table[i];
			while (current != nullptr) {
                cout << "[" << i << "] " << current->key << ": " << current->value << endl;
                current = current->next;
			}
		}
	}
}

int main() {
	system("chcp 65001");
	HashTable<int, int> table(10);
    table.insert(1, 1);
	table.insert(2, 2);
	table.insert(3, 3);
	table.print();
	cout << endl;

	table.remove(1);
	table.print();

	system("pause");
	return 0;
}

