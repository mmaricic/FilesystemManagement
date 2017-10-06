#include "Move.h"
#include "Copy.h"
#include "Delete.h"
#include "except.h"

void Move::operator()(const vector<string> &elem) {
	if (!checkArg(elem)) return;
	try{
		Copy c;
		c.setFlag(1);
		c(elem);
		Delete d;
		vector<string> v;
		v.push_back(elem[0]);
		d.setFlag(1);
		d(v);
	}
	catch (EIsParent &e) {
		cout << e;
	}
}


void Move::help() {
	cout << "Moves files/folders. Syntax of command MOVE is: move [SOURCE] [DESTINATION]" << endl;
}