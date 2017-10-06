#ifndef _MOVE_H
#define _MOVE_H

#include "cmnd.h"

class Move : public Cmnd{
public:
	void operator()(const vector<string> &elem) override;
	void help() override;
	int argNum() const override { return 2; }
};

#endif