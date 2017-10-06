#include "CompareClass.h"
#include "CompareBuilder.h"

static Selection* ptrSel = nullptr;

bool Intersection::compare(File file1, File file2){
	path p1 = file1.getPath(), p2 = file2.getPath();
	return ((p1.filename().string() == p2.filename().string()) && (file1.getSize() == file2.getSize()) && (file1.getTime() == file2.getTime()));
}