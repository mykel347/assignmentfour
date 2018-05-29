
#include "LinkedList.h"
//#include "LinkedList.h"

//Default constructor
template <typename T>
LinkedList<T>::LinkedList()
{
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	//Clears the linked list
	clear();
}

template<typename T>
bool LinkedList<T>::add(T * objectSent)
{
	Node* newNode = new Node();
	newNode->data = objectSent;
	//Base case: of a empty LinkedList
	if (root == nullptr) {
		root = newNode;
		return true;
	}
	Node* tempPtr = root;
	//Checks to see if newNode belongs as the root
	if (objectSent->lessThan(tempPtr->data)) {
		newNode->next = tempPtr;
		root = newNode;
		return true;
	}
	//Traverses untill it either reaches the end, or finds the proper spot
	while (tempPtr->next != nullptr) {
		if (tempPtr->next->data->lessThan(objectSent)) {
			tempPtr = tempPtr->next;
		}
		else
			break;
	}
	//Case: End of list
	if (tempPtr->next == nullptr) {
		tempPtr->next = newNode;
		return true;
	}
	//Case: splice within the list
	newNode->next = tempPtr->next;
	tempPtr->next = newNode;
	return true;
}

//Print from Node
template<typename T>
void LinkedList<T>::printFromNode() const {
	Node* tempPtr = root;
	while (tempPtr->next != nullptr) {
		tempPtr->data->print();
		tempPtr = tempPtr->next;
	}
	tempPtr->data->print();
}

//Checks if the linkedlist isEmpty
template<typename T>
bool LinkedList<T>::isEmpty() const {
	if (root == nullptr)
		return true;
	return false;
}

template<typename T>
void LinkedList<T>::clear()
{
	//Defined in .h
	clearHelper(root);
}

