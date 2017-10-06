#include "cmnd.h"

Alias *Cmnd::ptrAlias = nullptr;
Selection *Cmnd::ptrSel = nullptr;

bool Cmnd::checkArg(const vector<string> &elem){
	if (elem.size() == 1 && elem[0] == "help") {
		help();
		return false;
	}
	if (elem.size() != argNum()) {
		cout << "Wrong syntax" << endl;
		help();
		return false;
	}
	return true;
}