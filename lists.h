#pragma once
#include "studio.h"
#include "movie.h"
#include <vector>
#include <string>


//functions

void clrscr();

void check();

std::vector<studio> readFromSFile(const char* fileName);

std::vector<movie> readFromMFile(const char* fileName);

void studios(std::vector<studio> studioVector);

void studioMovies(std::vector<studio> studioVector, std::vector<movie> movieVector);

void maxImdb(std::vector<movie> movieVector);

void whoDirected(std::vector<movie> movieVector, std::string title);

void swap(movie *a, movie *b);

void imdbSort(std::vector<movie> &movieVector);

void save2File(const char* fileName, std::vector<movie> movieVector);
