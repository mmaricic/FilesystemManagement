#include "RenameRunClasses.h"

void RenameSelection::run(string oldn, string newn){
	vector<File *>f = ptrSel->find(oldn)->second;
	ptrSel->erase(oldn);
	ptrSel->insert(make_pair(newn, f));
}