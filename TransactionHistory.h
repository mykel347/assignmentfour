#pragma once
#include <string>
#include "Movie.h"

//This class is to be used within each customer object to maintain
//their individual transation histories.
class TransactionHistory
{
public:
	TransactionHistory(std::string type, Movie* movie);
	~TransactionHistory();

	//This list will not sort itself. The list generates linearly
	bool lessThan(TransactionHistory* z) { return false; }
	void print();

	//Possible reasons for a get/set is for user to edit history
	//No need to this function within the scope of the assignement

private:
	std::string date;   //to be implemented when you figure out how to timestamp
	std::string transType;
	Movie* moviePtr; //May change the way to keep movie data, using the ptr to call the print method within movie
};

