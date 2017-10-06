#include "Rename.h"

Rename::Rename() {
	RunningFunc.insert(make_pair("a", new RenameAlias()));
	RunningFunc.insert(make_pair("s", new RenameSelection()));
	RunningFunc.insert(make_pair("p", new RenamePath()));
	RunningFunc.insert(make_pair("b", new RenameBoth()));
}


void Rename::operator()(const vector<string> &elem) {
	if (!checkArg(elem)) return;
	RunningFunc.find(RunClass::getType(elem[0]))->second->run(elem[0], elem[1]);
	
}

void Rename::help() {
	cout << "Rename file/folder/alias/selection.\nSyntax  of command RENAME is: rename [OLD_NAME] [NEW_NAME]" << endl;
}