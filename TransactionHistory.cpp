#include "TransactionHistory.h"
#include <iostream>



TransactionHistory::TransactionHistory(std::string type, std::string key)
{
	if (type == "B")
		transType = "Borrowed";
	else if (type == "R")
		transType = "Returned";
	else
		transType = "Invalid Type";
	movieKey = key;
}


TransactionHistory::~TransactionHistory()
{
}

void TransactionHistory::print()
{
	std::cout << "Action Type: " << transType;
	std::cout << "\t Movie Key: " << movieKey << std::endl;
}
