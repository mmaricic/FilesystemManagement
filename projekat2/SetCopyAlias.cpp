#include "CopySetPathClasses.h"

string SetCopyAlias::set(string str) {
		string out = ptrAlias->find(str)->second->getPath();
		Alias::exist(out);
		return out;
}