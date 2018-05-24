#pragma once

template <typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	//Add is dependant on the objects having a lessThan method for sorting
	bool add(T* objectSent);
	void print() const;
	bool isEmpty() const;

private:
	struct Node {
		T* data;
		Node* next;
	};
	Node* root;
};

#include "LinkedList.cpp"
