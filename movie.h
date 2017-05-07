#pragma once
#include <string>

class movie
{
	std::string movieName;
	int movieMade;
	double movieImdb;
	std::string movieDirName;
	std::string movieStarName;
	int movieId;
public:
	movie();
	movie(std::string movieName, int movieMade, double movieImdb, std::string movieDirName, std::string movieStarName, int movieId);

	std::string getMovieName() const;
	int getMovieMade() const;
	double getMovieImdb() const;
	std::string getMovieDirName() const;
	std::string getMovieStarName() const;
	int getMovieId() const;

	void setMovieName(std::string s);
	void setMovieMade(int i);
	void setMovieImdb(double d);
	void setMovieDirName(std::string s);
	void setMovieStarName(std::string s);
	void setMovieId(int i);

	~movie();
};
