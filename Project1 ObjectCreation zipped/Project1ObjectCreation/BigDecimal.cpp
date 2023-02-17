										/*BigDecimal class definitions*/

#include "BigDecimal.h"
#include <iostream>
#include <iomanip>
using namespace std;
//---------------------------------------------------------------------
//------------------------------Constructors---------------------------
//---------------------------------------------------------------------

/*
Function: BigDecimal
Author: Johnathan Bates
Description: Default Constructor. Creates a Big Decimal object and fills the container with 3 Char class objects, '0','.','0'
Inputs: No Input
Outputs: No Output
*/
BigDecimal::BigDecimal() 
{
	this->push_back(new Char('0'));
	this->push_back(new Char('.'));
	this->push_back(new Char('0'));
}
/*
Function: BigDecimal
Author: Johnathan Bates
Description: Constructor. Creates a BigDecimal object and fills it with chars from the string input
Inputs: string
Outputs: No Output
*/
BigDecimal::BigDecimal(string value) : BigDecimal()
{
	this->equals(value);
}
//---------------------------------------------------------------------
//------------------------------Mutators-------------------------------
//---------------------------------------------------------------------

/*
Function: equals
Author: Johnathan Bates
Description: Mutator. Clears the BigDecimal container and fills it with the char input
Inputs: char
Outputs: No Output
*/
void BigDecimal::equals(char ch)
{
	this->clear();
	try
	{
		if (isdigit(ch) || ch == '.')
		{
			this->push_back(new Char(ch));
		}
		if (!isdigit(ch) || ch != '.')
			throw BigDecimalException("Invalid Character");
	}
	catch (BigDecimalException bde)
	{
			cout << bde.what() << endl;
	}
}
/*
Function: equals
Author: Johnathan Bates
Description: Mutator. Clears the BigDecimal container and fills it with each char from the string object. Includes exceptions in 
the cases where invalid inputs occur, being:2 decimal points or letters instead of numbers. 
Inputs: string
Outputs: No Output
*/
void BigDecimal::equals(string value)
{
	
	this->clear();
	int dec = 0;
	try
	{
		for (size_t i = 0; i < value.length() && dec < 2; i++)
		{
			if (value[i] == '.')
			{
				dec++;
				if (dec <= 1)
				{
					this->push_back(new Char(value[i]));
				}
				if (dec == 2)
					throw BigDecimalException("Error, cannot have 2 decimals in number");
			}
			if (isdigit(value[i]))
			{
				this->push_back(new Char(value[i]));
			}
			else if (value[i] != '.' && !isdigit(value[i]))
			{
				i = value.length();
				throw BigDecimalException("Error, invalid character");
			}

		}
	}
	catch (BigDecimalException bde)
	{
		cout << bde.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown Error. " << endl;
	}
}
/*
Function: BigDecimal operator + overload
Author: Johnathan Bates
Description: Mutator. Overloads + operator and allows the ability to add 2 BigDecimal objects together and returns their sum
in another BigDecimal object
Inputs: BigDecimal
Outputs: BigDecimal 
*/
BigDecimal BigDecimal::operator +(BigDecimal m1)
{	
	double a = this->toDouble(), b = m1.toDouble(), c;
	c = a + b;
	BigDecimal d(to_string(c));
	return d;
}
/*
Function: BigDecimal operator - overload
Author: Johnathan Bates
Description: Mutator. Overloads - operator and allows the ability to subtract 1 BigDecimal object from another, returning
the difference to a BigDecimal object
Inputs: BigDecimal
Outputs: BigDecimal 
*/
BigDecimal BigDecimal::operator -(BigDecimal m1)
{
	double a = this->toDouble(), b = m1.toDouble(), c;
	c = a - b;
	BigDecimal d(to_string(c));
	return d;
}
//---------------------------------------------------------------------
//------------------------------Accessors------------------------------
//---------------------------------------------------------------------

/*
Function: toDouble
Author: Johnathan Bates
Description: Accessor. Cast data stored in BigDecimal object to double using string stream
Inputs: No input
Outputs: double
*/
double BigDecimal::toDouble()
{	
	int i = (this->toString().length()) - 3;
	std::stringstream ss;	
	ss << std::setprecision(i) << this->toString();
	double d;
	ss >>  d;
	return d;	
}
/*
Function: toString
Author: Johnathan Bates
Description: Accessor. Cast data stored in BigDecimal object to a string. 
Inputs: No input
Outputs: string
*/
string BigDecimal::toString()
{
	string s;
	for (size_t i = 0; i < this->size(); i++)
	{
		s.push_back(this->at(i).toChar());
	}
	return s;
}
/*
Function: at overload
Author: Johnathan Bates
Description: Accessor. Returns Char object at specified index stored in BigDecimal object.
Inputs: Int
Outputs: Char 
*/
Char BigDecimal::at(int index)
{
	Char* a = this->vector::at(index);
	return *a;
}
/*
Function: wholeNumber
Author: Johnathan Bates
Description: Accessor. Cast a BigDecimal object as a double, then cast that double instance as an int object leaving only the
whole number portion left.
Inputs: None
Outputs: int 
*/
int BigDecimal::wholeNumber()
{
	int a = (int)this->toDouble();
	return a;
}
/*
Function: fraction
Author: Johnathan Bates
Description: Accessor. Removes the whole number portion of a BigDecimal object then cast the decimal portion as a double.
Inputs: None
Outputs: double 
*/
double BigDecimal::fraction()
{	
	double d1 = this->toDouble(), d2 = (double)this->wholeNumber(), d3;
	d3 = d1 - d2;
	
	return d3;
}
/*
Function: findDecimal
Author: Johnathan Bates
Description: Accessor. Parses the string inside a BigDecimal to find the position of the decimal, helping to set the precision
in toDouble.
Inputs: string
Outputs: int
*/


