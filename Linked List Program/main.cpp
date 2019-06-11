/*
Programmer: Hunter Johnson
Name: Linked List Template
Date: 3/7/2017
*/
// First Version of Linked List Implementation
#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	// Create linked list
	LinkedList<int> list;
	int length;
	
	cout << "Linked List Implementation:\n\n";

	// Operation Testing
	cout << "Is Empty: " << list.isEmpty() << endl;
	cout << "Insert End: ";
	list.insertAtEnd(5);
	list.insertAtEnd(15);
	list.insertAtEnd(3);
	list.printList();
	cout << endl;

	cout << "Insert: ";
	list.insert(10);
	list.insert(2);
	list.printList();
	cout << endl;

	cout << "Delete: ";
	list.deleteNode(5);
	list.printList();
	cout << endl;

	cout << "Delete List: ";
	list.deleteList();
	list.printList();
	cout << endl;
	
	cout << "Insert: ";
	list.insert(100);
	list.insert(56);
	list.printList();
	cout << endl;

	cout << "Length: ";
	length = list.getCount();
	cout << length << endl;

	
	for (int i = 0; i <= 15; i++)
	{
		list.insert(i);
	}
	cout << "Insert: ";
	list.printList();
	cout << endl;

	cout << "Length: ";
	length = list.getCount();
	cout << length << endl;
	
	cout << "Reverse: ";
	list.reverseList();
	list.printList();
	cout << endl;

	cout << "Sorted: ";
	list.sortList();
	list.printList();
	cout << endl;

	cout << "Insert: ";
	list.insert(32);
	list.insert(21);
	list.insert(21);
	list.insert(5);
	list.printList();
	cout << endl;

	cout << "Insert At: ";
	list.insertAt(5, 2);
	list.insertAt(78, 0);
	list.printList();
	cout << endl;

	cout << "Element At: ";
	int a = list.getElementAt(0);
	cout << "Index 0 is " << a << endl;

	cout << "Element At: ";
	int b = list.getElementAt(2);
	cout << "Index 2 is " << b << endl;	

	cout << "Element AT: ";
	int kk = list.getElementAt(50);
	cout << "Index 50 is " << kk << endl;

	cout << "Occurances: ";
	int c = list.getNodeOccurances(21);
	cout << "21 appears " << c << " times." << endl;

	cout << "Occurances: ";
	int d = list.getNodeOccurances(5);
	cout << "5 appears " << d << " times." << endl;

	cout << "Insert Front: ";
	list.insertAtFront(4);
	list.insertAtFront(88);
	list.printList();
	cout << endl;

	cout << "Sorted: ";
	list.sortList();
	list.printList();
	cout << endl;

	cout << "Length: ";
	int e = list.getCount();
	cout << e << endl;

	cout << "Is Empty: " << list.isEmpty() << endl;

	cout << "Insert Front: ";
	list.insertAtFront(12);
	list.printList();
	cout << endl << "Front Element: " << list.getFrontElement() << endl;

	cout << "Remove Front: ";
	list.removeFront();
	list.printList();


	system("pause");
	return 0;
}
