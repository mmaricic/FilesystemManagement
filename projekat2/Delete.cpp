#include "Delete.h"
#include "except.h"
#include "File.h"

Delete::Delete() {
	RunningFunc.insert(make_pair("a", new DeleteAlias(flag)));
	RunningFunc.insert(make_pair("s", new DeleteSelection(flag)));
	RunningFunc.insert(make_pair("p", new DeletePath(flag)));
	RunningFunc.insert(make_pair("b", new DeleteBoth(flag)));
}

void Delete::operator()(const vector<string> &elem) {
	if (!checkArg(elem)) return;
	RunningFunc.find(RunClass::getType(elem[0]))->second->run(elem[0]);
}

void Delete::help() {
	cout << "Delete files/folders.\nSyntax  of command DELETE is: delete [FILE]||[FOLDER]||[ALIAS]||[SELECTION]" << endl;
}