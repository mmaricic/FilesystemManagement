#pragma once
#include "user.h"
#include "ComplexCommandContainer.h"

class ComplexCommandBuilder{
	static ComplexCommandBuilder* instance;
	ComplexCommandBuilder() {}
	ComplexCommandBuilder(ComplexCommandBuilder const&) = delete;
	void operator=(ComplexCommandBuilder const&) = delete;
public:
	static ComplexCommandBuilder* makeObject();
	void operator()(const vector<string> &elem, User* user);
	void help();
};

