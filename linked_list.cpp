# include <iostream>
# include "linked_list.h"
using namespace std;
// 静态顺序表的实现

// 初始化顺序表
void SqList::InitList()
{
    this->length = 0; // 初始化长度为0
    for (int i = 0; i < MAXSIZE; i++) {
        this->data[i] = 0;
    }
}

void SqList::printList() {
    for (int i = 0; i < this->length; i++) {
        cout << this->data[i] << " ";
    }
    cout << endl;
}

void SqList::appendElem(ElemType elem) {
    if (this->length == MAXSIZE) {
        cout << "The list is full, unable to append element" << endl;
        return;
    }
    this->data[length] = elem;
    this->length++;
    return;
}

void SqList::pushFront(ElemType elem) {
    if (this->length == MAXSIZE) {
        cout << "The list is full, unable to insert at front" << endl;
        return;
    }
    for (int i = this->length; i > 0; i--) {
        this->data[i] = this->data[i - 1];
    }
    this->data[0] = elem;
    this->length++;
}

void SqList::insertElem(int pos, ElemType elem) {
    if (this->length == MAXSIZE) {
        cout << "The list is full, unable to insert element" << endl;
        return;
    }

    if (pos < 0 || pos > this->length) {
        cout << "Invalid position, unable to insert" << endl;
        return;
    }

    for (int i = this->length - 1; i >= pos; i--) {
        this->data[i + 1] = this->data[i];
    }
    this->data[pos] = elem;
    this->length++;
}

void SqList::deleteFront() {
    if (this->length == 0) {
        cout << "The list is empty, unable to delete any element" << endl;
        return;
    }

    if (this->length == 1) {
        this->data[0] = 0;
    }
    else {
        for (int i = 1; i < this->length; i++) {
            this->data[i - 1] = this->data[i];
        }
    }

    this->length--;
}

void SqList::deleteLast() {
    if (this->length == 0) {
        cout << "The list is empty, unable to delete any element" << endl;
        return;
    }

    if (this->length == 1) {
        this->data[0] = 0;
        this->length--;
    }

    else {
        this->data[length - 1] = 0;
        this->length--;
    }
}

void SqList::deleteElem(int pos) { 
    if (this->length == 0) {
        cout << "The list is empty, unable to delete any element" << endl;
        return;
    }

    if (pos < 0 || pos >= this->length) {
        cout << "Invalid position, unable to delete" << endl;
        return;
    }

    for (int i = this->length - 1; i >= pos; i--) {
        this->data[i] = this->data[i + 1];
    }
    this->data[length - 1] = 0;
    this->length--;
}

int SqList::findElem(ElemType elem) {
    for (int i = 0; i < this->length; i++) {
        if (this->data[i] == elem) {
            return i;
        }
    }
    cout << "The element is not in the list, unable to find" << endl;
    return -1;
}

void SqList::BubbleSort() {
    for (int i = 0; i < this->length - 1; i++) {
        for (int j = 0; j < this->length - 1 - i; j++) {
            if (this->data[j] > this->data[j + 1]) {
                ElemType temp = this->data[j];
                this->data[j] = this->data[j + 1];
                this->data[j + 1] = temp;
            }
        }
    }
}

void SqList::reverseSort() {
    if (this->length == 0) {
        cout << "The list is empty, unable to reverse" << endl;
        return;
    }
    this->BubbleSort();
    int start = 0;
    int end = this->length - 1;
    while (start < end) {
        ElemType temp = this->data[start];
        this->data[start] = this->data[end];
        this->data[end] = temp;
        start++;
        end--;
    }
}

void SqList::reverse() { 
    if (this->length == 0) {
        cout << "The list is empty, unable to reverse" << endl;
        return;
    }

    int start = 0;
    int end = this->length - 1;
    while (start < end) {
        ElemType temp = this->data[start];
        this->data[start] = this->data[end];
        this->data[end] = temp;
        start++;
        end--;
    }
}

void test01() {
    SqList list;
    list.InitList();
    list.appendElem(10);
    list.pushFront(20);
    list.insertElem(1, 30);
    list.printList();

    list.deleteFront();
    list.printList();
    list.deleteElem(1);
    list.printList();
    list.deleteLast();
    list.printList();
}

void test02() {
    SqList lists;
    lists.InitList();
    lists.appendElem(10);
    lists.appendElem(20);
    lists.insertElem(1, 30);
    lists.pushFront(60);
    lists.printList();

    int pos = lists.findElem(20);
    cout << "The position of 20 is: " << pos << endl;
}

void test03() {
    SqList list1;
    list1.InitList();
    list1.appendElem(10);
    list1.appendElem(50);
    list1.appendElem(30);
    list1.appendElem(40);
    list1.appendElem(20);
    cout << "Before sorting: " << endl;
    list1.printList();

    list1.BubbleSort();
    cout << "After sorting: " << endl;
    list1.printList();

    list1.reverse();
    cout << "After reversing: " << endl;
    list1.printList();
}

int main() {
    system("chcp 65001");
    test03();

    system("pause");
    return 0;
}