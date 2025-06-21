# include <iostream>
# include "oneLinkedList.h"
# include "oneLinkedList.cpp"
using namespace std;
void test01() {
	cout << "Testing adding element" << endl;
	LinkedList<int>* lists = new LinkedList<int>();
	lists->append(10);
	lists->prepend(20);
	lists->print();
	cout << endl;

	cout << "Adding element by index" << endl;
	lists->add_by_index(1, 99);
	lists->print();

	lists->add_by_index(3, 18);
	lists->print();

	lists->add_by_index(4, 25);
	lists->print();

	delete lists;
	cout << endl;
}

void test02() {
	cout << "Testing delete element" << endl;
	LinkedList<char>* lists = new LinkedList<char>();

	int ini = (int)'a';
	for (int i = 0; i < 10; i++) {
		lists->append(ini);
		ini++;
	}

	lists->print();

	lists->delete_byvalue('b');
	lists->delete_byvalue('e');
	lists->print();

	lists->delete_byindex(0);
	lists->delete_byindex(3);
	lists->print();

	lists->clearlist();
	delete lists;
	cout << endl;
}

void test03() {
	cout << "Modify value of list" << endl;
	LinkedList<int>* list = new LinkedList<int>();
	for (int i = 10; i < 16; i++) {
		list->append(i);
	}
	list->print();

	list->modify_value(3, 100);
	list->print();
	cout << "Index of 100 is " << list->get_index(100) << endl;
	cout << "The data at index 1 is " << list->get_data(1) << endl;
	delete list;
	cout << endl;
}

void test05() {
	cout << "Reverse and sorting" << endl;
	LinkedList<int>* list = new LinkedList<int>();

	for (int i = 0; i < 6; i++)
	{
		if (i < 3) {
			list->prepend(i);
		}
		else {
			list->append(i);
		}
	}
	list->print();

	list->reverse2();
	list->print();

	list->sort();
	list->print();

	list->sort(false);
	list->print();

	delete list;
	cout << endl;
}

void questionOne() {
	LinkedList<int>* list = new LinkedList<int>();
    list->append(1);
	list->append(2);
	list->append(3);
	list->append(4);
	list->append(5);
	list->append(6);
	list->append(7);
	list->findElem(3);

	delete list;
}

void questionTwo() {
	LinkedList<char>* list1 = new LinkedList<char>();
	LinkedList<char>* list2 = new LinkedList<char>();

	// 构建 list1: 'l' -> 'o' -> 'a' -> 'd' -> 'i' -> 'n' -> 'g'
	list1->append('l');
	list1->append('o');
	list1->append('a');
	list1->append('d');

	// 构建共享部分 'i' -> 'n' -> 'g'
	LinkedList<char>::Node* sharedNode = new LinkedList<char>::Node{ 'i', nullptr };
	sharedNode->next = new LinkedList<char>::Node{ 'n', nullptr };
	sharedNode->next->next = new LinkedList<char>::Node{ 'g', nullptr };

	// 让 list1 的尾部指向共享节点
	LinkedList<char>::Node* tail1 = list1->head;
	while (tail1->next != nullptr) {
		tail1 = tail1->next;
	}
	tail1->next = sharedNode;  // list1 现在包含共享部分

	// 构建 list2: 'b' -> 'e' -> [共享节点 'i' -> 'n' -> 'g']
	list2->append('b');
	list2->append('e');

	// 让 list2 的尾部指向共享节点
	LinkedList<char>::Node* tail2 = list2->head;
	while (tail2->next != nullptr) {
		tail2 = tail2->next;
	}
	tail2->next = sharedNode;  // list2 现在也包含共享部分

	// 调用 findStart 查找第一个公共节点
	char result = list1->findStart(list2->head);
	std::cout << "The first shared node data: " << result << std::endl;  // 输出 'i'

	delete sharedNode->next->next;
    delete sharedNode->next;
    delete sharedNode;
	tail1->next = nullptr;
	tail2->next = nullptr;
	delete list1;
	delete list2;
}

void questionThree() {
	LinkedList<int> *list = new LinkedList<int>();
	list->append(21);
	list->append(-15);
	list->append(-15);
	list->append(-7);
	list->append(15);

	list->removeNode(21);
	list->print();
	delete list;
}

void questionFour() { 
    LinkedList<int> *list = new LinkedList<int>();
    list->append(1);
	list->append(2);
	list->append(3);
	list->append(4);
	list->append(5);
	list->append(6);

	list->reOrderList();
    list->print();
	delete list;
}

void questionFive() {
	LinkedList<int> *list = new LinkedList<int>();
	list->append(1);
	list->append(2);
	list->append(3);
	list->append(4);
	list->append(5);
	list->append(6);
	list->append(7);
	LinkedList<int>::Node* mid = list->head->next->next;
	LinkedList<int>::Node* tail = list->head;
	while (tail->next != nullptr) {
		tail = tail->next;
	}
    tail->next = mid;

	list->haveCycle();

    tail->next = nullptr;
	delete list;
}

void questionSix() {
    LinkedList<int> *list = new LinkedList<int>();
	list->append(1);
	list->append(2);
	list->append(3);
	list->append(4);
	list->append(5);
	list->append(6);
	list->append(7);
	LinkedList<int>::Node* mid = list->head->next->next;
	LinkedList<int>::Node* tail = list->head;
	while (tail->next != nullptr) {
		tail = tail->next;
	}
	tail->next = mid;

	list->cycleStart();

	tail->next = nullptr;
	delete list;
}

int main() {
	system("chcp 65001");
	// test01();
	// test02();
	// test03();
	// test05();
	// questionOne();
	// questionTwo();
	// questionThree();
    // questionFour();
    // questionFive();
    questionSix();

	system("pause");
	return 0;
}