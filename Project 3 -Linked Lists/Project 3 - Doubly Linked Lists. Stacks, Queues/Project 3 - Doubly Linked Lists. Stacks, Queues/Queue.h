/*QUEUE CLASS:This class inherits the DOUBLYLINKEDLIST Class and therefore is-a doublylinkedlist as well as itself being a template. It is built like a 
typical Queue, FIFO, with the ability to "enqueue" an item at the front of the queue and "dequeue" an item from the rear of the queue. It can clear the 
queue entirely. It has the ability tell the user what item is at the front or rear of the queue. Lastly, it can tell the user if the queue is empty or if
there are items in the queue. For this Queue Class I chose to inherit the doublyLinkedList because of object creation. I wanted an instance of a Queue
object to be a ready list the moment it is created. In my opinion, just like the Stack Class, this was the logical thing to do since by definition a 
queue is a list.*/
#pragma once
#ifndef QUEUE
#define QUEUE
#include <string>//included so we can use strings
#include "DoublyLinkedList.h"//uses the doublylinkedlist


template<class T>
class Queue :
	public DoublyLinkedList<T>
{
public:
/*
Funtion:		Queue()
Author:			Johnathan Bates
Description:	Default Constructor. Creates a Queue object which is itself a DoublyLinkedList. Uses the DoublyLinkedList constructor
Inputs:			None
Outputs:		None
*/
	Queue() : DoublyLinkedList<T>() {}
/*
Funtion:		Queue(T data)
Author:			Johnathan Bates
Description:	Constructor. Takes the data input and creates a Queue object which is itself a DoublyLinkedList. Uses the DoublyLinkedList constructor
Inputs:			Templated Input.
Outputs:		None
*/
	Queue(T data) : DoublyLinkedList<T>(data){}
/*
Funtion:		enqueue()
Author:			Johnathan Bates
Description:	Mutator. Adds item to the front of the queue
Inputs:			template data
Outputs:		None
*/
	void enqueue(T data) { this->addFront(data); }
/*
Funtion:		dequeue()
Author:			Johnathan Bates
Description:	Mutator. Removes item from the front of the queue and returns item to the caller
Inputs:			None
Outputs:		Template data. 
*/
	T dequeue()
	{
		if (this->is_Queue_Empty() != true)
		{
			T dequeued_Item = this->returnTail();//creates a new item that will hold the data of the item being removed from the rear of the queue
			this->deleteEndNode();//removes item at the rear of the queue as it will be returned
			return dequeued_Item;//returns item to caller that was at the rear of the queue
		}
		else
			cout << "Queue is already empty, cannot execute dequeue function.\n";//outputs message to console

		return this->returnTail();//returns NULL or nothing if it is empty
	}
/*
Funtion:		queue_Peek_Front()
Author:			Johnathan Bates
Description:	Accessor. Returns the data in the front of the queue
Inputs:			None
Outputs:		Template Data
*/
	T queue_Peek_Front() { return this->returnTail(); }
/*
Funtion:		queue_Peek_Front()
Author:			Johnathan Bates
Description:	Accessor. Returns the data in the rear of the queue
Inputs:			None
Outputs:		Template Data
*/
	T queue_Peek_Rear() { return this->returnHead(); }
/*
Funtion:		clear_Queue()
Author:			Johnathan Bates
Description:	Mutator. Removes all items from the queue
Inputs:			None
Outputs:		None
*/
	void clear_Queue(){ while (this->is_Queue_Empty() != true){	this->dequeue(); }		
	}
/*
Funtion:		queue_Size()
Author:			Johnathan Bates
Description:	Accessor. Returns the size of the queue to the caller
Inputs:			None
Outputs:		Int
*/
	int queue_Size() { return this->size_of_List(); }	
private:
/*
Funtion:		is_Queue_Empty()
Author:			Johnathan Bates
Description:	Accessor. Returns true if the queue is empty, else returns false
Inputs:			None
Outputs:		Bool
*/
	bool is_Queue_Empty() { return (this->size_of_List() == 0); }
};
#endif