#ifndef _FILE_H
#define _FILE_H
#include <string>
#include <boost\filesystem.hpp>
#include <iostream>
#include "except.h"

using namespace std;
using namespace boost::filesystem;

class File{
	string p;
public:
	explicit File(string pp) :p(pp) {}
	string getPath() const { return p; }
	time_t getTime();
	long double getSize() const;
	bool exists() { if (boost::filesystem::exists(p)) return true; return false; }
	void changePath(string s) { p = s; }
	bool isParent(string ch) { if (ch.find(p) != std::string::npos) return true; return false; }
	bool isChild(string par) { if (p.find(par) != std::string::npos) return true; return false; }
};

#endif