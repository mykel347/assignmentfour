#include "Movie.h"
#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////
//Parent Movie Class
//////////////////////////////////////////////////////////////////

Movie::Movie()
{
}

Movie::~Movie()
{
}

bool Movie::setStock(int s) { 
	if (s < 0)
	{
		return false;
	}
	else
	stock = s; 
	return true;
}

int Movie::getStock() const { return stock; }

void Movie::setDirector(std::string dir) { director = dir; }

std::string Movie::getDirector() const { return director; }

void Movie::setTitle(std::string t) { title = t; }

std::string Movie::getTitle() const { return title; }

void Movie::setYearReleased(int year) { yearReleased = year; }

int Movie::getYearReleased() const { return yearReleased; }

bool Movie::lessThan(Movie* Rhs) const
{
	std::cout << "Wrong LessThan method called" << std::endl;
	return false;
}

void Movie::print()
{
	std::cout << "Wrong Movie Print method called" << std::endl;
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
	std::cout << "Stock: " << getStock() << "\tTitle: " << getTitle() << " -- Director: " << getDirector() << std::endl;
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
	return true;
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
	std::cout << "Stock: " << getStock() << "\tTitle: " << getTitle() << " -- Director: " << getDirector() << std::endl;
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
	return true;
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
	std::cout << "Stock: " << getStock() << "\tTitle: " << getTitle() << " -- Director: " << getDirector();
	std::cout << " -- Main Actor: " << getMajorActorFirst() << " " << getMajorActorLast() << std::endl;
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
	return true;
}
