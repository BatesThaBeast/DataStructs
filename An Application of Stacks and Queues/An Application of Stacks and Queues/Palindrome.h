
#pragma once
#ifndef PALINDROME
#define PALINDROME
#include <fstream>//Used for file I/O stream
#include "Stack.h"
#include "Queue.h"
using namespace std;
class Palindrome
{
public:
/*
Funtion:		Palindrome()
Author:			Johnathan Bates
Description:	Constructor.Default constructor, if no file is inputed during construction then this is the constructor used
Inputs:			None
Outputs:		None
*/
	Palindrome() {}
/*
Funtion:		Palindrome()
Author:			Johnathan Bates
Description:	Constructor.Default constructor, if no file is inputed during construction then this is the constructor used
Inputs:			None
Outputs:		None
*/
	Palindrome(string fileName) { read_File(fileName), check_File(), write_File(); }
/*
Funtion:		read_File(string fileName)
Author:			Johnathan Bates
Description:	Mutator. Opens file and reads each line of text, enqueuing it into file_Queue.
Inputs:			string
Outputs:		None
*/
	void read_File(string fileName)
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
					getline(file, s);//takes in a line from file and stores it as a string in s
					file_Queue.enqueue(s);//puts the line stored in string s into the queue
				}
				file.close();//closes file	
			}
	}
/*
Funtion:		check_File()
Author:			Johnathan Bates
Description:	Mutator. checks each string stored within the file_Queue to see if it is a palindrome. If it is, it is stored in is_Palindrome_Queue
Inputs:			None
Outputs:		None
*/
	void check_File()
	{
		string s;
		while (file_Queue.queue_Size() != 0)//will go through every string enqueued in file_Queue
		{
			s = file_Queue.dequeue();//sets string s eqaul to the string dequeued from file_Queue
			check_String(s);//
			if (palindrome_Check_Queue.queue_Size() == 0)//check to see if end of string was reached, which means it is a palindrome
			{
				cout << s << " is a palindrome.\n";
				is_Palindrome_Queue.enqueue(s);//queue that is to be used to write the palindromes to file
			}
			else//current string being analyzed is not a palindrome
			{
				cout << s << " is not a palindrome.\n";
				//clearing the queue and the stack for the next round of palindrome checking
				palindrome_Check_Queue.clear_Queue();
				palindrome_Check_Stack.clear_Stack();
			}
		}
	}
/*
Funtion:		write_File()
Author:			Johnathan Bates
Description:	Mutator. Writes strings stored in is_Palindrome_Queue to a file named Palindrome.txt
Inputs:			None
Outputs:		None
*/

	void write_File()
	{
		if (is_Palindrome_Queue.queue_Size() != 0)//check to see if any strings analyzed were palindromes. If queue is empty, no palindromes were found
		{
			ofstream file("Palindrome.txt");//creates the file Palindrome.txt
			if (!file)//check to make sure the file was opened/created
			{
				cout << "Error opening " << "Palindrome.txt" << " to write to. " << endl;
				return;
			}
			while (is_Palindrome_Queue.queue_Size() != 0)//loop to run till the queue is emptied
			{
				file <<  is_Palindrome_Queue.dequeue() << endl;//writing strings to file
			}
		}
	}
	/*
Funtion:		check_String()
Author:			Johnathan Bates
Description:	Mutator. loads the string into the Queue and Stack, then compares that strings beginning vs the end
Inputs:			string
Outputs:		None
*/
	void check_String(string input)
	{
		char f, b;//these chars will hold characters starting from the beginning of a string and the end of the string respectively
		for (size_t i = 0; i < input.length(); i++)//loading both palindrome_Check_Queue & palindrome_Check_Stack with each character in string s
		{
			if (input[i] != ' ')//checks for a space, as we want to eliminate spaces for the check
			{
				palindrome_Check_Queue.enqueue(tolower(input[i]));//puts character into the queue
				palindrome_Check_Stack.push(tolower(input[i]));//puts character onto the stack
			}
		}
		f = ' ';//initializing char f to empty char before loop starts. we want to do this here as when we return to this loop f needs to be empty so as not to skip the loop
		b = ' ';//initializing char b just as f
		while (f == b && palindrome_Check_Queue.queue_Size() != 0)//either the characters do not match, or the string has ended and it is a palindrome
		{
			f = palindrome_Check_Queue.dequeue();//f or front, starts at front end of string which is being dequeued--FIFO
			b = palindrome_Check_Stack.pop();//b or back, starts at rearend of string which is being popped--FILO
		}
	}
private:
	Queue <char> palindrome_Check_Queue;//will be used to store each character in a given string. dequeuing will analyze the string from start to end
	Queue <string> file_Queue;//will be used to intake strings from file
	Queue <string> is_Palindrome_Queue;//will be used to store each string that is in fact a palindrome
	Stack <char> palindrome_Check_Stack;//will be used to store each character in a given string. popping will essentially analyze the string in reverse
};
#endif
