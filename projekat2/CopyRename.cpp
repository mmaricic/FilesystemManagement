#include "CopyRunClasses.h"


bool CopyRename::run(string in, string out, size_t &currCopy, size_t &all){
	path p(out);
	string newOut = p.remove_filename().string() + p.stem().string() + "(1)" + p.extension().string();
	BasicCopy::run(in, newOut, currCopy, all);
	return true;
}