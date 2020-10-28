/**
@file CommandPlus.h
*/
#pragma once
#include<conio.h>

class CommandPlus {
private:
	char command{};

public:
	CommandPlus();
	char getCommand();
	void setCommand();
};