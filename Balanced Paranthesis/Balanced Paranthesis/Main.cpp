#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include "BalancedParanthesis.h"
using namespace std;

void Joining(char ch, ofstream &oFile)           // Concatenating charcter to string 
{
	string line;

	line += ch;

	oFile << left << line;
}

bool AreParanthesisBalanced(ifstream &iFile, ofstream &oFile)    //reading contents from the file
{
	char exp;
	string line;

	Stack s(100);

	s.EmptyContents();

	while (iFile.get(exp) && exp != '\n')
	{
		Joining(exp, oFile);
		if (exp == '(')
			s.Push(exp);             // Push the open paranthesis onto the stack as soon as you see it

		else if (exp == ')')
		{
			if (s.Empty())
			{                             // If you see close paranthesis, check if the stack is empty and if it has open paranthesis
				                          // If yes, pop it
				while (exp != '\n')
				{
					iFile.get(exp);
					Joining(exp, oFile);

				}
				return false;
			}
			else
				s.Pop();
		}
	}
	return s.Empty();               // If empty stack gets returned, it means its balanced
}

void Format(ofstream &oFile)
{
	cout << "Expression" << setw(44) << "Balanced or Not " << endl << endl;
	cout << "_____________________________________________________________________" << endl;
	oFile << "Expression" << setw(50) << "Balanced or Not " << endl << endl;
	oFile << "_____________________________________________________________________" << endl;
	return;
}



void Copy(ifstream &iFile, ofstream &oFile)
{
	char ch;

	Format(oFile);

	for (int i = 0; i < 10; i++)
	{
		if (AreParanthesisBalanced(iFile, oFile))
		{
			cout << right << setw(50) << "Balanced\n" << endl;
			oFile << right << setw(38) << "Balanced\n" << endl;
		}
		else
		{
			cout << right << setw(50) << "Not Balanced\n" << endl;
			oFile << right << setw(34) << "Not Balanced\n" << endl;

		}

		
	}
	oFile << "Great Job in finishing the first assignment. You deserve an applaud" << endl;
	return;
}



int main()
{
	ifstream inFile;
	ofstream oFile;
	inFile.open("input.txt");
	oFile.open("output.txt");

	/*string item;
	int count = 0;

	while (!inFile.eof()) {
		inFile >> item;
		count++;
	 }

	cout << count << endl; */



	Copy(inFile, oFile);

	system("pause");
	return 0;
}