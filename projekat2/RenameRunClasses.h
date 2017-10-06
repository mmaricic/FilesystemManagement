#ifndef _RENAMERUNCLASSES_H
#define _RENAMERUNCLASSES_H

#include "RunClass.h"

class BasicRename : public RunClass{
public:
	virtual void run(string oldn, string newn)=0;
};
class RenamePath : public BasicRename{
public:
	void run(string oldn, string newn) override;
};
class RenameAlias : public BasicRename{
public:
	void run(string oldn, string newn) override;
};
class RenameSelection : public BasicRename{
public:
	void run(string oldn, string newn) override;
};

class RenameBoth : public BasicRename{
public:
	void run(string oldn, string newn) override;
};

#endif