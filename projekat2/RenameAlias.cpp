#include "RenameRunClasses.h"

void RenameAlias::run(string oldn, string newn){
	File *f = ptrAlias->find(oldn)->second;
	ptrAlias->erase(oldn);
	ptrAlias->insert(make_pair(newn, f));
}