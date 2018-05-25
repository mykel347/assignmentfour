#include "Customer.h"
#include <iostream>


Customer::Customer()
{
	ID = 0000;
	firstName = "No firstName";
	lastName = "No lastName";
}

Customer::Customer(int newID, std::string first, std::string last) {
	ID = newID; 
	firstName = first;
	lastName = last;
}


Customer::~Customer()
{
}

void Customer::setFirstName(std::string first) {
	firstName = first;
}

std::string Customer::getFirstName() const
{
	return firstName;
}

void Customer::setLastName(std::string last)
{
	lastName = last;
}

std::string Customer::getLastName() const
{
	return lastName;
}

void Customer::setID(int newID)
{
	ID = newID;
}

int Customer::getID() const
{
	return ID;
}

bool Customer::lessThan(Customer * c)
{
	if (ID < c->getID())
		return true;
	return false;
}

bool Customer::addToHistory(std::string type, Movie * movie)
{
	TransactionHistory* newHistory = new TransactionHistory(type, movie);
	historyLinkedList.add(newHistory);
	return false;
}

void Customer::printHistory()
{
	std::cout << "Displaying Transcation History For" << firstName << " " << lastName << "  ID: "<< ID << std::endl << std::endl;
	historyLinkedList.printFromNode();
}
