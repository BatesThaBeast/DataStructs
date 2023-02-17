												/*Char Class*/
/*This is the base class for this BigDecimal project. The Char object has a data section that is a primative data type char. It
is capable of being constructed with chars, ints, another Char object, and the first character in a string. The mutators allow
the Char object to be set equal to another Char object, int, or a char. Char is able to access it's data section and return it 
as an char, int, string, and string in hex notation. It also has the ability to add to another Char object or a char by
overloading the operator +.*/

												/*Exceptions*/
/*This Char class is derived from the exception class and is built to handle undesired char inputs, such as an int that would
not convert to ASCII char */

#pragma once
#include <exception>
#include <ios>
#include <string>
#include <sstream>
using namespace std;

#ifndef CHAR
#define CHAR

class CharException :
	public exception
{
public:
	CharException() : errorMsg("This is an Invalid character. "){}
	CharException(string msg) : errorMsg(msg){}
	virtual const char* what() { return errorMsg.c_str(); }
private:
	string errorMsg;
};

class Char
{
public:
//---------------------------------------------------------------------
//-----------------------------Constructors----------------------------
//---------------------------------------------------------------------
	Char();
	Char(char c);
	Char(int c);
	Char(const Char &c);
	Char(string c);
//---------------------------------------------------------------------
//------------------------------Mutators-------------------------------
//---------------------------------------------------------------------
	void equals(const Char &c);
	void equals(char c);
	void equals(int c);
//---------------------------------------------------------------------
//------------------------------Accessors------------------------------
//---------------------------------------------------------------------
	char toChar() const;
	int toInt() const;
	string toString();
	string toHexString();
	string operator + (char c);
	string operator + (const Char& c);
private:
	char data = (char)0;
};
#endif