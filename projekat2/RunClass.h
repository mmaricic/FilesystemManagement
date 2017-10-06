#ifndef _RUNCLASS_H
#define _RUNCLASS_H

#include "Alias.h"
#include "Selection.h"

class RunClass {
protected:
	static Alias *ptrAlias;
	static Selection *ptrSel;
public:
	static string getType(string name);
	static void setPtr(Alias *a, Selection *s) { ptrAlias = a; ptrSel = s; }
	virtual ~RunClass() = 0;
};

#endif