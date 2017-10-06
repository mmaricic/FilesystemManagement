#include "CompareClass.h"
#include "CompareBuilder.h"

static Selection* ptrSel = nullptr;

bool Diference::compare(File file1, File file2){
	path p1(file1.getPath());
	path p2(file2.getPath());
	if (p2.filename().string() != p1.filename().string())
		return true;
	return false;
}