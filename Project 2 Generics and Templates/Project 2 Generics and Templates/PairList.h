

#pragma once
#include "TheLinkedList.h"
#ifndef PAIRLIST
#define PAIRLIST
template<class T >
class PairList : public  LinkedList <Pair<T> > 
{
public:
	PairList();
	PairList(T first, T second);
	void addPairAtEnd(T first, T second);
	void addPairAtFront(T first, T second);
	T getFirst(T value);
	T getSecond(T value);
	void deletePair(T first, T second);
	void printList();
private:
	struct LLNode{
		Pair<T> Data;//will hold the data of the node. Using template so data could be anything
		LLNode* Next;//will be used to link the list, always pointing to the next node or the NULL/end of list
	};
	LLNode* Head;
};
#endif
template <class T>
PairList<T>::PairList()//default constructor
{	
	LLNode* L = new LLNode;
	L->Data = NULL;
	L->Next = NULL;
	Head = L;
}
template <class T>
PairList<T>::PairList(T first, T second)//Constructor, takes 2 inputs and creates a pair to be added to the list
{	
	LLNode* l = new LLNode;
	Pair<T> p(first, second);//creates a Pair object and fills them with the input values
	l->Data = p;
	Head = l;//sets head to point at this node
	Head->Next = NULL;//creates an end to the list
		
}
template <class T>
void PairList<T>::addPairAtEnd(T first, T second)//Adds a pair to the list
{
	LLNode* l = new LLNode;
	Pair<T> p(first, second);
	l->addEnd(p);
}
template <class T>
void PairList<T>::addPairAtFront(T first, T second)
{
	Pair<T> p(first, second);
	LLData->addFront(p);
}
template <class T>
T PairList<T>::getFirst(T value)
{
	this->Head = LLData->Head;
	while (Head->getSecond() != value)
	{
		Head = Head->Next;
	}
	if (Head->getSecond() == value)
	{
		return Head->getSecond();
	}
	else
		cout << "Could not find corresponding value.\n";
	return NULL;
}