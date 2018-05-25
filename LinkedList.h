#pragma once

template <typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	//Add is dependant on the objects having a lessThan method for sorting
	bool add(T* objectSent);
	void printFromNode() const;
	bool isEmpty() const;

	//No remove and no clear functions implemented. 

private:
	struct Node {
		T* data;
		Node* next;
	};
	Node* root;
};

#include "LinkedList.cpp"
