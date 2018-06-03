// Assignment 4 - Movie rental database
// Version 1.0 - 6/2/2018
// Jacob Lefeat + Mykel Boachie

#include <iostream>
#include <queue>
#include "Movie.h"
#include "LinkedList.h"
#include "Customer.h"
#include "HashTable.h"
#include <sstream>
#include <fstream>
#include <vector>

//All linked lists and hash tables to be used in the program
HashTable<std::string, Customer*> customerHashTable(100);
HashTable<std::string, MovieClassic*> movieClassicHashTable(100);
HashTable<std::string, MovieDrama*> movieDramaHashTable(100);
HashTable<std::string, MovieComedy*> movieComedyHashTable(100);
LinkedList<MovieComedy> movieComedyLinkedList;
LinkedList<MovieDrama> movieDramaLinkedList;
LinkedList<MovieClassic> movieClassicLinkedList;
LinkedList<Customer> customerLinkedList;

//Dirty method to count words in a string
int countWords(std::string s) {
	int wordCount = 0;
	std::stringstream ss(s);
	std::string word;
	while (ss >> word) ++wordCount;
	return wordCount;
}

//Recieves a string from "readMovieFile" method and executes accordingly
void processMovies(int type, std::string line)
{
	MovieComedy* movieComedy;
	MovieDrama* movieDrama;
	MovieClassic* movieClassic;
	std::istringstream iss(line);
	int wordCount = countWords(line);;
	std::vector<std::string> wordVector;
	std::string director = "";
	std::string title = "";
	std::string key = "";

	//this method iterates each word within the string from "iss" to a temp string "subs"
	do {
		std::string subs;
		iss >> subs;
		//removes unnessessary commas from the word
		//subs.erase(std::remove(subs.begin(), subs.end(), ','), subs.end()); //disabled due to nature of command file format
		//pushes the words into a temp vector, for later use.
		wordVector.push_back(subs);
	} while (iss);

	switch (type)
	{
		//Comedy movie format
	case 1:
		movieComedy = new MovieComedy();
		//set stock - slot 1
		movieComedy->setStock(stoi(wordVector[1]));
		//set director - slot 2 and 3
		director = wordVector[2] + " " + wordVector[3];
		movieComedy->setDirector(director);
		//Title slots - from slot 4 to 1 before final slot
		title = wordVector[4];
		for (int i = 5; i < wordCount - 1; i++) {
			title += " " + wordVector[i];
		}
		movieComedy->setTitle(title);
		//year released - last slot - wordCount-1 
		movieComedy->setYearReleased(stoi(wordVector[wordCount-1]));
		//Set key to be used for hashTable
		key = movieComedy->getTitle();
		key += " " + std::to_string(movieComedy->getYearReleased());

		//Checks if Movie already exists through the hash table "put" function
		//If movie already exists, does not place a duplicate into the linked list
		if (movieComedyHashTable.put(key, movieComedy)) {
			movieComedyLinkedList.add(movieComedy);
			//Reporting tool
			//std::cout << "Successfully added Movie" << std::endl;
		}
		else
			std::cout << "Movie object already exist in database. Replacing with new object" << std::endl;
		break;

		//Drama
	case 2:
		movieDrama = new MovieDrama();

		//set stock - slot 1
		movieDrama->setStock(stoi(wordVector[1]));

		//set director - slot 2 and 3
		director = wordVector[2] + " " + wordVector[3];
		movieDrama->setDirector(director);

		//Set Title - from slot 4 to 1 before final slot
		title = wordVector[4];
		for (int i = 5; i < wordCount - 1; i++) {
			title += " " + wordVector[i];
		}
		movieDrama->setTitle(title);

		//Set yearReleased - last slot - wordCount-1 
		movieDrama->setYearReleased(stoi(wordVector[wordCount - 1]));

		//Set key to be used for hashTable
		key = movieDrama->getDirector();
		key += " " + movieDrama->getTitle();

		//Checks if Movie already exists through the hash table "put" function
		//If movie already exists, does not place a duplicate into the linked list
		if (movieDramaHashTable.put(key, movieDrama)) {
			movieDramaLinkedList.add(movieDrama);
		}
		else
			std::cout << "Movie object already exist in database. Replacing with new object" << std::endl;
		break;

		//Classic
	case 3:
		movieClassic = new MovieClassic();

		//set stock - slot 1
		movieClassic->setStock(stoi(wordVector[1]));

		//set director - slot 2 and 3
		director = wordVector[2] + " " + wordVector[3];
		movieClassic->setDirector(director);

		//Set Title - from slot 4 to 1 before final slot
		title = wordVector[4];
		for (int i = 5; i < wordCount - 4; i++) {
			title += " " + wordVector[i];
		}
		movieClassic->setTitle(title);

		//Set Actor first name
		movieClassic->setMajorActorFirst(wordVector[wordCount - 4]);

		//Set actor last name
		movieClassic->setMajorActorLast(wordVector[wordCount - 3]);

		//Set month released 
		movieClassic->setMonthReleased(stoi(wordVector[wordCount - 2]));

		//Set yearReleased - last slot - wordCount-1 
		movieClassic->setYearReleased(stoi(wordVector[wordCount - 1]));

		//Set key to be used for hashTable
		key = wordVector[wordCount - 2] + " ";
		key += wordVector[wordCount - 1] + " ";
		key += wordVector[wordCount - 4] + " ";
		key += wordVector[wordCount - 3];

		//Checks if Movie already exists through the hash table "put" function
		//If movie already exists, does not place a duplicate into the linked list
		if (movieClassicHashTable.put(key, movieClassic))
		{
			movieClassicLinkedList.add(movieClassic);
		}
		else
			std::cout << "Movie object already exist in database. Replacing with new object" << std::endl;


		break;
	}
}

//Reads the movie file and sends the lines to the "processMovies" method
void readMovieFile(std::string filename) {
	std::ifstream inFile(filename);
	std::string line;
	std::string peek;
	int type;

	if (!inFile) {
		std::cerr << "Unable to open file data4movies";
	}
	else
	{
		while(std::getline(inFile, line))
			if (!line.empty()) {
				peek = line.at(0);

				if (peek == "F")
					type = 1;
				else if (peek == "D")
					type = 2;
				else if (peek == "C")
					type = 3;
				else
				{
					std::cerr << "Error processing Movie - Invalid genre" << std::endl;
					continue;
				}
				processMovies(type, line);
			}		
	}
	inFile.close();
}

//Reads and procesess the customer file
void readCustomerFile(std::string filename) {
	std::ifstream inFile;
	std::string line;
	int count = 0;
	std::string first;
	std::string last;
	std::string key;

	inFile.open(filename);
	if (!inFile) {
		std::cerr << "unable to open file data4customers";
	}
	else
	{
		while (std::getline(inFile, line))
		{
			Customer* cust = new Customer();
			std::istringstream iss(line);
			do {
				std::string subs;
				iss >> subs;
				if (count == 0) {
				key = subs;
				cust->setID(stoi(subs));
				}
				if (count == 1)
					cust->setFirstName(subs);
				if (count == 2)
					cust->setLastName(subs);
				count++;			
			} while (iss);
			//Adds in the new customer object
			if (customerHashTable.put(key, cust))
			{
				customerLinkedList.add(cust);
			}
			else
				std::cout << "Customer object already exists in database. Replacing with new Object" << std::endl;
			count = 0;
		}
	}
	inFile.close();
}

//Reads and processes the command file
void readCommandFile(std::string filename)
{
	std::ifstream inFile;
	std::string line;
	std::string type;
	
	inFile.open(filename);

	if (!inFile) {
		std::cerr << "unable to open file data4commands";
	}
	else
	{
		while (std::getline(inFile, line))
		{
			std::vector<std::string> wordVector;
			std::istringstream iss(line);
			std::string key;
			do {
				std::string subs;
				iss >> subs;
				wordVector.push_back(subs);
			} while (iss);
			type = wordVector[0];
			

			if (type == "I") {
				//print inventory
				std::cout << "Printing Movie Inventory" << std::endl;
				std::cout << "Comedic Movies" << std::endl;
				movieComedyLinkedList.printFromNode();
				std::cout << "Dramatic Movies" << std::endl;
				movieDramaLinkedList.printFromNode();
				std::cout << "Classical Movies" << std::endl;
				movieClassicLinkedList.printFromNode();
				
				
			}
			else if (type == "H") {
				//Print customer history 
				Customer* tempCust;
				customerHashTable.get(wordVector[1], tempCust);
				tempCust->printHistory();                                               //Work on this formating if it looks wierd
			}
			//Handles All "Borrow" transactions
			else if (type == "B") {
				if (wordVector[2] != "D")
				{
					std::cerr << "Invalid Format - Only DvD's currently acceptable." << std::endl;
					continue;
				}
				
				std::string movieType = wordVector[3];
				//Movie "drama" format
				if (movieType == "D") {
					Customer* tempCust;
					key = wordVector[4] + " ";
					key += wordVector[5];
					for (int i = 6; i < wordVector.size()-1; i++) {
						key += " ";
						key += wordVector[i];
					}
					MovieDrama* tempMovie;

					if (!customerHashTable.get(wordVector[1], tempCust)) {
						std::cerr << "Customer not found" << std::endl;
						continue;
					}
					if (!movieDramaHashTable.get(key, tempMovie)) {
						std::cerr << "Movie not found" << std::endl;
						continue;
					}
					if (!tempMovie->setStock(tempMovie->getStock() - 1))
					{
						std::cerr << "Customer ID: " << wordVector[1] << ". Unable to borrow movie: " << tempMovie->getTitle() <<" - Out of stock." << std::endl;
					}
					else
					{
						tempCust->addToHistory(type, key);
					}
				}
				//Movie "classic" format
				else if (movieType == "C") {
					key = wordVector[4] + " ";
					key += wordVector[5] + " ";
					key += wordVector[6] + " ";
					key += wordVector[7];
					MovieClassic* tempMovie;
					Customer* tempCust;
					if (!customerHashTable.get(wordVector[1], tempCust)) {
						std::cerr << "Customer not found" << std::endl;
						continue;
					}
					if (!movieClassicHashTable.get(key, tempMovie)) {
						std::cerr << "Movie not found" << std::endl;
						continue;
					}
					if (!tempMovie->setStock(tempMovie->getStock() - 1))
					{
						std::cerr << "Customer ID: " << wordVector[1] << ". Unable to borrow movie: " << tempMovie->getTitle() << " - Out of stock." << std::endl;
					}
					else
					{
						tempCust->addToHistory(type, key);
					}
				}
				//Movie Comedy format
				else if (movieType == "F") {
					key = wordVector[4];
					for (int i = 5; i < wordVector.size()-1; i++)
					{
						key += " ";
						key += wordVector[i];
					}
					Customer* tempCust;
					MovieComedy* tempMovie;
					if (!customerHashTable.get(wordVector[1], tempCust)) {
						std::cerr << "Customer not found" << std::endl;
						continue;
					}
					if (!movieComedyHashTable.get(key, tempMovie)) {
						std::cerr << "Movie not found" << std::endl;
						continue;
					}
					if (!tempMovie->setStock(tempMovie->getStock() - 1))
					{
						std::cerr << "Customer ID: " << wordVector[1] << ". Unable to borrow movie: " << tempMovie->getTitle() << " - Out of stock." << std::endl;
					}
					else
					{
						tempCust->addToHistory(type, key);
					}


				}
				else
					std::cout << "Invalid movie genre used" << std::endl;
		
			}
			//Handles all "return" entries
			else if (type == "R") {
				if (wordVector[2] != "D")
				{
					std::cerr << "Invalid Format - Only DvD's currently acceptable." << std::endl;
					continue;
				}
				std::string movieType = wordVector[3];
				//Drama format
				if (movieType == "D") {
					Customer* tempCust;
					key = wordVector[4] + " ";
					key += wordVector[5];
					for (int i = 6; i < wordVector.size()-1; i++) {
						key += " ";
						key += wordVector[i];
					}
					MovieDrama* tempMovie;
					if (!customerHashTable.get(wordVector[1], tempCust)) {
						std::cerr << "Customer not found" << std::endl;
						continue;
					}
					if (!movieDramaHashTable.get(key, tempMovie)) {
						std::cerr << "Movie not found" << std::endl;
						continue;
					}
					tempMovie->setStock(tempMovie->getStock() + 1);
					tempCust->addToHistory(type, key);
					
				}
				//Classic format
				else if (movieType == "C") {
					key = wordVector[4] + " ";
					key += wordVector[5] + " ";
					key += wordVector[6] + " ";
					key += wordVector[7];
					MovieClassic* tempMovie;
					Customer* tempCust;
					if (!customerHashTable.get(wordVector[1], tempCust)) {
						std::cerr << "Customer not found" << std::endl;
						continue;
					}
					if (!movieClassicHashTable.get(key, tempMovie)) {
						std::cerr << "Movie not found" << std::endl;
						continue;
					}
					tempMovie->setStock(tempMovie->getStock() + 1);
					tempCust->addToHistory(type, key);
					
				}
				//Comedy format
				else if (movieType == "F") {
					key = "";
					for (int i = 4; i < wordVector.size()-1; i++)
					{
						key += " ";
						key += wordVector[i];
					}
					Customer* tempCust;
					MovieComedy* tempMovie;
					if (!customerHashTable.get(wordVector[1], tempCust)) {
						std::cerr << "Customer not found" << std::endl;
						continue;
					}
					if (!movieComedyHashTable.get(key, tempMovie)) {
						std::cerr << "Movie not found" << std::endl;
						continue;
					}
					tempMovie->setStock(tempMovie->getStock() + 1);
					tempCust->addToHistory(type, key);
				}
				else
					std::cout << "Invalid movie genre used" << std::endl;

			}
			else
				std::cerr << "Invalid command indicator used." << std::endl;
			
		}
	}
	inFile.close();
}

int main()
{

	while (true)
	{
		std::string input;
		int k;
		std::cout << "Welcome to REDACTED movies. Please enter the number associated with your selection." << std::endl;
		std::cout << "1. Read Movie File into database." << std::endl;
		std::cout << "2. Read Customer File Into Database." << std::endl;
		std::cout << "3. Read and Execute Command File." << std::endl;
		std::cout << "4. Print Classic Movie Database" << std::endl;
		std::cout << "5. Print Dramatic Movie Database" << std::endl;
		std::cout << "6. Print Comedic Movie Database" << std::endl;
		std::cout << "7. Print Customer Database" << std::endl;
		std::cout << "8. Exit Program" << std::endl;

		std::cin >> input;
		if (!isdigit(input[0]))
		{
			std::cout << "Bad input, please use valid numbers." << std::endl;
			continue;
		}
		else
			k = stoi(input);

		switch (k)
		{
		case 1:
			readMovieFile("data4movies.txt");
			std::cout << std::endl << "Reading From Movie File Completed" << std::endl << std::endl;
			break;
		case 2:
			readCustomerFile("data4customers.txt");
			std::cout << std::endl << "Reading From Customer File Completed" << std::endl << std::endl;
			break;
		case 3:
			readCommandFile("data4commands.txt");
			std::cout << std::endl << "Executing Command File Completed" << std::endl << std::endl;
			break;
		case 4:
			std::cout << std::endl;
			movieClassicLinkedList.printFromNode();
			std::cout << std::endl;
			break;
		case 5:
			std::cout << std::endl;
			movieDramaLinkedList.printFromNode();
			std::cout << std::endl;
			break;
		case 6:
			std::cout << std::endl;
			movieComedyLinkedList.printFromNode();
			std::cout << std::endl;
			break;
		case 7:
			std::cout << std::endl;
			customerLinkedList.printFromNode();
			std::cout << std::endl;
			break;
		case 8:
			return 0;
		default:
			std::cout << "Bad input, please use valid numbers." << std::endl;
		}
	}
	return 0;
}

