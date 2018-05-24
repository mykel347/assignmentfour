#include "Movie.h"
#include <iostream>

//////////////////////////////////////////////////////////////////
//Parent Movie Class
//////////////////////////////////////////////////////////////////

Movie::Movie()
{
}

Movie::~Movie()
{
}

void Movie::setStock(int s) { stock = s; }

int Movie::getStock() const { return stock; }

void Movie::setDirector(std::string dir) { director = dir; }

std::string Movie::getDirector() const { return director; }

void Movie::setTitle(std::string t) { title = t; }

std::string Movie::getTitle() const { return title; }

void Movie::setYearReleased(int year) { yearReleased = year; }

int Movie::getYearReleased() const { return yearReleased; }

void Movie::print()
{
}

////////////////////////////////////////////////////////////////////
//Child Drama Class
////////////////////////////////////////////////////////////////////

MovieDrama::MovieDrama()
{
}

MovieDrama::~MovieDrama()
{
}

void MovieDrama::print()
{
	std::cout << "Title: \t" << getTitle() << std::endl;
	std::cout << "Director: \t" << getDirector() << std::endl;
	std::cout << "Genre: \t" << getMovieType() << std::endl;
	std::cout << "Release Date: \t" << getYearReleased() << std::endl;
	std::cout << "In Stock: \t" << getStock() << std::endl << std::endl;
}

std::string MovieDrama::getMovieType() const { return movieType; }

bool MovieDrama::lessThan(MovieDrama * Rhs) const
{
	if (getDirector() < Rhs->getDirector())
		return true;
	else if (getDirector() > Rhs->getDirector())
		return false;

	if (getTitle() < Rhs->getTitle())
		return true;
	else if (getTitle() > Rhs->getTitle())
		return false;
}

//////////////////////////////////////////////////////////////////////
//Child Comedy Class
//////////////////////////////////////////////////////////////////////

MovieComedy::MovieComedy()
{
}

MovieComedy::~MovieComedy()
{
}

void MovieComedy::print()
{
	std::cout << "Title: \t" << getTitle() << std::endl;
	std::cout << "Director: \t" << getDirector() << std::endl;
	std::cout << "Genre: \t" << getMovieType() << std::endl;
	std::cout << "Release Date: \t" << getYearReleased() << std::endl;
	std::cout << "In Stock: \t" << getStock() << std::endl << std::endl;
}

std::string MovieComedy::getMovieType() const { return movieType; }

bool MovieComedy::lessThan(MovieComedy * Rhs) const
{
	if (getTitle() < Rhs->getTitle()) {
		return true;
	}
	else if (getTitle() > Rhs->getTitle()) {
		return false;
	}
	if (getYearReleased() < Rhs->getYearReleased()) {
		return true;
	}
	else if (getYearReleased() > Rhs->getYearReleased())
		return false;
}

////////////////////////////////////////////////////////////////////
//Child Classic Class
////////////////////////////////////////////////////////////////////

MovieClassic::MovieClassic()
{
}

MovieClassic::~MovieClassic()
{
}

std::string MovieClassic::getMajorActorFirst() const { return majorActorFirst; }

void MovieClassic::setMajorActorFirst(std::string actor) { majorActorFirst = actor; }

std::string MovieClassic::getMajorActorLast() const { return majorActorLast; }

void MovieClassic::setMajorActorLast(std::string actor) { majorActorLast = actor; }

int MovieClassic::getMonthReleased() const { return monthReleased; }

void MovieClassic::setMonthReleased(int m) { monthReleased = m; }

void MovieClassic::print() const
{
	std::cout << "Title: \t" << getTitle() << std::endl;
	std::cout << "Director: \t" << getDirector() << std::endl;
	std::cout << "Genre: \t" << getMovieType() << std::endl;
	std::cout << "Release Date: \t" << getMonthReleased() << " " << getYearReleased() << std::endl;
	std::cout << "In Stock: \t" << getStock() << std::endl;
	std::cout << "Main Actor: \t" << getMajorActorFirst() << " " << getMajorActorLast() << std::endl << std::endl;
}

std::string MovieClassic::getMovieType() const { return movieType; }

bool MovieClassic::lessThan(const MovieClassic * Rhs) const
{
	if (getYearReleased() < Rhs->getYearReleased())
		return true;
	else if (getYearReleased() > Rhs->getYearReleased())
		return false;

	if (getMonthReleased() < Rhs->getMonthReleased())
		return true;
	else if (getMonthReleased() > Rhs->getMonthReleased())
		return false;

	if (getMajorActorFirst() < Rhs->getMajorActorFirst())
		return true;
	else if (getMajorActorFirst() > Rhs->getMajorActorFirst())
		return false;

	if (getMajorActorLast() < Rhs->getMajorActorLast())
		return true;
	else if (getMajorActorLast() > Rhs->getMajorActorLast())
		return false;
}
