#include<iostream>
#include "BalancedParanthesis.h"
using namespace std;

Stack::Stack()       
{
	S = new char[MAXSIZE];
	Top = -1;
}


Stack::Stack(int size)
{
	Size = size;
	Top = -1;
	S = new char[Size];
}


void Stack::Push(char x)
{
	if (!Full())
		S[++Top] = x;
	else
		cout << "Stack over flow" << endl;
}


char Stack::Pop()
{
	if (!Empty())
		return S[Top--];
	else
		return '?';
}


bool Stack::Full()
{
	return Top == Size - 1;
}


bool Stack::Empty()
{
	return Top == -1;
}

void Stack::EmptyContents()
{
	while (!Empty())
		Pop();
	Top = -1;
}

Stack::~Stack()
{
	delete[] S;
	Top = -1;
}