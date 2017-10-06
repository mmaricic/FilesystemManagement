#include "RunClass.h"

Alias* RunClass::ptrAlias = nullptr;
Selection* RunClass::ptrSel = nullptr;
RunClass::~RunClass() {}

string RunClass::getType(string name){
	File f(name);
	if (f.exists()) return "p";
	if (ptrAlias->count(name) && ptrSel->count(name)) return "b";
	if (ptrAlias->count(name)) return "a";
	if (ptrSel->count(name)) return "s";
	throw EInvalidArg();
}

