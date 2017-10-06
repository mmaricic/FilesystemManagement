#ifndef _COPY_H
#define _COPY_H

#include "cmnd.h"
#include "Selection.h"
#include "Alias.h"
#include "CopySetPathClasses.h"
#include "CopyRunClasses.h"
#include <fstream>
#include <queue>
#include <iostream>

using namespace std;
using namespace boost::filesystem;

typedef pair<string, string> two;

class Copy : public Cmnd{
	bool checkIfExists(string out) {
		File pout(out);
		return pout.exists();
	}
	int flag = 0;
	map<string, BasicSet*> SetFunc;
	map<string, BasicCopy* > RunningFunc;
	void setAll(string in, string out, string &choiceflag);
	void StartCopy(queue<two> fin, size_t &copySize, size_t &size, string &choiceflag);
public:
	Copy();
	void setFlag(int a) { flag = a; }
	void operator()(const vector<string> &elem) override;
	void help() override;
	int argNum() const override { return 2; }
	~Copy();
};

#endif