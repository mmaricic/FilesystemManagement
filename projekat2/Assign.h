#ifndef _ASSIGN_H
#define _ASSIGN_H

#include "cmnd.h"

class Assign : public Cmnd{
public:
	void operator()(const vector<string> &elem) override;
	void help() override;
	int argNum() const override { return 2; }
};

#endif