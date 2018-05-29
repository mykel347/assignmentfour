// Assignment4.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <queue>
#include "Movie.h"
#include "LinkedList.h"
#include "Customer.h"
#include "HashTable.h"
#include <sstream>
#include <fstream>
#include <vector>
//#include <cstddef>


HashTable<std::string, Customer*> customerHashTable(100);
HashTable<std::string, Movie*> movieHashTable(100);
LinkedList<MovieComedy> movieComedyLinkedList;
LinkedList<MovieDrama> movieDramaLinkedList;
LinkedList<MovieClassic> movieClassicLinkedList;
LinkedList<Customer> customerLinkedList;

int countWords(std::string s) {
	int wordCount = 0;
	std::stringstream ss(s);
	std::string word;
	while (ss >> word) ++wordCount;
	return wordCount;
}

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
		key += key + " " + std::to_string(movieComedy->getYearReleased());

		//Checks if Movie already exists through the hash table "put" function
		//If movie already exists, does not place a duplicate into the linked list
		if (movieComedyLinkedList.add(movieComedy)) {
			movieHashTable.put(key, movieComedy);
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
		key += key + " " + movieDrama->getTitle();

		//Checks if Movie already exists through the hash table "put" function
		//If movie already exists, does not place a duplicate into the linked list
		if (movieDramaLinkedList.add(movieDrama)) {
			movieHashTable.put(key, movieDrama);
			//Reporting tool
			//std::cout << "Successfully added Movie" << std::endl;
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
		if (movieHashTable.put(key, movieClassic))
		{
			movieClassicLinkedList.add(movieClassic);
			//Reporting tool
			//std::cout << "Successfully added Movie" << std::endl;
		}
		else
			std::cout << "Movie object already exist in database. Replacing with new object" << std::endl;


		break;
	}
}

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
				//Reporting tool
				//std::cout << "Successfully added Customer" << std::endl;
			}
			else
				std::cout << "Customer object already exists in database. Replacing with new Object" << std::endl;
			count = 0;
		}
	}
	inFile.close();
}

void readFromFile() {

	readMovieFile("data4movies.txt");
	readCustomerFile("data4customers.txt");
}

//Not in requirement and can be skipped
void writeToFile() {

}



int main()
{
	/*Movie* movie1Generic = new Movie();
	MovieComedy* movie2Comedy = new MovieComedy();
	MovieDrama* movie3Drama = new MovieDrama();

	MovieClassic* movie1Classic = new MovieClassic();
	MovieClassic* movie2Classic = new MovieClassic();
	MovieClassic* movie3Classic = new MovieClassic();
	MovieClassic* movie4Classic = new MovieClassic();

	LinkedList<MovieClassic>* MovieList = new LinkedList<MovieClassic>();

	movie1Classic->setDirector("Director Cheney");
	movie1Classic->setStock(10);
	movie1Classic->setTitle("This is america");
	movie1Classic->setMajorActorFirst("Childish");
	movie1Classic->setMajorActorLast("Gambino");
	movie1Classic->setYearReleased(2018);
	movie1Classic->setMonthReleased(2);

	movie2Classic->setDirector("Director Cheney");
	movie2Classic->setStock(10);
	movie2Classic->setTitle("This is america");
	movie2Classic->setMajorActorLast("Childish");
	movie2Classic->setMajorActorFirst("Gambino");
	movie2Classic->setYearReleased(2017);
	movie2Classic->setMonthReleased(7);

	movie3Classic->setDirector("Director Cheney");
	movie3Classic->setStock(10);
	movie3Classic->setTitle("This is america");
	movie3Classic->setMajorActorFirst("Jane");
	movie3Classic->setMajorActorLast("Savage");
	movie3Classic->setYearReleased(2019);
	movie3Classic->setMonthReleased(2);

	movie4Classic->setDirector("Director Cheney");
	movie4Classic->setStock(10);
	movie4Classic->setTitle("This is america");
	movie4Classic->setMajorActorFirst("zoo");
	movie4Classic->setMajorActorLast("philia");
	movie4Classic->setYearReleased(2018);
	movie4Classic->setMonthReleased(6);

	if (MovieList->add(movie1Classic)) {
		std::cout << "Item 1 Added" << std::endl;
	}
	if (MovieList->add(movie2Classic)) {
		std::cout << "Item 2 Added" << std::endl;
	}
	if (MovieList->add(movie3Classic)) {
		std::cout << "Item 3 Added" << std::endl;
	}
	if (MovieList->add(movie4Classic)) {
		std::cout << "Item 4 Added" << std::endl;
	}

	MovieList->printFromNode();

	LinkedList<Customer>* CustomerList = new LinkedList<Customer>();
	Customer dave;*/

	/*HashTable<std::string, Customer*>* customerHashTable = new HashTable<std::string, Customer*>(100);
	HashTable<std::string, Movie*>* movieHashTable = new HashTable<std::string, Movie*>(100);
	LinkedList<Movie> movieLinkedList;
	LinkedList<Customer> customerLinkedList;*/

	readFromFile();
	

	//switch menu
	//possible options?

	writeToFile();


	system("PAUSE");
	return 0;
}

