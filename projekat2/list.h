#ifndef _LIST_H
#define _LIST_H

#include "cmnd.h"

class List : public Cmnd{
public:
	void operator()(const vector<string> &elem) override;
	void help() override;
	int argNum() const override { return 0; }
};

#endif