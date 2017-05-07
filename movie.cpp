#include "movie.h"
#include <string>


movie::movie()
{
}

movie::movie(std::string movieName, int movieMade, double movieImdb, std::string movieDirName, std::string movieStarName, int movieId) : 
	movieName(movieName), movieMade(movieMade), movieImdb(movieImdb), movieDirName(movieDirName), movieStarName(movieStarName), movieId(movieId)
{
}

std::string movie::getMovieName() const
{
	return movieName;
}

int movie::getMovieMade() const
{
	return movieMade;
}

double movie::getMovieImdb() const
{
	return movieImdb;
}

std::string movie::getMovieDirName() const
{
	return movieDirName;
}

std::string movie::getMovieStarName() const
{
	return movieStarName;
}

int movie::getMovieId() const
{
	return movieId;
}

void movie::setMovieName(std::string s)
{
	movieName = s;
}

void movie::setMovieMade(int i)
{
	movieMade = i;
}

void movie::setMovieImdb(double d)
{
	movieImdb = d;
}

void movie::setMovieDirName(std::string s)
{
	movieDirName = s;
}

void movie::setMovieStarName(std::string s)
{
	movieStarName = s;
}

void movie::setMovieId(int i)
{
	movieId = i;
}

movie::~movie()
{
}
