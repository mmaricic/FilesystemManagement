#ifndef _REMOVE_H
#define _REMOVE_H

#include "cmnd.h"

class Remove : public Cmnd{
	void RemoveAlias(string elem);
	void RemoveSelection(string elem);
public:
	void operator()(const vector<string> &elem) override;
	void help() override;
	int argNum() const override { return 1; }
};

#endif