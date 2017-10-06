#ifndef _COPYRUNCLASSES_H
#define _COPYRUNCLASSES_H

#include <string>
#include <iostream>
#include <boost\filesystem.hpp>

using namespace std;
using namespace boost::filesystem;

class BasicCopy{
protected:
	bool flag;
public:
	BasicCopy(bool f) :flag(f) {}
	virtual bool run(string in, string out, size_t &currCopy, size_t &all);
};
class CopySkip : public BasicCopy{
public:
	CopySkip(bool f) :BasicCopy(f) {}
	bool run(string in, string out, size_t &currCopy, size_t &all) override;
};

class CopyOverwrite : public BasicCopy{
public:
	CopyOverwrite(bool f) :BasicCopy(f) {}
	bool run(string in, string out, size_t &currCopy, size_t &all) override;
};

class CopyRename : public BasicCopy{
public:
	CopyRename(bool f) :BasicCopy(f) {}
	bool run(string in, string out, size_t &currCopy, size_t &all) override;

};

class CopyAbort : public BasicCopy{
public:
	CopyAbort(bool f) :BasicCopy(f) {}
	bool run(string in, string out, size_t &currCopy, size_t &all) override;
};

#endif