/*
Programmer: Hunter Johnson
Name: Linked List Template
Date: 3/7/2017
*/
#pragma once
template <typename T>
class LinkedList
{
private:
	// Declare a structure for the list
	struct Node {
		T data;			// The value in this node
		Node *next;		// To point to the next node
	};

	Node *top;			// List top pointer
public:
	//************************************************************
	// Default Constructor - Initializes the list with no nodes. 
	//************************************************************
	LinkedList() { top = nullptr; }

	// Destructor
	~LinkedList();

	// Linked list operations
	void insert(T);
	void insertAt(T, int);
	void insertAtFront(T);
	void insertAtEnd(T);
	void deleteNode(T);
	void deleteList();
	void printList() const;
	void reverseList();
	void removeFront();
	void sortList();
	bool isEmpty();
	int  getCount() const;
	T	 getElementAt(int) const;
	T	 getFrontElement() const;
	int  getNodeOccurances(T);
};

//**********************************************
// Destructor - Deletes every node in the list 
//**********************************************
template <typename T>
LinkedList<T>::~LinkedList()
{
	Node *nodePtr;		// To traverse the list
	Node *nextNode;		// To point to the next node

	// Position nodePtr at the top of the list
	nodePtr = top;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr)
	{
		// Save a pointer to the next node
		nextNode = nodePtr->next;

		// Delete the current node
		delete nodePtr;

		// Position nodePtr at the next node
		nodePtr = nextNode;
	}
}

//*********************************************************************************
// insertNode - inserts a node with newItem copied to its value member in order.  
//*********************************************************************************
template <typename T>
void LinkedList<T>::insert(T newItem)
{
	Node *newNode;				  // A new node
	Node *nodePtr;				  // To traverse the list
	Node *previousNode = nullptr; // The previous node

								  // Allocate a new node and store num there
	newNode = new Node;
	newNode->data = newItem;

	// If there are no nodes in the list, make newNode the first node
	if (!top)
	{
		top = newNode;
		newNode->next = nullptr;
	}
	else // Otherwise, insert newNode
	{
		// Position nodePtr at the top of list
		nodePtr = top;

		// Initialize previousNode to nullptr
		previousNode = nullptr;

		// Skip all nodes whose value is less than num
		while (nodePtr != nullptr && nodePtr->data < newItem)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If the new node is to be the lst in the list, insert it before all other nodes
		if (previousNode == nullptr)
		{
			top = newNode;
			newNode->next = nodePtr;
		}
		else // Otherwise insert after previous node
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

//****************************************************************************************************
// insertNodeAt - Inserts a node into a Linked List, given the value and position to be inserted at. 
//****************************************************************************************************
template <typename T>
void LinkedList<T>::insertAt(T value, int pos)
{
	Node *newNode;
	Node *nodePtr;
	Node *previousNode = nullptr;
	newNode = new Node;
	newNode->data = value;
	nodePtr = top;
	for (int i = 0; i < pos; ++i) { // iterate to the two nodes you want to insert between
		previousNode = nodePtr;
		nodePtr = nodePtr->next;
	}
	// if there is a previous node
	if (previousNode)
	{
		previousNode->next = newNode; // point next of the node before to the new node
		newNode->next = nodePtr;	  // point new node to the next node
	}
	// there is no previous node, nodePtr must be at head
	else
	{
		top = newNode;				 // point head to new node
		newNode->next = nodePtr;	 // point next to the old first
	}
}

//*****************************************************************************
// insertAtFront - Inserts the value given into the front of the Linked List. 
//*****************************************************************************
template <typename T>
void LinkedList<T>::insertAtFront(T newItem)
{
	Node *nodePtr = top;	 // Points to top node
	Node *newNode;			 // Holds new node

	newNode = new Node;	
	newNode->next = nullptr;
	newNode->data = newItem; // Set new value to the newNode->data
	newNode->next = nodePtr; // Set newNode->next node to top
	top = newNode;			 // Set top to newNode
}

//*****************************************************************
// insertAtEnd - inserts a node with the item passed into newItem 
// to the end of the list							                
//*****************************************************************
template <typename T>
void LinkedList<T>::insertAtEnd(T newItem)
{
	Node *newNode;  // To point to a new node
	Node *nodePtr;  // To move through the list

	// Allocate a new node and store newItem there.
	newNode = new Node;
	newNode->data = newItem;
	newNode->next = nullptr;

	// If there are no nodes in the list
	// make newNode the first node.
	if (!top)
		top = newNode;
	else  // Otherwise, insert newNode at end.
	{
		// Initialize nodePtr to head of list.
		nodePtr = top;

		// Find the last node in the list.
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}
}

//*********************************************************
// deleteNode - searches for a node with searchValue as   
// its value. The node, if found, is deleted from the list
// and from memory.			                              
//*********************************************************
template <typename T>
void LinkedList<T>::deleteNode(T item)
{
	Node *nodePtr;					// To traverse the list
	Node *previousNode = nullptr;   // To point to the previous node

	// If the list is empty, do nothing.
	if (!top)
		return;

	// Determine if the first node is the one.
	if (top->data == item)
	{
		nodePtr = top->next;
		delete top;
		top = nodePtr;
	}
	else
	{
		// Initialize nodePtr to top of list
		nodePtr = top;

		// Skip all nodes whose value member is 
		// not equal to num.
		while (nodePtr != nullptr && nodePtr->data != item)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list, 
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

//*******************************************************************
// deleteList - Deletes the nodes in the list, sets top to nullptr. 
//*******************************************************************
template <typename T>
void LinkedList<T>::deleteList()
{
	Node *nodePtr;		// To traverse the list
	Node *nextNode;		// To point to the next node

	// Position nodePtr at the top of the list
	nodePtr = top;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr) 
	{
		// Save a pointer to the next node
		nextNode = nodePtr->next;

		// Delete the current node
		delete nodePtr;

		// Position nodePtr at the next node
		nodePtr = nextNode;
	}
	top = nullptr;
}

//****************************************************
// printList - Shows the value stored in each node	 
// of the linked list pointed to by top.             
//****************************************************
template <typename T>
void LinkedList<T>::printList() const
{
	Node *nodePtr; // To move through the list

	// Position nodePtr at the top of the list
	nodePtr = top;

	// While nodePtr points to a node, traverse the list
	while (nodePtr)
	{
		// Display the data in this node
		cout << nodePtr->data << " ";

		// move to the next node
		nodePtr = nodePtr->next;
	}
}

//*********************************************************
// reverseList - Reverses the linked list contents order. 
//*********************************************************
template <typename T>
void LinkedList<T>::reverseList()
{
	if (top == nullptr) return;	// If no nodes in list

	Node *prev = nullptr, *current = top, *next;
	while (current != nullptr)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	// let top point at the last node (prev)
	top = prev;
}

template <typename T>
void LinkedList<T>::removeFront()
{
	Node *old = top;
	top = old->next;
	delete old;
}

//**********************************************************************
// sortList - Sorts the data contained in the nodes through loops side 
// by side starting with top and top->next.                            
//**********************************************************************
template <typename T>
void LinkedList<T>::sortList()
{
	// Starting from top, moves down the list
	for (Node *i = top; i->next != nullptr; i = i->next)
	{
		// Starting from top->next, moves down the list
		for (Node *selection = i->next; selection != nullptr; selection = selection->next)
		{
			// Compare data in nodes
			if (i->data > selection->data)
			{
				swap(i->data, selection->data);	// Swap the data in the two nodes
			}
		}
	}
}

//**********************************************************
// isEmpty - Determines whether the linked list is empty or not 
//**********************************************************
template <typename T>
bool LinkedList<T>::isEmpty()
{
	return top == NULL;
}

//**********************************************************
// getCount - Determines the number of nodes in the list.  
//**********************************************************
template <typename T>
int LinkedList<T>::getCount() const
{
	int count = 0;

	// Loop through list while top isnt nullptr, increment count
	for (Node *nodePtr = top; nodePtr != nullptr; nodePtr = nodePtr->next) 
	{
		count++;
	}
	return count;	
}

//********************************************************************************
// getElementAt - Returns the Linked List element at the given the position.     
//				  Algorithm:												     
//				  1. Initialize count = 0										 
//				  2. Set nodePtr to top node (head)								 
//				  3. Loop through the link list									 
//					  a. if count is equal to the passed index then return		 
//					     current node											 
//					  b.Increment count											 
//					  c.change current to point to next of the current.			 
//********************************************************************************
template <typename T>
T LinkedList<T>::getElementAt(int pos) const
{
	int count = 0;		 // Current Index
	Node* nodePtr = top; // Points to top node

						 // Loop through linked list
	while (nodePtr != nullptr)
	{
		if (count == pos)
			return(nodePtr->data);	// Return current node
		count++;					// Increment Count
		nodePtr = nodePtr->next;	// Change nodePtr to point to next of nodePtr
	}

	// (Check to see if this is correct) or try something since it doesn't return another path
	return NULL;
}

//********************************************************************************
// getFrontElement - Returns the front element
//********************************************************************************
template <typename T>
T LinkedList<T>::getFrontElement() const
{
	return top->data;
}

//******************************************************************************************
// getNodeOccurances - Counts how many times the given value 'n' occurs in the Linked List.
// Returns count													                       
//******************************************************************************************
template <typename T>
int LinkedList<T>::getNodeOccurances(T n)
{
	Node *nodePtr = top;		 // Point to top node
	int count = 0;				 // Counts occurances of node 'n'
	while (nodePtr)
	{
		if (nodePtr->data == n)
			count++;		// Node found, increment count
		nodePtr = nodePtr->next; // Point to next node
	}
	return count;
}