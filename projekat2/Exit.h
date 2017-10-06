#ifndef _EXIT_H
#define _EXIT_H

#include "cmnd.h"

class Exit : public Cmnd{
	void saveConf();
public:
	void operator()(const vector<string> &elem) override;
	void help() override;
	int argNum() const override { return 0; }
};

#endif