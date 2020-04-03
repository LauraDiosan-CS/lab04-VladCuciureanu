#pragma once
#include "Service.h"
#include <iostream>

class UserInterface
{
private:
	Service service;
	int exitTrigger = 0;
public:
	UserInterface(const Service& service);
	~UserInterface();
	void init();
	void parseUserInput(std::string input);
};

