/*This is for Data Structures and Algorithms class. This was what the professor wanted us to achieve. I will separate in Main what the textbook wanted us to achieve.
This is the LinkedList Class. It's purpose within this program is to handle Pair Class objects, and organize them within a list
that is linked by pointers and built by a struct typically called Node. This is however a template class, making it capable of handling any data input and storing it within
it's list. LinkedList objects have the ability to add data to the front and end of it's list. It has the ability to insert a node
anywhere a user chooses. It can delete any Node of choice. Finally, it has the ability to traverse a list entire content and 
check to find a specific Node.*/
													
#pragma once
#ifndef LINKEDLIST
#define LINKEDLIST
#include <type_traits>// included so we can use NULL
#include "PairClass.h"
using namespace std;

template<class T>
class LinkedList : public Pair<T>
{
	public:	//function definitions for the class. For more description of each function, scroll to just above a function
	LinkedList();
	LinkedList(T data);
	void addFront(T data);
	void addEnd(T data);	
	void insertNode(T search, T data);
	void deleteNode(T delData);
	void traverse();
	bool findNode(T data);
	void printList();
	
private://data section for the class. Consists of a struct called Node which has a template data and a Node pointer named Next.Then outside the struct it has a Node pointer named Node Head
	struct Node  : public Pair<T>{
		T Data;//will hold the data of the node. Using template so data could be anything
		Node* Next;//will be used to link the list, always pointing to the next node or the NULL/end of list
		
	};
	Node* Head;//will be used to reference the front of the list
};
#endif
/*
Funtion:		LinkedList()
Author:			Johnathan Bates
Description:	Default Constructor.
Inputs:			None
Outputs:		None
*/
template<class T>
LinkedList<T>::LinkedList() 
{
	Node* p = new Node;//creates a new Node
	p->Data = NULL;//sets data equal to NULL since there is no input
	Head = p;//sets head to point at this node
	Head->Next = NULL;//creates an end to the list
}
/*
Funtion:		LinkedList(T data)
Author:			Johnathan Bates
Description:	Constructor. Takes an input that isn't defined until compile time as this is a template class
Inputs:			Template data. To be determined at compile time. This will be what the data section of the Node is set to
Outputs:		None
*/
template<class T>
LinkedList<T>::LinkedList(T data)
{
	Node* p = new Node;//creates a new node
	p->Data = data;//sets data section equal to input
	Head = p;//sets head to point at this node
	Head->Next = NULL;//creates an end to the list
}
/*
Funtion:		addFront(T data)
Author:			Johnathan Bates
Description:	Mutator. Creates a new Node to be inserted at the start of the list. Takes in template data to be determined at compile time
Inputs:			Template data. To be determined at compile time. This will be what the data section of the Node is set to
Outputs:		None
*/
template<class T>
void LinkedList<T>::addFront(T data)
{
	Node* p = new Node;//creates a new node, our iterator
	p->Data = data;//set new node data section equal to input
	if (Head->Next == NULL)//checking to see if there are any Nodes after Head in the list.
	{
		p->Next = Head;//sets current Nodes Next pointer to point to Head Node
		Head = p;//sets Head equal to p, making p the first node or Head
	}
	else
	{
		Node* n = Head;//creates a new Node to hold Head's data and point to what Head was pointing to.This will become the second node.
		p->Next = n;//sets new nodes pointer to point to what will be the second Node
		Head = p;// now head points to or equals new node, the new beginning of the list
	}
}
/*
Funtion:		addEnd(T data)
Author:			Johnathan Bates
Description:	Mutator. Creates a new Node to be inserted at the end of the list. Takes in template data to be determined at compile time
Inputs:			Template data. To be determined at compile time. This will be what the data section of the Node is set to
Outputs:		None
*/
template<class T>
void LinkedList<T>::addEnd(T data)
{
	if (Head == NULL)//checking to see if there are any nodes in the list. if head is null, means list has no nodes
	{
		Head = new Node;//make head the new first element
		Head->Data = data;//sets the data section of the node equal to the input
		Head->Next = NULL;//sets the pointer to point to NULL which is the end of the list
	}
	else
	{
		Node* p = Head;// create new node and set equal to head, will be our iterator
		while(p->Next != NULL)//cycle through nodes until we reach the end of the list
		{
			p = p->Next;// iterates to the next Node
		}
		Node* n = new Node;//create new node n
		n->Data = data;//set n's data section equal to the input
		n->Next = NULL;//set n's pointer equal to null creating a new end of the list
		p->Next = n;//sets what used to be the end of the list to point to new Node, or new end of list
	}
}
/*
Funtion:		insertNode(T search, T data)
Author:			Johnathan Bates
Description:	Mutator. Inserts Node just after desired position in the list.
Inputs:			Template data. To be determined at compile time. One is a search value to find the Node, the other is the data that is to be inputted into the new node
Outputs:		None
*/
template<class T>
void LinkedList<T>::insertNode(T search, T data)
{
	Node* p = Head;//creates a new node which will serve as our iterator
	while (p->Data != search)//cycles through the nodes until the end of the list is reached
	{
		p = p->Next;// iterates to the next Node
	}
	if (p->Next == NULL)//checks to see if end of list has been reached
	{
		cout << "Could not locate node in which insertion is to be done. Insertion failed.\n";//outputs message nothing was inserted
	}
	else//executes if a match was found with search input
	{
		Node* n = new Node;//creates a new node
		n->Data = data;//sets the data section of the new node equal to the input
		n->Next = p->Next;//sets n's pointer equal to p's pointer(linking into the list)
		p->Next = n;//sets p's pointer to point to n
	}
}
/*
Funtion:		deleteNode(T data)
Author:			Johnathan Bates
Description:	Mutator. Deletes desired Node from the list.
Inputs:			Template data. To be determined at compile time. Used to find desired position in the list to be deleted
Outputs:		None
*/
template<class T>
void LinkedList<T>::deleteNode(T delData)
{
	Node* delPtr = NULL;//create a delptr, will use for the purpose of deleting a node
	Node* Temp = NULL;//uses the Temp ptr and sets it equal to the beginning of the list. This node will trail CurrPos, effectively a link to the previous node
	Node* CurrPos = Head;//uses current position ptr and sets it equal to the beginning of the list
	while (CurrPos != NULL && CurrPos->Data != delData)//either cycles through the list entirely or stops at the position where the input matches the data, effectively finding the node that was searched for **whatever is being insterted to data needs to have to overload the != operator to acheive this
	{
		Temp = CurrPos;//gives us a link to the previous node before incrementation
		CurrPos = CurrPos->Next;//increments the currpos ptr to the next node
	}
	if (CurrPos == NULL)//checks to see if we reached the end of the list without finding a match from input to data. Nothing to delete
	{
		cout << "No match was found. No deletion occured.\n";//outputs message indicating nothing was deleted
		delete delPtr;//delData was not found
	}
	else//delData was found, deleting Node
	{
		delPtr = CurrPos;//sets the node to be deleted to currpos
		CurrPos = CurrPos->Next;//sets current pos to the next node,skipping the "current node"to be deleted
		Temp->Next = CurrPos;//sets the temp ptr equal to the currpos. Temp trailed curr pos, so this now leaps over what delptr is pointing to
		if (delPtr == Head)//checks to see if this is the first node in the list
		{
			Head = Head->Next;//sets the Head ptr to the next node
			Temp = NULL;//sets temp ptr equal to null
		}
		delete delPtr;//clears delptr from the heap(garbage collection).This deletes the node.
	}
}
/*
Funtion:		Traverse()
Author :		Johnathan Bates
Description :	Accessor. Starts at the beginning of the list and cycles through every node until reaching the end of the list
Inputs :		None
Outputs :		None
*/
template<class T>
void LinkedList<T>::traverse()
{
	Node* p = Head;//creates a new pointer and sets it at the beginning of the list
	while (p->Next != NULL)//cycles through the nodes until the end of the list is reached
	{
		p = p->Next;//cycling to next Node
	}
}
/*
Funtion:		findNode(T data)
Author :		Johnathan Bates
Description :	Accessor. Cycles through the list until a match is found from the input. If no match is found outputs to console no match
Inputs :		Template data. To be determined at compile time. Used to find desired position in the list
Outputs :		None
*/
template<class T>
bool LinkedList<T>::findNode(T data)
{
	Node* CurrPos = Head;//set currpos to the start of the linked list
	while (CurrPos != NULL && CurrPos->Data != data)//cycle through list until data section matches what is being searched for
	{
		CurrPos = CurrPos->Next;//iterates to the next Node
	}
	if (CurrPos == NULL)//check to see if end of list has been reached
	{
		cout << "Could not find Node.\n";
		return false;//no match was found,returns false to the caller that there is a match
	}
	else//if a match was found
	{
		cout << "Node exist.\n";
		return true;//match was found, returns true to the caller that there is a match
	}
}
/*
Funtion:		printList()
Author:			Johnathan Bates
Description:	Accessor. Prints each Node within the list to the console.
Inputs:			None
Outputs:		None
*/
template<class T>
void LinkedList<T>::printList()
{
	Node* CurrPos = Head;//set currpos to the start of the linked list
	while (CurrPos != NULL)//cycle through list until data section matches what is being searched for
	{
		cout << CurrPos->Data << endl;//prints out Data section on a line **whatever is being insterted to data needs to have to overload the << operator to acheive this
		CurrPos = CurrPos->Next;//advances CurrPos to the next node
	}
	if (CurrPos == NULL)//check to see if end of list has been reached
	{
		cout << "End of list.\n";//outputs to console to let user know the end of list has been reached
	}
}