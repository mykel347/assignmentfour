// Assignment4.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "Movie.h"
#include "LinkedList.h"
#include "Customer.h"
#include "HashTable.h"
#include <fstream>

void readFromFile() {
	std::ifstream inFile;
	inFile.open("data4customers.txt");

	if (!inFile) {
		std::cerr << "Unable to open file data4customers";
		std::cout << "Unable to open the file data4customers";
	}
}

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

	readFromFile();

	//switch menu
	//possible options?

	writeToFile();


	system("PAUSE");
	return 0;
}

