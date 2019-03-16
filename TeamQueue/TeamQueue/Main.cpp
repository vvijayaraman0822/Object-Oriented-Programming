// Name    : Vasudev Vijayaraman

// Course  : Object Oriented Programming, CMPS-2143-101, Fall 2017, Dr.Stringfellow

// Purpose : This program uses a queue to keep track of the team members and the 
//           command used are ENQUEUE, DEQUEUE and STOP. It takes an input file named
//			 input.txt and outputs it to output.txt. The functions that are used are
//			 push, pop, peek, empty. 

//  Date   : 6th December, 2017

#include<iostream>
#include<fstream>
#include<string>
#include<utility> 
#include<vector>
#include"TeamQueue.h"
using namespace std;
int main() {
	
	typedef pair<int, int> IntPair;
	ifstream infile;
	ofstream outfile;
	
	TeamQueue<int> queue;
	
	vector<IntPair> data;
	
	string command = "";
	
	int numTeams ;
	int sizeTeam, current;
	infile.open("input.txt");
	outfile.open("output.txt");

	infile >> numTeams;
	while (numTeams != 0) {
		
		for (int i = 0; i < numTeams; i++) {
			infile >> sizeTeam;
			cout << sizeTeam;
			for (int j = 0; j < sizeTeam; j++) {
				infile >> current;
				data.push_back(IntPair(current, i));
			}
		}
		infile >> command;
		while (command != "STOP") {
			if (command == "ENQUEUE") {
				infile >> current;
				
				for (int i = 0; i < data.size(); i++) {
					if (data[i].first == current) {
							queue.push(data[i].first, data[i].second);
					}
				}
			}
			else if (command == "DEQUEUE") {
				outfile << queue.pop();
			}
			infile >> command;
		}
		infile >> numTeams;
	}

	system("pause");
	return 0;
}