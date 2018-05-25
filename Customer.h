#pragma once
#include <string>
#include "LinkedList.h"

#include "TransactionHistory.h"
class Customer
{
public:
	Customer();
	Customer(int newID, std::string first, std::string last);
	~Customer();
	void setFirstName(std::string first);
	std::string getFirstName() const;
	void setLastName(std::string last);
	std::string getLastName() const;
	void setID(int newID);
	int getID() const;
	bool lessThan(Customer* c);

	bool addToHistory(std::string type, Movie* movie);
	void printHistory();

private:
	int ID;
	std::string firstName;
	std::string lastName;
	LinkedList<TransactionHistory> historyLinkedList;
};

