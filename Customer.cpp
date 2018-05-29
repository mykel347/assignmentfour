#include "Customer.h"
#include <iostream>

//Constructor for the customer class
Customer::Customer()
{
	ID = 0000;
	firstName = "No firstName"; //Initializes a default customer
	lastName = "No lastName";
}

//Cinstructor with data passed. Initializes ID, firstName, lastName
Customer::Customer(int newID, std::string first, std::string last) {
	ID = newID; 
	firstName = first;
	lastName = last;
}

//Destructor
Customer::~Customer()
{
}

//First Name setter
void Customer::setFirstName(std::string first) {
	firstName = first;
}

//Returns customer first name
std::string Customer::getFirstName() const
{
	return firstName;
}

//Sets customer last name
void Customer::setLastName(std::string last)
{
	lastName = last;
}

//Returns customer last name
std::string Customer::getLastName() const
{
	return lastName;
}

//Sets customer ID
void Customer::setID(int newID)
{
	ID = newID;
}

//Returns customer ID
int Customer::getID() const
{
	return ID;
}

//Comparison method to check customer ID
bool Customer::lessThan(Customer * c)
{
	if (ID < c->getID())
		return true;
	return false;
}

//Adds customer to transaction ID
bool Customer::addToHistory(std::string type, Movie * movie)
{
	TransactionHistory* newHistory = new TransactionHistory(type, movie);
	historyLinkedList.add(newHistory);
	return false;
}

//Prints history for the transaction processed
void Customer::printHistory()
{
	std::cout << "Displaying Transcation History For" << firstName << " " << lastName << "  ID: "<< ID << std::endl << std::endl;
	historyLinkedList.printFromNode();
}
