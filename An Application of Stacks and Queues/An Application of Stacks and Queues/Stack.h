/*STACK CLASS: This class inherits the DOUBLYLINKEDLIST Class and therefore is-a doublylinkedlist as well as itself being a template. It is built like a
typical stack, LIFO, with the ability to "push" an item onto the stack and "pop" an item off the stack. It can clear the stack entirely. It has the ability 
to tell the user what item is on top of the stack. Lastly, it can tell the user if the stack is empty or if there are items on the stack. For this Stack 
Class, I chose to inherit the doublyLinkedList because of object creation. I wanted an instance of a Stack object to be a ready list the moment it is 
created. In my opinion, this was the logical thing to do since by definition a stack is a list.*/
#pragma once
#ifndef STACK
#define STACK
#include <string>//included so we can use strings
#include "DoublyLinkedList.h"//uses the doublylinkedlist

template <class T>
class Stack :
	public DoublyLinkedList<T>
{
public:
/*
Funtion:		Stack()
Author:			Johnathan Bates
Description:	Default Constructor. Creates a Stack object which is itself a DoublyLinkedList. Uses the DoublyLinkedList constructor
Inputs:			None
Outputs:		None
*/
	Stack() : DoublyLinkedList<T>() {};
/*
Funtion:		Stack(T data)
Author:			Johnathan Bates
Description:	Constructor. Takes the data input and creates a Stack object which is itself a DoublyLinkedList. Uses the DoublyLinkedList constructor
Inputs:			Templated Input.
Outputs:		None
*/
	Stack(T data) : DoublyLinkedList<T>(data) {}
/*
Funtion:		push()
Author:			Johnathan Bates
Description:	Mutator. Adds item to the top of the stack
Inputs:			template data
Outputs:		None
*/
	void push(T input)	{ this->addFront(input); }
/*
Funtion:		pop()
Author:			Johnathan Bates
Description:	Mutator. Removes and returns data stored at the front of the Stack
Inputs:			None
Outputs:		Template Data
*/
	T pop()
	{
		if (this->is_Stack_Empty() != true)//check to see if the stack isn't empty
		{
			T temp = this->returnHead();//sets temp to equal whats on top of the stack before the pop operation
			this->deleteFrontNode();//this will remove last item that was put onto the stack.
			return temp;//returns what was popped of the stack
		}
		else
			cout << "Stack is already empty, cannot execute pop function.\n";//outputs message to console

		return this->returnHead();//returns NULL or nothing if it is empty
	}
/*
Funtion:		stack_Peek()
Author:			Johnathan Bates
Description:	Accessor. Returns data at the front of the Stack
Inputs:			None
Outputs:		Template Data
*/
T stack_Peek()	{ return this->returnHead(); }
/*
Funtion:		clear_Stack()
Author:			Johnathan Bates
Description:	Mutator. Runs a loop and pops all items off of the stack. As it's name implies, clears the stack of all data
Inputs:			None
Outputs:		None
*/
	void clear_Stack(){	while (this->is_Stack_Empty() != true){	this->pop(); }	}
/*
Funtion:		stack_Size()
Author:			Johnathan Bates
Description:	Accessor. Returns to the user how many items are currently in the Stack
Inputs:			None
Outputs:		Int
*/
	int stack_Size() { return this->size_of_List(); }
private:
/*
Funtion:		is_Stack_Empty()
Author:			Johnathan Bates
Description:	Accessor. Returns to user true if the stack is empty, false if there are items in the stack
Inputs:			None
Outputs:		Bool
*/
	bool is_Stack_Empty() { return (this->size_of_List() == 0); }
};
#endif