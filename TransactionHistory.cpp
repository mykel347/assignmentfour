#include "TransactionHistory.h"
#include <iostream>



TransactionHistory::TransactionHistory(std::string type, Movie* movie)
{
	if (type == "B")
		transType = "Borrowed";
	else if (type == "R")
		transType = "Returned";
	else
		transType = "Invalid Type";
	moviePtr = movie;
}


TransactionHistory::~TransactionHistory()
{
}

void TransactionHistory::print()
{
	std::cout << transType;
	moviePtr->print();
}
