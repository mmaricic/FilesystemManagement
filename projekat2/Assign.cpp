#include "Assign.h"

void Assign::operator()(const vector<string> &elem) {
	if (!checkArg(elem)) return;
	if (ptrAlias->count(elem[0])){
		cout << "Alias alredy exists" << endl;
		return;
	}
	if (elem[1][1] != ':' && elem[1][2] != '\\'){
		cout << "Invalid path!" << endl;
		return;
	}
	if (!exists(elem[1]))
		cout << "Alias is set for nonexistent path" << endl;
	ptrAlias->insert(make_pair(elem[0], new File(elem[1])));

}

void Assign::help() {
	cout << "Make alias for folder.\nSyntax of command ASSIGN is: assign [ALIAS] [FULL_PATH]" << endl;
}