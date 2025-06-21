#pragma once
#include <iostream>
using namespace std;
template <class T>
class LinkedList {
public:
	int length;
	struct Node {
		T data;
		Node* next;
	};

	Node* head = nullptr;

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
	void reverse2();
	void sort(bool accending = true);

	// 删除中间节点
	void removeMid();

	void print();

	// 接下去为试题解答
	T findElem(int k); // 查找倒数第k个元素（2019）
	T findStart(Node* second); // 查找链表第一个与第二个节点相同的元素（2012）
	void removeNode(int n); //删除链表内的重复值（绝对值相同的值就要删）
	void reOrderList(); // 交替排序链表（2019）
	bool haveCycle(); // 判断链表是否有环
	void cycleStart(); // 寻找链表环的入口点
};


