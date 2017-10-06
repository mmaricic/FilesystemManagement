#ifndef _SETTS_H
#define _SETTS_H

#include "cmnd.h"

class Setts: public Cmnd{
public:
	void operator()(const vector<string> &elem) override;
	void help() override;
	int argNum() const override { return 3; }
};

#endif