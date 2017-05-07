#pragma once
#include <string>

class studio
{
	std::string studioName;
	int studioFounded;
	std::string studioHq;
	int studioId;
public:
	studio();
	studio(std::string studioName, int studioFounded, std::string studioHq, int studioId);

	std::string getStudioName() const;
	int getStudioFounded() const;
	std::string getStudioHq() const;
	int getStudioId() const;

	void setStudioName(std::string s);
	void setStudioFounded(int i);
	void setStudioHq(std::string s);
	void setStudioId(int i);

	~studio();
};
