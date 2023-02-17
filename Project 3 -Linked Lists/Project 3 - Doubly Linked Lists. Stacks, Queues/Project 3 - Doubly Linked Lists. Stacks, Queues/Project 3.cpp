// Project 3 - Doubly Linked Lists. Stacks, Queues.cpp 
/*To change the input of what is being calculated, go the the defintion of void testInfixCalculator() and change the string "testing". This calculator is not
built to handle variables(letters), modulus or integers that are more than 1 digit. Descriptions of each funtion are located above said function, as well as
class descriptions at the top of the included header files.*/

#include <iostream>
#include "Queue.h"
#include "InfixCalculator.h"

using namespace std;
/*
Funtion:		testDoublyLinkedList()
Author:			Johnathan Bates
Description:	Funtion that test the different functions within DOUBLYLINKEDLIST class
Inputs:			None
Outputs:		None
*/
void testDoublyLinkedList();
/*
Funtion:		testStack()
Author:			Johnathan Bates
Description:	Funtion that test the different functions within STACK class
Inputs:			None
Outputs:		None
*/
void testStack();
/*
Funtion:		testQueue()
Author:			Johnathan Bates
Description:	Funtion that test the different functions within QUEUE class
Inputs:			None
Outputs:		None
*/
void testQueue();
/*
Funtion:		testRPNCalculator()
Author:			Johnathan Bates
Description:	Funtion that test the different functions within RPNCALCULATOR class
Inputs:			None
Outputs:		None
*/
void testRPNCalculator();
/*
Funtion:		testInfixCalculator()
Author:			Johnathan Bates
Description:	Funtion that test INFIXCALCULATOR class with a particular input. to change input as described above, scroll down to the definition of this 
function and change the string "testing:
Inputs:			None
Outputs:		None
*/
void testInfixCalculator();
int main()
{	
	testInfixCalculator();
	testDoublyLinkedList();
	testStack();
	testRPNCalculator();
}
void testInfixCalculator()
{
	/*to test the calculator, change the string */
	string testing = "4 - 2 + ( 8 * 2 ) / 2";//with current input the result will be 10
	InfixCalculator infCalc(testing);
	cout << testing << " = " << infCalc.return_Solution() << endl << endl;
}
void testRPNCalculator()
{
	string test_Calc = "2 3 + 4 *";	
	RPNCalculator<string> test_1(test_Calc);
	cout << "This is a test of the RPNCalculator\n";
	cout << test_Calc + " = " << test_1.return_Solution() << endl;
}
void testStack()
{
	int a, b, c, d;
	a = 10;
	b = 20;
	c = 30;
	d = 40;
	Stack<int> testStack(a);//testing constructor
	testStack.push(b);//testing push function
	testStack.push(c);
	testStack.push(d);
	testStack.push(a);
	testStack.push(b);
	testStack.push(c);
	testStack.push(d);
	testStack.push(a);
	testStack.push(b);
	testStack.push(c);
	testStack.push(d);
	testStack.printListForward();//this should display in reverse of the order the numbers were pushed in. there are 12 inputs, 10, 20, 30, 40 3 times
	testStack.printListBackward();//this will display the opposite of printlistforward
	testStack.pop();//testing pop function
	testStack.pop();
	testStack.pop();
	testStack.pop();
	testStack.pop();
	testStack.pop();
	testStack.printListForward();//six inputs have been popped from the stack, there will be six left. 10,20,30,40,10,20
	testStack.printListBackward();
	cout << testStack.stack_Peek() << " is on the top of the stack.\n";
	cout << testStack.stack_Size() << " is the size of the stack.\n";
	testStack.clear_Stack();
	cout << "Now the stack has " << testStack.stack_Peek() << " elements in it.\n";
}
void testQueue()
{
	int a, b, c, d;
	a = 10;
	b = 20;
	c = 30;
	d = 40;
	Queue<int> testQueue(a);
	testQueue.enqueue(b);
	testQueue.enqueue(c);
	testQueue.enqueue(d);
	testQueue.enqueue(a);
	testQueue.enqueue(b);
	testQueue.enqueue(c);
	testQueue.enqueue(d);
	testQueue.enqueue(a);
	testQueue.enqueue(b);
	testQueue.enqueue(c);
	testQueue.enqueue(d);
	testQueue.printListForward();
	testQueue.printListBackward();
	int e = testQueue.dequeue();
	cout << e << " was just dequeue'd from the queue.\n";
	cout << testQueue.queue_Peek_Front() << " is at the front of the list now.\n";
	cout << testQueue.queue_Peek_Rear() << " is at the rear of the list.\n";
	cout << testQueue.queue_Size() << " is how many items are in the queue.\n";
	cout << "Now we are going to clear the queue.\n";
	testQueue.clear_Queue();
	cout << testQueue.queue_Size() << " is how many items are in the queue.\n";


}
void testDoublyLinkedList()
{
	//creating a bunch of strings to test my doublylinkedlist class
	string first = "This is the first string. ";
	string second = "This is the second string. ";
	string third = "This is the third string. ";
	string fourth = "This is the fourth string. ";
	string fifth = "This is the fifth string. ";
	string sixth = "This is the sixth string. ";
	DoublyLinkedList<string> newList(second);//creating a new instance of doublylinkedlist and adding string second to the list
	newList.addFront(first);//adding string first to the front of the list
	newList.printListForward();//checking if Constructor, addFront, and printListForward funtions work
	newList.printListBackward();//checking printListBackwards function works
	newList.addEnd(fourth);//adding string fourth to the end of the list
	newList.printListForward();//checking to see if addEnd funtion works
	newList.printListBackward();//ensuring both prints works
	newList.insertNode(second, third);//inserting string third after second Node
	newList.printListForward();//checking to see if insertNode function works
	newList.printListBackward();//ensuring both prints work
	newList.deleteNode(fourth);//deleting Node containing string fourth in it's data
	newList.printListForward();//checking if deleteNode function works
	newList.printListBackward();//ensuring both prints work
	newList.addEnd(fourth);//adding string fourth back to the list
	newList.findNode(third);//testing findNode() function. should return that third Node exist
	newList.findNode(sixth);//should return Node does not exist in list
	newList.deleteNode(first);//testing deleteNode function. will delete first Node in the list
	newList.printListForward();
	newList.printListBackward();
	newList.deleteEndNode();//testing deleteEndNode() function. should delete string fourth
	newList.printListForward();
	newList.printListBackward();
	newList.deleteFrontNode();//testing deleteFrontNode() function. should delete string second
	newList.printListForward();
	newList.printListBackward();
	newList.addFront(second);//adding string second back to the list
	newList.addFront(first);//adding string first back to the list
	newList.addEnd(fourth);//adding string fourth back to the list
	newList.traverseForward(4);//testing traverseForward() function. has the ability to return data at inputted index. will print to console what is in inputted position
	newList.traverseBackward(1);
}
