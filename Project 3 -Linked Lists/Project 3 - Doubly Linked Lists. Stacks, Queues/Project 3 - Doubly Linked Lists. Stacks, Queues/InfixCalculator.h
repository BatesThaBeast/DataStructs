/*INFIXCALCULATOR CLASS: This is the class which was largely supplied by you Dr.Stevenson. Slight changes have been made obviously since the code you provided
was written in C#. Descriptions of each function are above said funtions. I did not use the doPrecedence funtion and hence it is eliminated from this version
of the class*/
#pragma once
#ifndef INFIXCALCULATOR
#define INFIXCALCULATOR
#include "RPNCalculator.h"
class InfixCalculator
{
public:
/*
Funtion:		InfixCalculator()
Author:			Johnathan Bates
Description:	Default Constructor. Creates a InfixCalculator object.  
Inputs:			None
Outputs:		None
*/
	InfixCalculator() {}
/*
Funtion:		InfixCalculator(string input)
Author:			Johnathan Bates
Description:	Constructor. Creates a InfixCalculator object taking a string input. that string is then converted with the infixToPostfix() function
then runs the RPNCalculator() function
Inputs:			string
Outputs:		None
*/
	InfixCalculator(string input) { string to_Be_Calculated = infixToPostfix(input); run_RPNCalculator(to_Be_Calculated); }
/*
Funtion:		run_RPNCalculator(string input)
Author:			Johnathan Bates
Description:	Mutator. Creates an RPNCalculator <string> object with the string input, which computes the postfix analysis of the input. Then sets the
string after_Calculation = to the solution.
Inputs:			string
Outputs:		None
*/
	void run_RPNCalculator(string input) { RPNCalculator<string> rpn_Calculator(input);	after_Calculation = rpn_Calculator.return_Solution(); }
/*
Funtion:		infixToPostfix(string expression)
Author:			Johnathan Bates
Description:	Mutator. Transforms the string input from infix to postfix. returns the transformed string to the caller
Inputs:			string
Outputs:		string
*/
	string infixToPostfix(string expression)
	{
		string postfix;
		string token;
		for (int i = 0; i < expression.length(); i++)
		{				
				token = expression[i];
				if (isOperand(token))
					postfix += token + " ";
				else if (token == "(")

					stack.push(token);
				else if (token == ")")
				{
					string topToken = stack.pop();
					while (topToken != "(")
					{
						postfix += topToken + " ";
						topToken = stack.pop();
					}
				}
				else
				{
					while (stack.stack_Size() > 0 && precedence(stack.stack_Peek()) >= precedence(token))
					{
						postfix += stack.pop() + " ";
					}
					stack.push(token);
					
				}
		}
		while (stack.stack_Size() > 0)
			postfix += stack.pop() + " ";

		return postfix;
	}
/*
Funtion:		return_Solution()
Author:			Johnathan Bates
Description:	Accessor. Returns the string after_Calculation to the caller
Inputs:			None
Outputs:		string
*/
	string return_Solution() { return after_Calculation; }
/*
Funtion:		precedence()
Author:			Johnathan Bates
Description:	Accessor. checks the string input for which operator is being inputted, and returns either 1,2,or 3, depending on the precedence set within
the function
Inputs:			string
Outputs:		int
*/
	int precedence(string x)
	{
		if (x == "+" || x == "-") { return 1; }
		if (x == "*" || x == "/" || x == "%") { return 2; }
		if (x == "^") { return 3; }
		return 0;
	}
private:
/*
Funtion:		isOperator(string c)
Author:			Johnathan Bates
Description:	Accessor. function that checks if the input is an operator
Inputs:			string
Outputs:		bool
*/
	bool isOperator(string c) { return c == "+" || c == "-" || c == "*" || c == "/" || c == "^" || c == "(" || c == ")"; }
/*
Funtion:		isOperand(string s)
Author:			Johnathan Bates
Description:	Accessor. function that checks if the input is an operand
Inputs:			string
Outputs:		bool
*/
	bool isOperand(string s) { if (!isOperator(s) && s != ")" && s != "(") { return true; } else { return false; } }
	string after_Calculation;//string used to hold the solution from postfix analysis
	Stack<string> stack;//stack used in transforming the user input into postfix format
};
#endif
