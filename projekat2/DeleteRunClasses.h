#ifndef _DELETERUNCLASSES_H
#define _DELETERUNCLASSES_H

#include "RunClass.h"

class BasicDelete : public RunClass{
protected:
	bool flag;
public:
	BasicDelete(bool f) :flag(f){}
	virtual bool run(string str);
};
class DeletePath : public BasicDelete{
public:
	DeletePath(bool f) :BasicDelete(f) {}
	bool run(string str) override;
};
class DeleteAlias : public BasicDelete{
public:
	DeleteAlias(bool f) :BasicDelete(f) {}
	bool run(string str) override;
};
class DeleteSelection : public BasicDelete{
public:
	DeleteSelection(bool f) :BasicDelete(f) {}
	bool run(string str) override;
};

class DeleteBoth : public BasicDelete{
public:
	DeleteBoth(bool f) :BasicDelete(f) {}
	bool run(string str) override;

};

#endif