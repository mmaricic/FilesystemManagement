#ifndef _MKDIR_H
#define _MKDIR_H

#include "cmnd.h"

class Mkdir : public Cmnd{
public:
	void operator()(const vector<string> &elem) override;
	void help() override;
	int argNum() const override { return 1; }
};

#endif