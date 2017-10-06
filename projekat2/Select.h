#ifndef _SELECT_H
#define _SELECT_H

#include "cmnd.h"

class Select : public Cmnd{
public:
	virtual void operator()(const vector<string> &elem) override;
	virtual void help() override;
	int argNum() const override { return 2; }
};

#endif