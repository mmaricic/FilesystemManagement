#include "Path.h"

void Path::operator()(const vector<string> &elem){
	if (!checkArg(elem)) return;
	cout << current_path().string() << endl;
}

void Path::help() {
	cout << "Get path of current working folder.\nSyntax  of command PATH is: path" << endl;
}