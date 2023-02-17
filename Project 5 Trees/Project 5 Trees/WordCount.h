#pragma once
#ifndef WORDCOUNT
#define WORDCOUNT
#include <fstream>
#include <cstring>
#include "AVLTree.h"
#include "Queue.h"
class WordCount
{
private:

public:
	void readFile(string fileName) 
	{
		ifstream file(fileName);
		if (!file.is_open()) { cout << "Error opening the file " << fileName << ".\n"; return; }
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
	void addToTree()
	{
		string s, line = " ";
		while (file_Queue.queue_Size() != 0)
		{
			line = file_Queue.dequeue();
			int i = 0;
			while (i < sizeof line)
			{
				s = " ";
				while (line[i] != ' ' || line[i] != ',' || line[i] != '.')
				{
					s += line[i];
					i++;
				}
				if (!avltree.contains(s))
				{
					avltree.insert(s);
					i++;
				}
				else
				{
					avltree.count(s);
					i++;
				}
			}
		}
	}
	//void printwordCount() { avltree.AVLprintTree(); }
private:
	AVLTree <string> avltree;
	Queue<string> file_Queue;
};
#endif
