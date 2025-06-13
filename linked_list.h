#pragma once
# include <iostream>
using namespace std;
// 顺序表的实现

# define MAXSIZE 100
typedef int ElemType; // 需要更换数据类型时可以通过此处变换

class SqList {
private: // 顺序表的数据成员
	ElemType data[MAXSIZE];
	int length;

public:
	void InitList(); // 初始化

	// 测试函数
	int getlength() { return length; };
	int getSize() { return sizeof(data); };

	// 输出顺序表内所有元素
	void printList();

	// 尾插元素
	void appendElem(ElemType x);
	// 头部加入元素
	void pushFront(ElemType x);
	// 指定位置插入元素
	void insertElem(int pos, ElemType x);

    // 删除首个元素
	void deleteFront();
	// 删除末尾元素
	void deleteLast();
    // 删除指定位置的元素
	void deleteElem(int pos);

	// 查找元素
	int findElem(ElemType x);

	// 排序（冒泡排序）
	void BubbleSort();
	// 逆序反转
	void reverseSort();

	// 反转顺序表
    void reverse();
};
