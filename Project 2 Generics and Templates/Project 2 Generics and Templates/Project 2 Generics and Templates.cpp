// Project 2 Generics and Templates.cpp 
//Below is where I wanted to end up with this program. Unfortunately I had a family emergency I had to deal with since Friday and well,
//this program is what I ended up with, partially complete with the meat and bones nowhere near functional. I am embarrassed and I deeply apologize 
//Dr. Stevenson. I've since set myself up to never turn in a pitiful excuse of an assignment like this again.


/*To test this program, I will ask the user to input how many list they want to create. Once that has been determined, I will
ask the user to input a pair of whatever they want, be that an int, char, string, double, whatever the case. After each pair is
entered, I will ask the user if they are finished creating that list. Then that continues until the user finishes creating all 
the list they first declared. I will then print all the list to the screen, and ask the user if they want to add or delete 
any items from the list. Once the user decides, the program will either execute commands and print again or close out.
1.Get user input on HOW MANY LIST(S) are to be created
2.Get user input to FILL IN said list(s)
3.Print user input to screen
4.Ask user if they wish to either input or delete any information
5.Execute user input from step 4 or close out program
6.If code was executed from step 5, print to screen again
7.Repeat steps 4 through 6 until user decides no more input/deletion is desired
*/
#include <iostream>
#include <string>
#include "PairList.h"
int main()
{
	int x = 10;
	int y = 20;
	Pair<int> pair1(x, y);
	Pair<int> pair2(30, 40);
	Pair<int> pair3(50, 60);
	Pair<int> pair4(70, 80);
	Pair<int> pair5(90, 100);
	Pair<int> pair6(110, 120);
	LinkedList <Pair<int> >  linkedlist(pair1);
	cout << "an instance of a linked list has been created, should read 10,20\n";
	linkedlist.printList();
	cout << "now going to add 30,40 to the front of the list\n";
	linkedlist.addFront(pair2);
	linkedlist.printList();
	cout << "now going to add 50,60 to the back of the list\n";
	linkedlist.addEnd(pair3);
	linkedlist.printList();
	cout << "now going to delete 50,60 from the list\n";
	linkedlist.deleteNode(pair3);
	linkedlist.printList();
	cout << "now going to insert 50,60 after 30,40\n";
	linkedlist.insertNode(pair2, pair3);
	linkedlist.printList();
	cout << "now goint to try and insert 50,60 after 10,20(this would be a addend operation, so it should fail to insert\n";
	linkedlist.insertNode(pair1, pair3);
	cout << "now running the findnode function to search if pair 1(10,20) exist\n";
	linkedlist.findNode(pair1);
	cout << "now running the findnode function to search if pair 6(does not exist) exist\n";
	linkedlist.findNode(pair6);
	//PairList<int > pairlist(10, 20); 
	/*this is where I left off and needed to learn what to do. If you un-comment out the above line of code this program will fail*/
	return 0;

}


