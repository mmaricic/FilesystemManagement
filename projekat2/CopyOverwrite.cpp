#include "CopyRunClasses.h"



bool CopyOverwrite::run(string in, string out, size_t &currCopy, size_t &all){
	BasicCopy::run(in, out, currCopy, all);
	return true;
}