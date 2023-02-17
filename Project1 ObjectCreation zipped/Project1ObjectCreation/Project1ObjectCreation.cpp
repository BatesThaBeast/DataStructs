/*This is the BigDecimal program. It is designed to handle large decimals with precision, with the ability to read said numbers
from file, seperate the whole numbers from the fractional portion and print each seperately to their own file. It contains a 
custom made Char class and BigDecimal Class. Char objects are meant to hold char instances, while BigDecimal objects serve as a 
container of Chars. Further explaination can be found within each class's header files as well as each function having details 
on it's operation.*/				
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Char.h"
#include "BigDecimal.h"

void readNumbers(string fileName);
void createFile(string fileName);
int findStrLen(string s);
vector <BigDecimal> myContainer;
int main()
{
	Char ch('A');
	Char c('B');
	int forShowInt = 87;
	//Showing functionality of all the functions used in this program from Char class and BigDecimal class
	Char showInt(forShowInt);// shows Char(int c)
	Char showCharCopy(ch);// shows  Char(const Char &c)
	Char showStringCopy("Show string being copied to Char.");// Char(string c)
	cout << "Showing  Char(int c) functionality with char toChar() const: " << showInt.toInt() << " = " << showInt.toChar() << endl;
	cout << "Showing  Char(const Char &c) functionality with char toString(): " << showCharCopy.toString() << endl;
	cout << "Showing  Char(string c) functionality with char toString(): " << showStringCopy.toString() << endl;
	cout << "Showing  string operator + (char c) functionality: " << ch + 'Z' << endl << endl;
	cout << "Now demonstrating void equals(const Char &c) " << showInt.toInt() << " now equals "; 
	showInt.equals(showCharCopy);
	cout << showInt.toChar() << endl;
	cout << "Now " << showInt.toChar() << " equals: ";
	showInt.equals(100);
	cout << showInt.toString() << endl;
	BigDecimal test1("140.67896");
	BigDecimal test2("100.26484");//demonstrating operator overloads of + and -. When adding = 240.9438. When subtracting = 40.41412
	BigDecimal equals = test1 + test2;
	cout << test1.toString() << " + " << test2.toString() << " = " << equals.toString() << endl;
	equals = test1 - test2;
	cout << test1.toString() << " - " << test2.toString() << " = " << equals.toString() << endl;
	cout << ch + c << endl; //Showing functionality of string operator + (const Char& c);
	cout << ch.toChar() << " In Hex is " << ch.toHexString() << endl;//Showing functionality of string toHexString()
	cout << ch.toChar() << " In Decimal " << ch.toInt() << endl;//Showing functionality of int toInt() const
	
	try
	{
		cout << "Try to set character to 140" << endl;
		ch.equals(140);
		cout << ch.toChar() << endl;
	}
	catch(CharException ce)
	{
		cout << ce.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown Error. " << endl;
	}
	BigDecimal A("39.987654.4");
	BigDecimal B("47.65478tr");
	readNumbers("Numbers.txt");
	createFile("wholeNumber.txt");
	createFile("fraction.txt");
	

	return 0;
}
/*
Function: readNumbers
Author: Johnathan Bates
Description: Takes a line from a file and inputs each line into a BigDecimal object, then stores that BigDecimal object into a 
vector named myContainer.
Inputs: string
Outputs: None
*/
void readNumbers(string fileName)
{
	ifstream file(fileName);
	if (!file)
	{
		cout << "Error opening " << fileName << " to read. " << endl;
		return;
	}
	string s;
	while (!file.eof())
	{
		getline(file, s);
		BigDecimal B(s);
		myContainer.push_back(B);
	}
	file.close();
}
/*
Function: createFile
Author: Johnathan Bates
Description: Creates either a file of only the whole number portion of all stored in a BigDecimal object or a file of only the 
decimal number portion of all instances stored in a BigDecimal object
Inputs: string
Outputs: Creates file
*/
void createFile(string fileName)
{
	ofstream file(fileName);
	if (!file)
	{
		cout << "Error opening "<< fileName << " to write to. " << endl;
		return;
	}
	
		if (fileName == "fraction.txt")
		{
			int j = 0;
			double d;
			for (size_t i = 0; i < myContainer.size() - 1; i++)
			{
				j = findStrLen(myContainer.at(i).toString()) - 3;
				d = myContainer.at(i).fraction();
				file << setprecision(j) << d << endl;
				
			}
			file.close();
		}
		if (fileName == "wholeNumber.txt")
		{
			for (size_t i = 0; i < myContainer.size() - 1; i++)
			{
				file << myContainer.at(i).wholeNumber() << endl;
			}
			file.close();
			
		}
	
}
/*
Function: findStrLen
Author: Johnathan Bates
Description: Counts how many characters make up a string
Inputs: string
Outputs: int
*/
int findStrLen(string s)
{
	int amt = 0;
	for (int i = 0; s[i]; i++)
	{
		amt++;
	}
	return amt;
}