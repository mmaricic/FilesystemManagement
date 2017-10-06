#pragma once
#include "cmnd.h"
#include "Selection.h"

class CompareClass{
protected:
	static Selection* ptrSel;
public:
	static void setPtr(Selection *ptr) { ptrSel = ptr; }
	virtual vector<File *> run(vector<string> selections);
	virtual bool compare(File file1, File file2) = 0;
};

class Diference : public CompareClass{
public:
	bool compare(File file1, File file2) override;
};

class Intersection : public CompareClass{
public:
	bool compare(File file1, File file2) override;
};