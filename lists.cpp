#include <conio.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "lists.h"
#include "studio.h"
#include "movie.h"

//function for clearing the screen
void clrscr()
{
	system("cls");
}

//function for pressing any button
void check()
{
	char chk; int j;
	std::cout << "\n\nNyomj egy gombot a kovetkezo feladathoz...";
	chk = _getch();
	j = chk;
	for (int i = 1; i <= 256; i++)
		if (i == j) break;
	clrscr();
}

//function for readin studios from a given file
std::vector<studio> readFromSFile(const char* fileName)
{
	std::vector<studio> studioVector;

	std::ifstream fin;
	fin.open(fileName);
	if (!fin) {
		std::cerr << "Error in opening the file" << std::endl;
	}

	std::string tempstring;
	std::vector<std::string> stringVector;
	studio tempstudio;

	while (std::getline(fin, tempstring)) {
		stringVector.push_back(tempstring);
	}


	for (size_t i = 0; i <= stringVector.size()-1; i++)
	{
		if (i % 4 == 0) 
		{
			tempstudio.setStudioName(stringVector[i]);
		}
		if (i % 4 == 1)
		{
			tempstudio.setStudioFounded ( atoi (stringVector[i].c_str())) ;
		}
		if (i % 4 == 2)
		{
			tempstudio.setStudioHq(stringVector[i]);
		}
		if (i % 4 == 3)
		{
			tempstudio.setStudioId(atoi(stringVector[i].c_str()));
			studioVector.push_back(tempstudio);
		}
	}

	fin.close();
	return studioVector;
}

//function for readin studios from a given file
std::vector<movie> readFromMFile(const char* fileName)
{
	std::vector<movie> movieVector;
	
	std::ifstream fin;
	fin.open(fileName);
	if (!fin) {
		std::cerr << "Error in opening the file" << std::endl;
	}
	movie tempmovie;
	std::string tempstring;
	std::vector<std::string> stringVector;

	while (std::getline(fin, tempstring)) {
		stringVector.push_back(tempstring);
	}
	
	for (size_t i = 0; i <= stringVector.size() - 1; i++)
	{
		if (i % 6 == 0)
		{
			tempmovie.setMovieName(stringVector[i]);
		}
		if (i % 6 == 1)
		{
			tempmovie.setMovieMade(atoi(stringVector[i].c_str()));
		}
		if (i % 6 == 2)
		{
			tempmovie.setMovieImdb(atof(stringVector[i].c_str()));
		}
		
		if (i % 6 == 3) 
		{
			tempmovie.setMovieDirName(stringVector[i]);
		}

		if (i % 6 == 4)
		{
			tempmovie.setMovieStarName(stringVector[i]);
		}
		if (i % 6 == 5)
		{
			tempmovie.setMovieId(atoi(stringVector[i].c_str()));
			movieVector.push_back(tempmovie);
		}
	}

	fin.close();
	return movieVector;

};

//function that gives you back all of the studios
void studios(std::vector<studio> studioVector)
{
	for (size_t i = 0; i <= studioVector.size()-1; i++)
	{
		std::cout << studioVector[i].getStudioName() << std::endl;
	}

}

//function that gives you back all of the movies sorted by studios
void studioMovies(std::vector<studio> studioVector, std::vector<movie> movieVector)
{
	size_t j = 0;
	for (size_t i = 0; i <= studioVector.size() - 1; i++)
	{

		for (j; j <= movieVector.size() - 1; j++)
		{

			if (studioVector[i].getStudioId() == movieVector[j].getMovieId()) //studioId and movieId means the same thing
			{
				std::cout << studioVector[i].getStudioName() << " : ";
				std::cout << movieVector[j].getMovieName() << std::endl;
			}
		}
		j = 0;
	}
}

//function that gives you back the movie with the highest Imdb number
void maxImdb(std::vector<movie> movieVector)
{
	double max = 0.0;

	for (size_t i = 0; i <= movieVector.size()-1; i++)
	{

		if (movieVector[i].getMovieImdb() > max)
			max = movieVector[i].getMovieImdb();
	}

	for (size_t i = 0; i <= movieVector.size()-1; i++)
	{
		if (movieVector[i].getMovieImdb() == max)
			std::cout << movieVector[i].getMovieName() << std::endl;
	}

}

//function that gives you back the director of the given movie
void whoDirected(std::vector<movie> movieVector, std::string title)
{
	int loop = 0;
	for (size_t i = 0; i <= movieVector.size()-1; i++)
	{
		if (movieVector[i].getMovieName() == title) //if it exists
		{
			std::cout << movieVector[i].getMovieDirName() << std::endl;
			loop = 1;
		}
	}
	if (loop == 0) //if it doesn't exist
		std::cout << "Nincs ilyen film. Biztos vagy benne, hogy jo cimet adtal meg?" << std::endl;

}

//basic swapping function
void swap(movie *a, movie *b)
{
	movie temp = *a;
	*a = *b;
	*b = temp;
}

//soring function
void imdbSort(std::vector<movie> &array)
{
	for (size_t i = 0; i < array.size()-1; i++) //first vector
	{
		for (size_t j = 0; j < array.size() - 1; j++) //second vector
		{
			if (array[j].getMovieImdb() > array[j + 1].getMovieImdb()) //comparing
				swap(&array[j], &array[j + 1]); //swapping
		}
	}
}

//saving to file function
void save2File(const char* fileName, std::vector<movie> movieVector)
{
	//open file
	std::ofstream fout(fileName);
	if (fout.is_open()) //if opening was succesful
	{
		for (size_t i = 0; i <= movieVector.size() - 1; i++) //write everything to the file
		{
		fout << movieVector[i].getMovieName() << std::endl;
		fout << movieVector[i].getMovieMade() << std::endl;
		fout << movieVector[i].getMovieImdb() << std::endl;
		fout << movieVector[i].getMovieDirName() << std::endl;
		fout << movieVector[i].getMovieStarName() << std::endl;
		fout << movieVector[i].getMovieId() << std::endl;
		}
		fout.close(); //close
	}
	else std::cout << "Unable to open file";  //if opening wasn't succesful
}