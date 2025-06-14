#pragma once
# include <iostream>
using namespace std;
template <class T>
class LinkedList {
public:
	int length;
	struct Node {
		T data;
		Node* next;
	} *head;

	LinkedList();
	~LinkedList();

	void prepend(T data); // 在链表前加入数据
	void append(T data); // 在链表后加入数据
	void add_by_index(int index, T data); // 按索引在链表内加入数据

	void delete_byvalue(T data);
	void delete_byindex(int index);
	void clearlist();

	void modify_value(int index, T data);

	T get_data(int index);
	int get_index(T data);

	void reverse_list();
	void sort(bool accending = true);

	void print();

};
