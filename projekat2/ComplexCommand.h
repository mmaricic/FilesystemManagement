#pragma once
#include "user.h"

class ComplexCommand{
	User* user;
	vector<string> commands;
public:
	ComplexCommand(vector<string> cmnd, User* u) :commands(cmnd), user(u) {}
	void run(vector<string> arg);
	int argNum();
};

