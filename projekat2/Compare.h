#pragma once
#include "cmnd.h"

class Compare: public Cmnd{
public:
	void operator()(const vector<string> &elem) override;
	void help() override;
	int argNum() const override { return 2; }
};

