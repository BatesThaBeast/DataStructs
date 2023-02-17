/*DOUBLYLINKEDLIST Class: This class is a template, doubly linked list which consist of Nodes. Nodes are what holds the data and connects the data with each other,
making up what the list is. When a list is either created or has data added to it, it has the ability to see what data comes before and after said data that was added.
This class is capable of adding and deleting Nodes at the front or rear of the list. This class can insert a Node at a desired position in the list. It has the ability
to traverse the list to a desired position, whether it traverses forward or backwards and tells the user if a Node exist or not as well as what data is held at that
position. Conversely, if the user doesn't know what position they want to look at but wants to find a specific Node by the data it holds, there is a Find Node function
. This class can print the contents of the list either forwards or backwards to console. Lastly, for use with Stacks and Queues, the list can return what is held at the
front or back of the list.*/

#pragma once
#ifndef DOUBLYLINKEDLIST
#define DOUBLYLINKEDLIST
#include <iostream>//included so we can use the input/output streams
#include <type_traits>// included so we can use NULL
using namespace std;

template<class T>
class DoublyLinkedList
{
public:	//function definitions for the class. For more description of each function, scroll to just above a function
/*
Funtion:		LinkedList()
Author:			Johnathan Bates
Description:	Default Constructor.Sets Head's Next pointer to Tail and Tail's Prev pointer to Head
Inputs:			None
Outputs:		None
*/
	DoublyLinkedList() { Head->Next = Tail, Tail->Prev = Head; }
	/*
	Funtion:		LinkedList(T data)
	Author:			Johnathan Bates
	Description:	Constructor. Takes an input that isn't defined until compile time as this is a template class
	Inputs:			Template data. To be determined at compile time. This will be what the data section of the Node is set to
	Outputs:		None
	*/
	DoublyLinkedList(T data)
	{
		Node* a = new Node;//creates a new Node a
		a->Data = data;//Sets new Nodes data equal to input
		Head->Next = a, a->Prev = Head, a->Next = Tail, Tail->Prev = a;//Inserts new Node between Head and Tail Nodes.
		theSize++;//increments the size count of the list
	}
	/*
	Funtion:		addFront(T data)
	Author:			Johnathan Bates
	Description:	Mutator. Creates a new Node to be inserted at the start of the list. Takes in template data to be determined at compile time
	Inputs:			Template data. To be determined at compile time. This will be what the data section of the Node is set to
	Outputs:		None
	*/
	void addFront(T data)
	{
		Node* a = new Node;//creates a new node, our iterator
		a->Data = data;//set new node data section equal to input
		if (Head->Next == Tail)//checking to see if there are any Nodes after Head in the list(if there are any items in the list)
		{
			/*Head's Next pointer is set to point to Node a, the first in the list. Node a's Prev pointer is set to point to Head.
			Node a's Next pointer is set to point to Tail. Tail's Prev pointer is set to point to Node a, the first Node in the list.
			and finally the size count of the list is incremented as we are adding an item to the list*/
			Head->Next = a, a->Prev = Head, a->Next = Tail, Tail->Prev = a, theSize++;
		}
		else
		{
			Node* p = Head->Next;//creates new Node p to equal the Node Head is pointing to
			/*Node a's Next pointer now points to p, which is now the second Node in the list.
			inserted Node's Prev pointer is now pointing to Head.second Node p's Prev pointer is now pointing to Node a, the first Node
			Head's Next pointer is now pointing to a, the first Node in the list increments the size count of the list as we are adding an item to the list*/
			a->Next = p, a->Prev = Head, p->Prev = a, Head->Next = a, theSize++;
		}
	}
	/*
	Funtion:		addEnd(T data)
	Author:			Johnathan Bates
	Description:	Mutator. Creates a new Node to be inserted at the end of the list. Takes in template data to be determined at compile time
	Inputs:			Template data. To be determined at compile time. This will be what the data section of the Node is set to
	Outputs:		None
	*/
	void addEnd(T data)
	{
		Node* a = new Node;//creates new Node a. This will be the Node to be inserted
		a->Data = data;//sets a's data section equal to the input
		if (Tail->Prev == NULL)//checking to see if there are any nodes in the list. if Tail->Prev is null, means list has no nodes
		{
			Tail->Prev = a;//sets Tail's Prev pointer to point to the Node being inserted
			Head->Next = a;//sets Head's Next pointer to point to the Node being inserted
			a->Prev = Head;//sets Node a's Prev pointer to point to Head
			a->Next = Tail;//sets Node a's Next pointer to point to Tail
			theSize++;//increments the size count of the list as we are adding an item to the list
		}
		else//there are Nodes already in the list, so insertion will connect new Node to the rest of the list
		{
			Node* b = Tail->Prev;//creates a new Node b, and sets it equal to what Tail's Prev pointer was pointing at
			b->Next = a;//sets Node b's Next pointer to point to Node a.
			a->Prev = b;//sets Node a's Prev pointer to point to Node b. Now Nodes are linked
			a->Next = Tail;//sets Node a's Next pointer to point to Tail
			Tail->Prev = a;//sets Tail's Prev pointer to point to Node a. Now list links all the way through to Tail
			theSize++;//increments the size count of the list as we are adding an item to the list
		}
	}
	/*
	Funtion:		insertNode(T search, T data)
	Author:			Johnathan Bates
	Description:	Mutator. Inserts Node just after desired position in the list.
	Inputs:			Template data. To be determined at compile time. One is a search value to find the Node, the other is the data that is to be inputted into the new node
	Outputs:		None
	*/
	void insertNode(T search, T data)
	{
		Node* a = Head->Next;//creates a new node n which will serve as our iterator
		while (a->Data != search)//cycles through the nodes until the end of the list is reached
		{
			a = a->Next;// iterates to the next Node
		}
		if (a == Tail)//checks to see if end of list has been reached
		{
			cout << "Could not locate node in which insertion is to be done. Insertion failed.\n";//outputs message nothing was inserted
		}
		else//executes if a match was found with search input
		{
			Node* b = new Node;
			b->Data = data;
			b->Next = a->Next;
			b->Prev = a;
			a->Next->Prev = b;
			a->Next = b;
			theSize++;//increments the size count of the list as we are adding an item to the list
		}
	}
	/*
	Funtion:		deleteNode(T data)
	Author:			Johnathan Bates
	Description:	Mutator. Deletes desired Node from the list.
	Inputs:			Template data. To be determined at compile time. Used to find desired position in the list to be deleted
	Outputs:		None
	*/
	void deleteNode(T delData)
	{
		Node* CurrPos = Head;//uses current position ptr and sets it equal to the beginning of the list
		while (CurrPos->Next != Tail && CurrPos->Data != delData)//either cycles through the list entirely or stops at the position where the input matches the data, effectively finding the node that was searched for **whatever is being insterted to data needs to have to overload the != operator to acheive this
		{
			CurrPos = CurrPos->Next;//increments the currpos ptr to the next node
		}
		if (CurrPos->Next == Tail && CurrPos->Data != delData)//checks to see if we reached the end of the list without finding a match from input to data. Nothing to delete
		{
			cout << "No match was found. No deletion occured.\n";//outputs message indicating nothing was deleted
		}
		else//delData was found, deleting Node
		{
			Node* a = CurrPos->Prev;
			a->Next = CurrPos->Next;
			CurrPos->Next->Prev = a;
			theSize--;//decrements the size count of the list as we are subtracting an item to the list
			delete CurrPos;
		}
	}
	/*
	Funtion:		deleteFrontNode(T data)
	Author:			Johnathan Bates
	Description:	Mutator. Deletes first Node from the list.
	Inputs:			None
	Outputs:		None
	*/
	void deleteFrontNode()

	{
		if (Head->Next != Tail)
		{
			Node* a = Head->Next->Next;
			Head->Next = a;
			a->Prev = Head;
			theSize--;//decrements the size count of the list as we are subtracting an item to the list
		}
		else
			cout << "The list is empty, cannot delete front Node.\n";
	}
	/*
	Funtion:		deleteEndNode(T data)
	Author:			Johnathan Bates
	Description:	Mutator. Deletes last Node from the list.
	Inputs:			None
	Outputs:		None
	*/
	void deleteEndNode()
	{
		if (Tail->Prev != Head)
		{
			Node* a = Tail->Prev->Prev;
			Tail->Prev = a;
			a->Next = Tail;
			theSize--;//decrements the size count of the list as we are subtracting an item to the list
		}
		else
			cout << "The list is empty, cannot delete end Node.\n";
	}
	/*
	Funtion:		traverseForward()
	Author :		Johnathan Bates
	Description :	Accessor. Starts at the beginning of the list and cycles through every node until reaching the end of the list
	Inputs :		Int
	Outputs :		Template Data
	*/
	T traverseForward(int index)
	{
		Node* p = Head->Next;//creates a new pointer and sets it at the beginning of the list
		int i = 0;//creates int i and sets it equal to zero. This is used to keep track of where we are in the list
		while (p->Next != Tail && i <= index)//cycles through the nodes until the end of the list is reached
		{
			p = p->Next;//cycling to next Node
			i++;//increments i
		}
		if (i = index)
		{
			cout << p->Data << " is in position " << i << " in the list.\n";
			return p->Data;//returns item found at index
		}
		else
			cout << "That position does not exist in the list\n";
		return NULL;
	}
	/*
	Funtion:		traverseBackward()
	Author :		Johnathan Bates
	Description :	Accessor. Starts at the end of the list and cycles through every node until reaching the beginning of the list
	Inputs :		Int
	Outputs :		Template Data
	*/
	T traverseBackward(int index)
	{
		Node* p = Tail->Prev;//set currpos to the start of the linked list
		int i = 0;
		while (p->Prev != Head && i <= index)//cycle through list until data section matches what is being searched for
		{
			p = p->Prev;//advances CurrPos to the next node
			i++;//increments i
		}
		if (i = index)
		{
			cout << p->Data << " is in position " << i << " in the list.\n";
			return p->Data;//returns item found at index
		}
		else
			cout << "That position does not exist in the list\n";
		return NULL;
	}
	/*
	Funtion:		findNode(T data)
	Author :		Johnathan Bates
	Description :	Accessor. Cycles through the list until a match is found from the input. If no match is found outputs to console no match
	Inputs :		Template data. To be determined at compile time. Used to find desired position in the list
	Outputs :		Bool
	*/
	bool findNode(T data)
	{
		int count = 1;
		Node* CurrPos = new Node;
		CurrPos = Head->Next;//set currpos to the start of the linked list
		while (CurrPos->Data != data && CurrPos->Next != NULL)//cycle through list until data section matches what is being searched for
		{
			CurrPos = CurrPos->Next;//iterates to the next Node
			count++;//increments the count to keep track of which Node we are at
		}
		if (CurrPos == Tail)//check to see if end of list has been reached
		{
			cout << "Could not find Node.\n";
			return false;//no match was found,returns false to the caller that there is a match
		}
		else//if a match was found
		{
			cout << "Node exist at position " << count << " in list.\n";//tells caller the position of the Node in the list
			return true;//match was found, returns true to the caller that there is a Node
		}
	}
	/*
	Funtion:		printListForward()
	Author:			Johnathan Bates
	Description:	Accessor. Prints each Node within the list to the console from begginning to end of list.
	Inputs:			None
	Outputs:		None
	*/
	void printListForward()
	{
		Node* CurrPos = Head->Next;//set currpos to the start of the linked list
		while (CurrPos != Tail)//cycle through list until data section matches what is being searched for
		{
			cout << CurrPos->Data << endl;//prints out Data section on a line **whatever is being insterted to data needs to have to overload the << operator to acheive this
			CurrPos = CurrPos->Next;//advances CurrPos to the next node
		}
		if (CurrPos == Tail)//check to see if end of list has been reached
		{
			cout << "End of list.\n";//outputs to console to let user know the end of list has been reached
		}
	}
	/*
	Funtion:		printListBackward()
	Author:			Johnathan Bates
	Description:	Accessor. Prints each Node within the list to the console from end to beginning of list.
	Inputs:			None
	Outputs:		None
	*/
	void printListBackward()
	{
		Node* CurrPos = Tail->Prev;//set currpos to the start of the linked list
		while (CurrPos != Head)//cycle through list until data section matches what is being searched for
		{
			cout << CurrPos->Data << endl;//prints out Data section on a line **whatever is being insterted to data needs to have to overload the << operator to acheive this
			CurrPos = CurrPos->Prev;//advances CurrPos to the next node
		}
		if (CurrPos == Head)//check to see if end of list has been reached
		{
			cout << "End of list.\n";//outputs to console to let user know the end of list has been reached
		}
	}
	T returnTail() { return Tail->Prev->Data; }//returns the data in the Node previous of tail to the caller
	T returnHead() { return Head->Next->Data; }//returns the data in the Node just after Head to the caller
	int size_of_List() { return theSize; }
private://data section for the class. Consists of a struct called Node which has a template data and a Node pointer named Next.Then outside the struct it has a Node pointer named Node Head
	struct Node
	{
		T Data;//will hold the data of the node. Using template so data could be anything
		Node* Next;//will be used to link the list, always pointing to the next node or the NULL/end of list
		Node* Prev;//will be used to link the list, always pointing to the previous node or the NULL/beginning of list
		Node(const T& d = T(), Node* p = NULL, Node* n = NULL) : Data(d), Prev(p), Next(n) {}
	};
	Node* Head = new Node;//will be used to reference the front of the list
	Node* Tail = new Node;//will be used to reference the end of the listNode::returnTail()
	int theSize = 0;

};
#endif

