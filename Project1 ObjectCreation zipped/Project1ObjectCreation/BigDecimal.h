												/*BigDecimal Class*/
/*BigDecimal class is derived from the Char Class as well as vector class, making it a designated container pointing to Char 
objects and allowing it to use Char class mutators and accessors. It is meant as it's name implies to hold a representation of
large decimal numbers BigDecimals are able to be constructed empty, giving it a default value of 0.0 or intake a string. When 
intaking a string for construction, BigDecimal converts each character into a Char class object, and stores them within it's 
container. BigDecimal is able to be mutated and set equal to a char or string, which clears what it previously held in the
container and sets it equal to the new data. BigDecimal has overloads for operators + and -, giving it the ability to either 
add or subtract from another BigDecimal object. BigDecimal is able to access it's container and return it as a double, 
string, the whole number portion of its data or the fractional part. Finally BigDecimal overloads the at() funtion allowing it
return a Char object at the desired position.*/

													/*Exceptions*/
/*This BigDecmial class is derived from the Char exception class, which is further derived from the base exception class.
It is built to handle undesired char inputs, such as a char that isn't a digit. It can check to see if it has already recieved
a decimal point and not take another, as that would not be a standard decimal number.*/

#pragma once
#include "Char.h"
#include <vector>
#include <cstdlib>

#ifndef BIGDECIMAL
#define BIGDECIMAL

class BigDecimalException :
	public CharException
{
public:
	BigDecimalException() : CharException(){}
	BigDecimalException(string msg) : CharException(msg){}
};

class BigDecimal : 
	public Char , public vector <Char*>
{
public:
//---------------------------------------------------------------------
//-----------------------------Constructors----------------------------
//---------------------------------------------------------------------
	BigDecimal();
	BigDecimal(string value);
//---------------------------------------------------------------------
//------------------------------Mutators-------------------------------
//---------------------------------------------------------------------
	void equals(char ch);
	void equals(string value);
	BigDecimal operator +(BigDecimal m1);
	BigDecimal operator -(BigDecimal m1);
//---------------------------------------------------------------------
//------------------------------Accessors------------------------------
//---------------------------------------------------------------------
	double toDouble();
	string toString();
	Char at(int index);

	int wholeNumber();
	double fraction();
};

#endif