#pragma once
#include <string>
#include "LinkedList.h"

#include "TransactionHistory.h"
class Customer
{
public:

	//Constructors
	Customer();
	Customer(int newID, std::string first, std::string last);

	//Destructors
	~Customer();

	//Setters for the customer class
	void setFirstName(std::string first);
	void setKey(std::string k) { key = k; }
	void setLastName(std::string last);
	void setID(int newID);

	//Getters for the customer class
	std::string getLastName() const;
	std::string getFirstName() const;
	int getID() const;
	std::string getKey() { return key; }

	//Helper methods for the customer class
	bool addToHistory(std::string type, Movie* movie);
	void printHistory();
	bool lessThan(Customer* c);

private:
	//Private viarables for the customer class
	int ID;
	std::string firstName;
	std::string lastName;
	std::string key;
	LinkedList<TransactionHistory> historyLinkedList;
};

