#ifndef _COPYSETCLASSES_H
#define _COPYSETCLASSES_H

#include "RunClass.h"
#include <string>

class BasicSet : public RunClass{
protected:
	bool flag;
public:
	BasicSet(bool f) :flag(f){}
	virtual string set(string str) =0;
};
class SetCopyPath : public BasicSet{
public:
	SetCopyPath(bool f) :BasicSet(f) {}
	string set(string str) override;
};
class SetCopyAlias : public BasicSet{
public:
	SetCopyAlias(bool f) :BasicSet(f) {}
	string set(string str) override;
};
#endif