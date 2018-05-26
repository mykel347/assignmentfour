#pragma once

template <typename T>
class LinkedList
{
private:
	struct Node {
		T* data;
		Node* next;
	};
	Node* root;

public:
	LinkedList();
	~LinkedList();

	//Add is dependant on the objects having a lessThan method for sorting
	bool add(T* objectSent);
	void printFromNode() const;
	bool isEmpty() const;
	void clear();

	//Defined the function here since the Node struct is unknown to the CPP file until compile
	Node* clearHelper(Node* r){
		if (r == NULL)
			return nullptr;

		while (r->next != NULL)
			clearHelper(r->next);
		delete r;
		return nullptr;
	}

	//No remove and no clear functions implemented. 
};

#include "LinkedList.cpp"
