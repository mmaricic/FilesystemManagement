#ifndef _CD_H
#define _CD_H

#include "cmnd.h"

class Cd : public Cmnd{
	void set();
public:
	void operator()(const vector<string> &elem) override;
	void help() override;
	int argNum() const override { return 1; }
};

#endif