// Name    : Vasudev Vijayaraman

// Course  : Object Oriented Programming, CMPS-2143-101, Fall 2017, Dr.Stringfellow

// Purpose : This program uses a stack to determine whether a string entered at the 
//           keyboard has balanced paranthesis. The method being used is a dynamic array
//			 array based stack. The program reads the input the file being input.txt and 
//           the solution is written to the file output.txt and also printed on the screen

//  Date   : 13th September, 2017

#pragma once
using namespace std;

const int MAXSIZE = 100;

class Stack
{
private:
	char *S;
	int Top;                            // variable to mark the top of the stack
	int Size;                           // Size of the stack

public:
	void EmptyContents();               // Empty the stack before you push or pop
	Stack();                            // constructor
	Stack(int size);					// Size of the Stack
	void Push(char x);                  // Insert an element to top of the stack
	char Pop();                         // Removing the element on top
	bool Full();                        // Return true or false, if stack is full
	bool Empty();                       // Return true or false, if stack is empty
	


	~Stack();

};