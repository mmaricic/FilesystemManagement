#ifndef _PATH_H
#define _PATH_H

#include "cmnd.h"

class Path : public Cmnd{
public:
	void operator()(const vector<string> &elem) override;
	void help() override;
	int argNum() const override { return 0; }
};

#endif