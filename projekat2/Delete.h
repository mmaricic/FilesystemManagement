#ifndef _DELETE_H
#define _DELETE_H

#include "cmnd.h"
#include "DeleteRunClasses.h"

class Delete : public Cmnd{
	int flag = 0;
	  map<string, BasicDelete*> RunningFunc;
public:
	int argNum() const override { return 1; }
	Delete();
	void setFlag(int a) { flag = a; }
	void operator()(const vector<string> &elem) override;
	void help() override;
	~Delete(){
		for (auto itr = RunningFunc.begin(); itr != RunningFunc.end(); itr++)
			delete itr->second;
	}
};

#endif