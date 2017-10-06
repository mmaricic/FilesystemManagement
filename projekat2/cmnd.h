#ifndef _CMND_H
#define _CMND_H

#include <boost\filesystem.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <time.h>
#include <regex>
#include "Selection.h"
#include "Alias.h"
#include "RunClass.h"

using namespace std;
using namespace boost::filesystem;


class Cmnd{
protected:
	static Alias *ptrAlias;
	static Selection *ptrSel;
public:
	bool checkArg(const vector<string> &elem);
	virtual int argNum() const = 0;
	virtual void operator()(const vector<string> &elem) = 0;
	virtual void help() =0;
	static void setPtr(Alias *a, Selection *s) { ptrAlias = a; ptrSel = s; }
};

#endif