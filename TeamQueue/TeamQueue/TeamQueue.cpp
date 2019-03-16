#include"TeamQueue.h"
template<class Type>
TeamQueue<Type>::Node::Node() {
	data = NULL;
	team = NULL;
	prev = NULL;
	next = NULL;
}

template<class Type>
TeamQueue<Type>::Node::Node(Type d, int t) {
	data = d;
	team = t;
	prev = NULL;
	next = NULL;
}

template<class Type>
TeamQueue<Type>::TeamQueue() {
	first = NULL;
	last = NULL;
}

// Check if Queue is empty
template<class Type>
bool TeamQueue<Type>::empty() {
	if (!first)
		return true;
	return false;
}

template<class Type>
void TeamQueue<Type>::push(Type d, int t) {
	Node* newitem = new Node(d, t);
	if (!empty()) {
		Node* searcher = first;
		while (searcher->next) {
			
			if (searcher->team == newitem->team
				&& searcher->next->team != newitem->team) {
				newitem->prev = searcher;
				newitem->next = searcher->next;
				newitem->next->prev = newitem;
				newitem->prev->next = newitem;
			}
			
			if (searcher->next != newitem)
				searcher = searcher->next;
			else
				searcher = last;
		}
		
		if (!newitem->next && !newitem->prev) {
			newitem->prev = last;
			last->next = newitem;
			last = newitem;
		}
	}

	else {
		first = newitem;
		last = newitem;
	}
	return;
}

template<class Type>
void TeamQueue<Type>::push(const Node & item) {
	Node* newitem = new Node(item.data, item.team);
	if (!empty()) {
		Node* searcher = first;
		while (searcher->next) {
			
			if (searcher->team == newitem->team
				&& searcher->next->team != newitem->team) {
				newitem->prev = searcher;
				newitem->next = searcher->next;
				
				newitem->next->prev = newitem;
				
				newitem->prev->next = newitem;
			}
			
			if (searcher->next != newitem)
				searcher = searcher->next;
			else
				searcher = last;
		}

		if (!newitem->next && !newitem->prev) {
			newitem->prev = last;
			last->next = newitem;
			last = newitem;
		}
	}

	else {
		first = newitem;
		last = newitem;
	}
	return;
}

template<class Type>
Type TeamQueue<Type>::pop() {
	Type popped;
	if (!empty() && first->next) {
		popped = first->data;
		first = first->next;
		delete first->prev;
		first->prev = NULL;
	}
	else if (!empty()) {
		popped = first->data;
		delete first;
		first = NULL;
		last = NULL;
	}
	else {
		popped = NULL;
	}
	return popped;
}

template<class Type>
Type TeamQueue<Type>::peek() {
	if (!empty())
		return first->data;
	return NULL;
}

template<class Type>
std::string TeamQueue<Type>::toString(bool reverse) {
	std::string qstring = "";
	if (!reverse) {
		Node* temp = first;
		while (temp) {
			qstring += temp->data;
			temp = temp->next;
			if (temp)
				qstring += " ";
		}
	}
	else {
		Node* temp = last;
		while (temp) {
			qstring += temp->data;
			temp = temp->prev;
			if (temp)
				qstring += " ";
		}
	}
	return qstring;
}