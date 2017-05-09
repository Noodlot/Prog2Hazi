#include <string>
#include <vector>
#include "lists.h"
#include "movie.h"
#include "studio.h"
#include <iostream>



int main()
{
	std::cout << "Udvozlet!" << std::endl << "Csak Csongor Programozas Alapjai 2 Nagy Hazifeladataban!" << std::endl << "Remelem tetszeni fog!" << std::endl << std::endl << std::endl;
	check();

	//----------Elso feladat:----------

	std::vector<studio> studioVector;
	studioVector = readFromSFile("Studios.txt");
	std::cout << std::endl << "----------Elso feladat:----------" << std:: endl << "Irjuk ki milyen studiok vannak!:\n\n" << std::endl;
	studios(studioVector);
	
	check();

	//----------Masodik feladat:----------

	std::vector<movie> movieVector;
	movieVector = readFromMFile("Movies.txt");
	std::cout << std::endl << "----------Masodik feladat:----------"<< std::endl << "Irjuk ki studionkent a filmeket!:\n\n" << std::endl;
	studioMovies(studioVector, movieVector);

	check();

	//----------Harmadik feladat:----------

	std::cout << std::endl << "----------Harmadik feladat:----------" << std::endl << "Irjuk ki a maximalis Imdb pontszammal rendelkezo filmet!:\n\n" << std::endl;
	maxImdb(movieVector);

	check();

	//----------Negyedik feladat:----------

	std::string tempString;
	movie readMovie;
	std::cout << std::endl << "----------Negyedik feladat:----------" << std::endl << "Adjunk hozza egy filmet!:\n" << std::endl;
	std::cout << "De elobb add meg a film cimet, aztan a gyartasi evet(egesz), imdb pontszamot(tort), rendezonevet, foszereplo nevet, filmgyar azonositojat(1-6)! (enterrel valaszdd el oket)  : \n" << std::endl;
	std::getline(std::cin, tempString);
	readMovie.setMovieName(tempString);
	std::getline(std::cin, tempString);
	readMovie.setMovieMade(atoi(tempString.c_str()));
	std::getline(std::cin, tempString);
	readMovie.setMovieImdb(atof(tempString.c_str()));
	std::getline(std::cin, tempString);
	readMovie.setMovieDirName(tempString);
	std::getline(std::cin, tempString);
	readMovie.setMovieStarName(tempString);
	std::getline(std::cin, tempString);
	readMovie.setMovieId(atoi(tempString.c_str()));
	
	movieVector.push_back(readMovie);

	std::cout << " ... Hozzaadva ..." << std::endl;

	check();

	//----------Otodik feladat:----------

	std::string s = "Twelve Monkeys";
	std::cout << std::endl << "----------Otodik feladat:----------" << std::endl << "Irjuk ki ki rendezte az alabbi filmet: " << s << std::endl;
	whoDirected(movieVector, s);

	check();

	//----------Hatodik feladat:----------

	std::cout << std::endl << "----------Hatodik feladat:----------" << std::endl << "Rendezzuk a filmeket IMDB pontszam szerint, majd irjuk ki egy file-ba rendezve a filmeket!\n\n" << std::endl;
	imdbSort(movieVector);
	save2File("Result.txt", movieVector);
	std::cout << "...Eredmenyek a Result.txt fileban..." << std::endl;

	std::cout << "Ennyi volt. Viszlat!" << std::endl << std::endl << std::endl;

	return 0;
}
