#pragma once
#include <string>
#include <iomanip>

//Parent Movie Class
class Movie
{
public:
	Movie();
	~Movie();

	void setStock(int s);
	int getStock() const;

	void setDirector(std::string dir);
	std::string getDirector() const;

	void setTitle(std::string t);
	std::string getTitle() const;

	void setYearReleased(int year);
	int getYearReleased() const;

	virtual void print();

private:
	int stock;
	std::string director;
	std::string title;
	int yearReleased;
};

//Child Classic Class
class MovieClassic : public Movie
{
public:
	MovieClassic();
	~MovieClassic();

	std::string getMajorActorFirst() const;
	void setMajorActorFirst(std::string actorFirst);
	std::string getMajorActorLast() const;
	void setMajorActorLast(std::string actorFirst);
	int getMonthReleased() const;
	void setMonthReleased(int m);
	void print() const;
	std::string getMovieType() const;
	bool lessThan(const MovieClassic* Rhs) const;

private:
	std::string majorActorFirst;
	std::string majorActorLast;
	std::string movieType = "Classic";
	int monthReleased = 0;

};

//Child Comedy Class
class MovieComedy : public Movie
{
public:
	MovieComedy();
	~MovieComedy();
	void print();
	std::string getMovieType() const;
	bool lessThan(MovieComedy* Rhs) const;
private:
	std::string movieType = "Comedy";
};

//Child Drama Class
class MovieDrama : public Movie
{
public:
	MovieDrama();
	~MovieDrama();
	void print();
	std::string getMovieType() const;
	bool lessThan(MovieDrama* Rhs) const;
private:
	std::string movieType = "Drama";
};

