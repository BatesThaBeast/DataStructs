/*RPNCALCULATOR CLASS: This class inherits the Stack Class, therefore it "is-a" Stack. It is a simple class, that when constructed immediately performs 
postfix analysis of the input. It has two functions, remove_Spaces which parses the inputed string for spaces and removes them and return_Solution, which
returns the solution of the input to the caller. I chose inheritance for this class for ease of making calls to the base classes it uses, as it was easier
for me to program.*/
#pragma once
#ifndef RPNCALCULATOR
#define RPNCALCULATOR
#include "Stack.h"//uses the stack class
template <class T>
class RPNCalculator :
	public Stack<T>
{
public:
/*
Funtion:		RPNCalculator()
Author:			Johnathan Bates
Description:	Default Constructor. Creates a RPNCalculator object which is itself a Stack. Uses the Stack constructor
Inputs:			None
Outputs:		None
*/
	RPNCalculator() : Stack<T>() {}
/*
Funtion:		RPNCalculator(string input)
Author:			Johnathan Bates
Description:	Constructor. Creates a RPNCalculator object which is itself a Stack. This function calculates a string of 
numbers in postfix form and stores the answer in the string DATA
Inputs:			String
Outputs:		None
*/
	RPNCalculator(string input)
	{
		string DATA = this->remove_Spaces(input);
		string convert;
		for (int i = 0; DATA[i]; i++)
		{
			if (isdigit(DATA[i]))
			{
				convert = DATA[i];
				this->push(convert);
			}
			else if (DATA[i] == '+')
			{
				int a = stoi(this->pop());
				int b = stoi(this->pop());
				this->push(to_string(a + b));
			}
			else if (DATA[i] == '-')
			{
				int a = stoi(this->pop());
				int b = stoi(this->pop());
				this->push(to_string(b - a));
			}
			else if (DATA[i] == '*')
			{
				int a = stoi(this->pop());
				int b = stoi(this->pop());
				this->push(to_string(a * b));
			}
			else if (DATA[i] == '/')
			{
				int a = stoi(this->pop());
				int b = stoi(this->pop());
				int c = b / a;
				this->push(to_string(c));
			}
		}

	}
/*
Funtion:		return_Solution()
Author:			Johnathan Bates
Description:	Accessor. Returns the solution from the RPNCalculator constructor, which is held in the stack
Inputs:			None
Outputs:		string
*/
	string return_Solution() { return this->pop(); }

/*
Funtion:		remove_Spaces(string input)
Author:			Johnathan Bates
Description:	Mutator. Parses the string for spaces and removes them. Preps the string for postfix calculations
Inputs:			string
Outputs:		None
*/
	string remove_Spaces(string input)
	{
		int count = 0;
		for (int i = 0; input[i]; i++)
		{
			if (input[i] != ' ')
			{
				input[count++] = input[i];
			}
		}
		input[count] = '\0';
		return input;
	}
};
#endif