#pragma once

#include "cmnd.h"

class Info : public Cmnd{
public:
	void operator()(const vector<string> &elem) override;
	void help() override;
	int argNum() const override { return 0; }
};

