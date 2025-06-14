# include <iostream>
# include "LinkedList.h"
# include "LinkedList.cpp"
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

	list->reverse_list();
	list->print();

	list->sort();
	list->print();

	list->sort(false);
	list->print();

	delete list;
	cout << endl;
}


int main() {
	system("chcp 65001");
	test01();
	test02();
	test03();
	test05();

	system("pause");
	return 0;
}