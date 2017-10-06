#include "remove.h"

void Remove::operator()(const vector<string> &elem){
	if (elem.size() != argNum()) {
		cout << "Wrong syntax" << endl;
		help();
		return;
	}
	string c;
	if (ptrAlias->count(elem[0]) && ptrSel->count(elem[0])){
		std::cout << "Do you want to remove Alias folder or Selection? Type a for Alias, and s for Selection: ";
		getline(cin, c);
		if (c == "a")
			RemoveAlias(elem[0]);
		else
		if (c == "s")
			RemoveSelection(elem[0]);
		else throw Einput();
		return;
	}
		if (ptrAlias->count(elem[0])){
			RemoveAlias(elem[0]);
			return;
		}
		if (ptrSel->count(elem[0])){
			RemoveSelection(elem[0]);
			return;
		}
	cout << "Wrong input. There is no alias/selection with given name" << endl;
}


void Remove::RemoveAlias(string elem) {
	delete ptrAlias->find(elem)->second;
	ptrAlias->erase(elem);
	cout << "Alias removed" << endl;
}
void Remove::RemoveSelection(string elem) {
	vector<File*> v = ptrSel->find(elem)->second;
	for (int i = 0; i < v.size(); i++) {
		delete v[i];
	}
	ptrSel->erase(elem);
	cout << "Selection removed" << endl;
	return;
}

void Remove::help() {
	cout << "Removes alias/selection. Syntax  of command REMOVE is: remove [ALIAS] || [SELECTION]" << endl;
}