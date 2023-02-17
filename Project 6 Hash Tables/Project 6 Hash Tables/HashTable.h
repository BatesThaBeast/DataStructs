/*I need: --ability to print one entry; as in a persons name, its hash value, and phone number--
--read from file  the phone number list--*/

#pragma once
#ifndef HASHTABLE
#define HASHTABLE
#include "DoublyLinkedList.h"
#include <vector>
#include <iomanip>
#include <string>

class HashTable 	
{
private:
	/*
	Funtion:		hashFunc(const double key)
	Author:			Johnathan Bates
	Description:	Accessor. Hash Function that divides the input by the tablesize and returns the remainder
	Inputs:			const double
	Outputs:		Int
	*/
	int hashFunc(const double key) { return static_cast<int>(key) % this->TABLESIZE; }
	/*
	Funtion:		hashFunc(const double key)
	Author:			Johnathan Bates
	Description:	Accessor. Hash Function that divides the input by the tablesize and returns the remainder
	Inputs:			const string
	Outputs:		Int
	*/
	int hashFunc(const string key) { int i = stringTOInt(key); return i % this->TABLESIZE; }
	/*
	Funtion:		contains(string x)
	Author:			Johnathan Bates
	Description:	Accessor. checks to see if an item exist in the hash table
	Inputs:			string
	Outputs:		bool
	*/
	bool contains(string x) { return this->search(x) > 0; }
	/*
	Funtion:		contains(string x)
	Author:			Johnathan Bates
	Description:	Accessor. checks to see if an item exist in the hash table
	Inputs:			double
	Outputs:		bool
	*/
	bool contains(double x) { return this->search(x) > 0; }
	int TABLESIZE = 0;
	vector <DoublyLinkedList<string> > HTVector;//vector to hold doublylinkedlist of strings
	vector <DoublyLinkedList<double> > HTNUMVector;//vector to hold doublylinkedlist of doubles
public:
	/*
	Funtion:		HashTable()
	Author:			Johnathan Bates
	Description:	Constructor. Creates an instance of the HashTable object. sets the variable TABLESIZE to 50 and resizes the vector to TABLESIZE
	Inputs:			None
	Outputs:		None
	*/
	explicit HashTable() { this->TABLESIZE = 50; HTVector.resize(TABLESIZE); HTNUMVector.resize(TABLESIZE); }
	/*
	Funtion:		HashTable(int tableSize)
	Author:			Johnathan Bates
	Description:	Constructor. Creates an instance of the HashTable object. sets the variable TABLESIZE to the input and resizes the vector to TABLESIZE
	Inputs:			Int
	Outputs:		None
	*/
	HashTable(int tableSize) { this->TABLESIZE = tableSize; HTVector.resize(TABLESIZE); HTNUMVector.resize(TABLESIZE); }
	/*
	Funtion:		djbHash(string str)
	Author:			Johnathan Bates
	Description:	Accessor. Function that after it computes decides where to place item in the HashTable
	Inputs:			String
	Outputs:		Int
	*/
	int djbHash(string str)
	{
		int hashVal = 5381;  
		for(int i = 0; i < str.length(); i++)
		{
			hashVal *= 33;
			hashVal += static_cast<int>(str[i]);
		}
		
		hashVal %= TABLESIZE;
		if (hashVal > 0)
		{
			return hashVal;
		}
		else
		{
			hashVal *= -1;
			return hashVal;
		}
	}
	/*
	Funtion:		hash(const string& s, const string& x)
	Author:			Johnathan Bates
	Description:	Mutator. Overload.stores inputted value into the hash table. Hanldes collision in that the input is added to the end of the list at that
					particular place in the vector
	Inputs:			Reference to Template data
	Outputs:		None
	*/
	void hash(string& s, const double& x)
	{
		if (this->contains(s) == true)
		{
			HTVector[djbHash(s)].addEnd(s);
			HTNUMVector[djbHash(s)].addEnd(x);
		}
		else
			HTVector[djbHash(s)].addFront(s);
		HTNUMVector[djbHash(s)].addFront(x);
	}
	/*
	Funtion:		hash(const double& value)
	Author:			Johnathan Bates
	Description:	Mutator. Overload.stores inputted value into the hash table. Hanldes collision in that the input is added to the end of the list at that
					particular place in the vector
	Inputs:			Reference to Template data
	Outputs:		None
	*/
	void hash(const double& x)
	{
		if (this->contains(x) == true)
		{
			HTNUMVector[hashFunc(x)].addEnd(x);
		}
		else
			HTNUMVector[hashFunc(x)].addFront(x);
	}
	/*
	Funtion:		hash(const T& value)
	Author:			Johnathan Bates
	Description:	Mutator. stores inputted value into the hash table. Hanldes collision in that the input is added to the end of the list at that
					particular place in the vector
	Inputs:			Reference to Template data
	Outputs:		None
	*/
	void hashString(string& x)
	{
		if (this->contains(x) == true)
		{
			HTVector[djbHash(x)].addEnd(x);
		}
		else
			HTVector[djbHash(x)].addFront(x);
	}
/*
Funtion:		search(double value)
Author:			Johnathan Bates
Description:	Accessor. returns the number of occurrences the inputted value appears in the table.
Inputs:			Double
Outputs:		Int
*/
	int search(double x) { return this->HTNUMVector[hashFunc(x)].countCopies(x); }
	/*
Funtion:		search(double value)
Author:			Johnathan Bates
Description:	Accessor. returns the number of occurrences the inputted value appears in the table.
Inputs:			Double
Outputs:		Int
*/
	int search(string x) { return this->HTVector[djbHash(x)].countCopies(x); }
	/*
	Funtion:		printNUMTable()
	Author:			Johnathan Bates
	Description:	Accessor. prints all of the values in the table to the screen.
	Inputs:			None
	Outputs:		None
	*/
	void printNUMTable()
	{
		cout << "Now printing the contents of the Hashtable.\n";
		for (int i = 0; i < TABLESIZE; i++)
		{
			HTNUMVector[i].printListForward();
		}
	}
	/*
	Funtion:		getEntry(const string& x)
	Author:			Johnathan Bates
	Description:	Accessor. Will output to screen item at Hashed location in both HTVector and HTNUMVector
	Inputs:			String
	Outputs:		None
	*/
	void getEntry(const string& x)
	{
		if (this->contains(x) == true)
		{
			
			
			int i = HTVector[djbHash(x)].findIndex(x);
			string outputName = HTVector[djbHash(x)].returnNodeATIndex(i);
			string outputNum = inputSymbols(HTNUMVector[djbHash(x)].returnNodeATIndex(i));
			if (i > 0)
			{
				cout << outputName << "(" << djbHash(x) << " - " << i << ") " << outputNum << endl;
			}
			else

			{
				cout << outputName << "(" << djbHash(x) << ") " << outputNum << endl;
			}
		}
		else
			cout << "That entry does not exist in the Hash Table.\n";
	}
	/*
	Funtion:		remove(const string& x)
	Author:			Johnathan Bates
	Description:	Mutator. Checks to see if an item exists in the hash table and removes it if it does.
	Inputs:			Constant String Data
	Outputs:		None
	*/
	void remove(const string& x)
	{
		if (this->contains(x) == true)
		{
			HTVector[hashFunc(x)].deleteNode(x);
		}
	}
	/*
	Funtion:		remove(const double& x)
	Author:			Johnathan Bates
	Description:	Mutator. Checks to see if an item exists in the hash table and removes it if it does.
	Inputs:			Constant Double
	Outputs:		None
	*/
	void remove(const double& x)
	{
		if (this->contains(x) == true)
		{
			HTNUMVector[hashFunc(x)].deleteNode(x);
		}
	}
	/*
	Funtion:		makeStringEmpty()
	Author:			Johnathan Bates
	Description:	Mutator. Removes every item from the Hash Table
	Inputs:			None
	Outputs:		None
	*/
	void makeStringEmpty()
	{
		for (int i = 0; i < HTVector.size(); i++)
		{
			while(HTVector[i].size_of_List() != 0)
			HTVector[i].deleteFrontNode();
		}
		cout << "HashTable is now empty.\n";
	}
	/*
	Funtion:		makeDoubleEmpty()
	Author:			Johnathan Bates
	Description:	Mutator. Removes every item from the Hash Table
	Inputs:			None
	Outputs:		None
	*/
	void makeDoubleEmpty()
	{
		for (int i = 0; i < HTVector.size(); i++)
		{
			while (HTNUMVector[i].size_of_List() != 0)
				HTNUMVector[i].deleteFrontNode();
		}
		cout << "HashTable is now empty.\n";
	}
	/*
	Funtion:		stringTOInt((const string& s)
	Author:			Johnathan Bates
	Description:	Mutator. Takes the string input and adds up the ASCII value of every character then returns the sum as an Int.
	Inputs:			String
	Outputs:		Int
	*/
	int stringTOInt(const string& s)
	{
		int j = 0;
		for (int i = 0; i < s.length(); i++)
		{
			j += static_cast<int>(s[i]);
		}
		return j;
	}
	/*
	Funtion:		inputSymbols((const double& s)
	Author:			Johnathan Bates
	Description:	Mutator. For phone numbers. Takes a double and places () and - into the string ex. (555)555-5555
	Inputs:			Const Double
	Outputs:		String
	*/
	string inputSymbols(const double& d)
	{
		string s = to_string(d);
		s.insert(0, "(");
		s.insert(4, ")");
		s.insert(8, "-");
		s.erase(13, 10);
		return s;
	}
};
#endif
