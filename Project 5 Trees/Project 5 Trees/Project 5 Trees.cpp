

#include <iostream>
#include "WordCount.h"
int main()
{
	WordCount wordcount;
	wordcount.readFile("WordCountTest.txt");
	wordcount.addToTree();
	//wordcount.printwordCount();
}


