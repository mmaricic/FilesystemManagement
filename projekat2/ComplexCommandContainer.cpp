#include "ComplexCommandContainer.h"


void ComplexCommandContainer::add(string name, ComplexCommand* cc) {
	newCommands.insert(make_pair(name, cc));
}

void ComplexCommandContainer::operator()(const vector<string> &elem) {
	int i = newCommands.find(elem[0])->second->argNum();
	if (i != elem.size() - 1) {
		cout << "Invalid argument number!" << endl;
		return;
	}
	vector<string> args = elem;
	args.erase(args.begin());
	newCommands.find(elem[0])->second->run(args);
}

ComplexCommandContainer::~ComplexCommandContainer(){
	for (auto itr = newCommands.begin(); itr != newCommands.end(); itr++)
		delete itr->second;
}

void ComplexCommandContainer::help() {
	cout << "Make complex command using simple and old complex commands.\nSyntax is: new [NAME]" << endl
		<< "(add [COMMAND])+" << endl
		<< "end" << endl;
}