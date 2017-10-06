#pragma once
#include "cmnd.h"
#include <map>
#include <string>
#include "ComplexCommand.h"

using namespace std;

class ComplexCommandContainer: public Cmnd{
public:
	map<string, ComplexCommand*> newCommands;
	void operator()(const vector<string> &elem) override;
	void help() override;
	void add(string name, ComplexCommand* cc);
	int argNum() const override { return 0; }
	~ComplexCommandContainer();
};

