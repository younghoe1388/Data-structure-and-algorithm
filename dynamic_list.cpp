# include <iostream>
# include "dynamic_list.h"
using namespace std;

DynamicList::DynamicList()
{
    this->capacity = INI_SIZE;
    this->data = new ElemType[INI_SIZE];
    this->length = 0;
}

DynamicList::~DynamicList()
{
    delete [] this->data;
    if (this->data != nullptr) {
        this->data = nullptr;
    }
    this->length = 0;
    this->capacity = 0;
}

void DynamicList::expandOrNot() {
    if (this->length < this->capacity) {
        return;
    }

    this->capacity *= 2;

    ElemType *newData = new ElemType[this->capacity];
    for (int i = 0; i < this->length; i++) {
        newData[i] = this->data[i];
    }

    delete[] this->data;
    this->data = newData;
}

// 其他操作基本与静态数组一样，不再赘述