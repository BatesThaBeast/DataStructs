/*THis is the example used in the book. Wanted to build and see the difference in application vs the linked list I had created.*/


#pragma once
#ifndef LIST
#define LIST
#include <iostream>
#include <type_traits>
template <class T>
class List
{
private:
	struct Node//this is Node struct. this will become the elements within the Linked List, this one being a doubly linked list
	{
		T data;//will hold the data of the node. Using template so data could be anything
		Node* next;//will be used to link the list, always pointing to the next node or the NULL/end of list
		Node* prev;//will be used to link the list, always pointing to the previous node or the NULL/beginning of list
		Node(const T& d = T(), Node* p = NULL, Node* n = NULL) : data(d), prev(p), next(n) {}//Node constructor
	};
public:
	class const_iterator
	{
	public:
		const_iterator() : current(NULL) {}//default constructor
		const T& operator*() const { return retrieve(); }//
		const_iterator& operator ++()//increments the const_iterator to the next Node and will return what is referenced
		{
			current = current->next;//incrementing const_iterator
			return *this;//returns the data to the const_iterator
		}
		const_iterator operator ++(int)//increments the const_iterator to the next Node and returns a pointer
		{
			const_iterator old = *this;//makes a instance of const_iterator called old and sets it equal to the current Node
			++(*this);//increments to the next Node in the list
			return old;//returns what is now in old back to the caller
		}
		bool operator ==(const const_iterator& rhs) const { return current == rhs.current; }//overloaded ==. returns if true
		bool operator !=(const const_iterator& rhs) const { *this == rhs; }//overloaded !=. 
	protected:
		Node* current;//creates a Node named current

		T& retrieve() const { return current->data; }//returns what is in the current Nodes data
		const_iterator(Node* p) : current(p) {}//constructor. sets currents data to Node p.
		friend class List<T>;//allows access to the list class funtions and members
	};
	class iterator : public const_iterator
	{
	public:
		iterator() {}//iterator constructor

		T & operator * () { return const_iterator::retrieve(); }
		const T& operator*() const { return const_iterator::operator*(); }
		iterator& operator++ ()
		{
			const_iterator::current = const_iterator::current->next;
			return *this;
		}
		iterator operator++(int)
		{
			iterator old = *this;
			++(*this);
			return old;
		}
	protected:
		iterator(Node* p) : const_iterator (p){}
		friend class List<T>;
	};
public:
	List() { init(); }
	~List() 
	{
		clear();
		delete head;
		delete tail;
	}
	List(const List& rhs)
	{
		init();
		*this = rhs;
	} 

	const List& operator =(const List& rhs)
	{
		if (this == &rhs)
			return *this;
		clear();
		for (const_iterator itr = rhs.begin(); itr != rhs.end(); ++itr)
			push_back(*itr);
		return *this;
	} 

	iterator begin()
	{
		return iterator(head->Next);
	}
	const_iterator begin()
	{
		return const_iterator(head->Next);
	}
	iterator end()
	{
		return iterator(tail);
	}
	const_iterator end()
	{
		return const_iterator(tail);
	}
	int size() { return theSize; }
	bool empty() const { return size() == 0; }
	void clear()
	{
		while (!empty())
			pop_front();
	}
	T& front() { return *begin(); }
	const T& front() { return *begin(); }
	T& back() { return *--end(); }
	const T& back() { return *--end(); }
	void push_front(const T& x) { insert(begin(), x); }
	void push_back(const T& x) { insert(end(), x); }
	void pop_front() { erase(begin()); }
	void pop_back() { erase(--end()); }

	iterator insert(iterator itr, const T& x) //inserts x before iterator
	{
		Node* p = itr.current;
		theSize++;
		return iterator(p->prev = p->prev->next = new Node(x, p->prev, p));
	}
	iterator erase( iterator itr )//erase item at iterator
	{
		Node* p = itr.current;
		iterator retVal(p->next);
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		theSize--;

		return retVal;
	}
	iterator erase( iterator start, iterator end )
	{
		for (iterator itr = start; itr != end;)
			itr = erase(itr);

		return end;
	}

private:
	int theSize;
	Node* head;
	Node* tail;

	void init()
	{
		theSize = 0;
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
	}
};
#endif