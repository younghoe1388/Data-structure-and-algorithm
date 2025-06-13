#pragma once
# include <iostream>
using namespace std;
# define INI_SIZE 100
typedef int ElemType;

class DynamicList {
private:
	ElemType *data;
	int length;
	int capacity;

public:
	DynamicList();
	~DynamicList();

	// 判断扩容
	void expandOrNot();
};