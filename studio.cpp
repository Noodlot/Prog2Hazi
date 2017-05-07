#include "studio.h"
#include <string>


studio::studio()
{
}

studio::studio(std::string studioName, int studioFounded, std::string studioHq, int studioId) : studioName(studioName), studioFounded(studioFounded), studioHq(studioHq), studioId(studioId) 
{
}

std::string studio::getStudioName() const 
{ 
	return studioName; 
}

int studio::getStudioFounded() const 
{ 
	return studioFounded; 
}

std::string studio::getStudioHq() const 
{
	return studioHq; 
}

int studio::getStudioId() const 
{ 
	return studioId; 
}

void studio::setStudioName(std::string s) 
{ 
	studioName = s; 
}

void studio::setStudioFounded(int i) 
{ 
	studioFounded = i; 
}

void studio::setStudioHq(std::string s) 
{ 
	studioHq = s; 
}

void studio::setStudioId(int i) 
{ 
	studioId = i; 
}

studio::~studio()
{
}
