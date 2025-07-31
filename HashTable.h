#pragma once
#include <iostream>
#include <vector>

template <class Key, class Value>
class HashTable {
private:
	struct Node {
		Key key;
		Value value;
		Node* next;
		Node(Key key, Value value) : key(key), value(value), next(nullptr) {}
	};

	std::vector<Node*> table;
	size_t size;

	size_t hashFunc(Key key) const;

public:
	HashTable(size_t capacity);
	~HashTable();

	void insert(Key key, Value value);
	Value findKey(Key key);
	void remove(Key key);
	void print();
};

