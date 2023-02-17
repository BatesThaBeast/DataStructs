// Project 6 Hash Tables.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include <iostream>
#include <string>
#include "HashTable.h"
/*
	Funtion:		testingHashTable()
	Author:			Johnathan Bates
	Description:	Function that uses most of the functions within HashTable Class
	Inputs:			None
	Outputs:		None
	*/
void testingHashTable();
/*
	Funtion:		readFile(string fileName, HashTable hash)
	Author:			Johnathan Bates
	Description:	Function that reads file and inputs the data into a hash table
	Inputs:			String, HashTable
	Outputs:		None
	*/
void readFile(string fileName, HashTable hash);
/*
	Funtion:		lookUp(HashTable hashtable)
	Author:			Johnathan Bates
	Description:	Function that takes user input and outputs to the screen the user's position in hash table and the phone number
	Inputs:			HashTable
	Outputs:		None
	*/
void lookUp(HashTable hashtable);
/*
	Funtion:		checkAgain(HashTable hashtable)
	Author:			Johnathan Bates
	Description:	Function that takes user input to see if they want to check for another item in hashtable
	Inputs:			HashTable
	Outputs:		None
	*/
void checkAgain(HashTable hashtable);
int main()
{
	testingHashTable();
	HashTable myHash(53);
	readFile("Hashdata.txt", myHash);
	cout << "Now we will test looking up phone numbers.\n";
	lookUp(myHash);
}
void testingHashTable()
{
	HashTable testHashTable;
	testHashTable.hash(127.123456789);
	testHashTable.hash(181.123456789);
	testHashTable.hash(134.123456789);
	testHashTable.hash(177.123456789);
	testHashTable.hash(77.123456789);
	testHashTable.hash(81.123456789);
	testHashTable.hash(84.123456789);
	testHashTable.hash(127.123456789);
	testHashTable.hash(181.123456789);
	cout << "181.123456789 appears " << testHashTable.search(181.123456789) << " time(s) in the table.\n";
	cout.precision(15);
	testHashTable.printNUMTable();
	testHashTable.remove(181.123456789);
	cout << "181.123456789 now appears " << testHashTable.search(181.123456789) << " time(s) in the table.\n";
	testHashTable.printNUMTable();
	testHashTable.makeDoubleEmpty();
}
void readFile(string fileName, HashTable hash)
{
	ifstream file(fileName);//looks for file (fileName) and opens it
	if (!file)//check if file failed to open
	{
		cout << "Error opening " << fileName << " to read. " << endl;
		return;
	}
	else//file was found and opened
	{
		string s;//string used to hold a line from the file
		
		
		while (!file.eof())//check to see if the file has ended
		{
			double phoneNum = 0.0;
			string name = "";//string used to hold the persons name
			string num = "";//string used to hold the phone number
			getline(file, s);//takes in a line from file and stores it as a string in s
			for (int i = 0; i < s.length(); i++)
			{
				if (isalpha(s[i]))
				{
					name += s[i];
				}
				if (isdigit(s[i]))
				{
					num += s[i];
				}
			}
			if(num != "")
			phoneNum = stod(num);
			hash.hash(name, phoneNum);
		}
		file.close();//closes file	
	}
}
void lookUp(HashTable hashtable)
{
	cout << "Enter name: ";
	string input;
	cin >> input;
	hashtable.getEntry(input);
	checkAgain(hashtable);	
}
void checkAgain(HashTable hashtable)
{
	cout << "Look up another number <Y / N>";
	char yorn;
	cin >> yorn;
	if (toupper(yorn) == 'Y')
	{
		lookUp(hashtable);
	}
	if (toupper(yorn) == 'N')
	{
		return;
	}
	else
	{
		cout << "Invalid entry, please enter either y or n.\n";
		checkAgain(hashtable);
	}
}
