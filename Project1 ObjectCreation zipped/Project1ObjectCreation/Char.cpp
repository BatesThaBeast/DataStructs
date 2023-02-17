										/*Char class definitions*/
#include "Char.h"

//---------------------------------------------------------------------
//------------------------------Constructors---------------------------
//---------------------------------------------------------------------

/*
Function: Char 
Author: Johnathan Bates
Description: Default Constructor. Creates a empty Char class object.
Inputs: None
Outputs: None
*/
Char::Char()
{}
/*
Function: Char
Author: Johnathan Bates
Description: Constructor. Creates a Char class object and sets its data equal to a char instance.
Inputs: char
Outputs: None
*/
Char::Char(char c)
{
	this->data = c;
}
/*
Function: Char
Author: Johnathan Bates
Description: Constructor. Creates a Char class object and sets its data equal to a char instance.
Inputs: int
Outputs: None
*/
Char::Char(int c)
{
	this->data = (char)c;
}
/*
Function: Char
Author: Johnathan Bates
Description: Constructor. Creates a Char class object and sets its data equal to a char instance.
Inputs: const Char&
Outputs: None
*/
Char::Char(const Char& c)
{
	*this = c;
}
/*
Function: Char
Author: Johnathan Bates
Description: Constructor. Creates a Char class object and sets its data section equal to a char instance that appears 
first in a string.
Inputs: string
Outputs: None
*/
Char::Char(string c)
{
	this->data = c.at(0);
}
//---------------------------------------------------------------------
//------------------------------Mutators-------------------------------
//---------------------------------------------------------------------

/*
Function: equals
Author: Johnathan Bates
Description: Mutator. Sets the data section of a Char object equal to the data of another Char object.
Inputs: const Char
Outputs: None
*/
void Char::equals(const Char &c)
{
	*this = c;
}
/*
Function: equals
Author: Johnathan Bates
Description: Mutator. Sets the data section of a Char object equal to a char instance.
Inputs: char
Outputs: None
*/
void Char::equals(char c)
{
	this->data = c;
}
/*
Function: equals
Author: Johnathan Bates
Description: Mutator. Sets the data section of a Char object equal to a char instance.
Inputs: int
Outputs: None
*/
void Char::equals(int c)
{
	this->data = (char)c;
	if (c < 32 || c > 127)
		throw CharException("Invalid character");
}
//---------------------------------------------------------------------
//------------------------------Accessors------------------------------
//---------------------------------------------------------------------

/*
Function: toChar
Author: Johnathan Bates
Description: Accessor. Returns the data section(a char instance)of a Char object as a char instance
Inputs: None
Outputs: char
*/
char Char::toChar() const
{
	return this->data;
}
/*
Function: toInt
Author: Johnathan Bates
Description: Accessor. Returns the data section(a char instance)of a Char object as a int instance
Inputs: None
Outputs: int
*/
int Char::toInt() const
{
	return (int)this->data;
}
/*
Function: toString
Author: Johnathan Bates
Description: Accessor. Returns the data section(a char instance)of a Char object as a string instance
Inputs: None
Outputs: string
*/
string Char::toString()
{
	string s;
	s += this->data;
	return s;
}
/*
Function: toInt
Author: Johnathan Bates
Description: Accessor. Returns the data section(a char instance)of a Char object in hex as a string instance
Inputs: None
Outputs: string
*/
string Char::toHexString()
{
	stringstream ss;
	ss << hex << this->toInt();
	return ss.str();
}
/*
Function: operator + 
Author: Johnathan Bates
Description: Allows addition between a Char object and a char instance storing both instances in a string
Inputs: None
Outputs: string
*/
string Char::operator + (char c)
{	
	string s;
	s.push_back(this->data);
	s.push_back(c);
	return s;
}
/*
Function: operator +
Author: Johnathan Bates
Description: Allows addition between 2 Char objects storing both instances in a string
Inputs: None
Outputs: string
*/
string Char::operator + (const Char &c)
{
	Char a;
	a.equals(c);
	string s;
	s.push_back(this->data);
	s.push_back(a.toChar());
	return s;
}