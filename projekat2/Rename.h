#ifndef _RENAME_H
#define _RENAME_H

#include "cmnd.h"
#include "RenameRunClasses.h"

class Rename : public Cmnd{
	map<string, BasicRename*> RunningFunc;
public:
	Rename();
	void operator()(const vector<string> &elem) override;
	void help() override;
	int argNum() const override { return 2; }
	~Rename(){
		for (auto itr = RunningFunc.begin(); itr != RunningFunc.end(); itr++)
			delete itr->second;
	}
};

#endif