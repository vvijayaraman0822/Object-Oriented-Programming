#pragma once
#include<string>
template<class Type>
class TeamQueue {
public:

	class Node {
	public:
		Node();
		Node(Type, int);
		Type data;
		int team;
		Node* next;
		Node* prev;
	};
	TeamQueue();
	bool empty();      
	void push(Type, int);
	void push(const Node &);
	Type pop();
	Type peek();
	std::string toString(bool);
private:
	Node* first = NULL;
	Node* last = NULL;
};
#include"TeamQueue.cpp"