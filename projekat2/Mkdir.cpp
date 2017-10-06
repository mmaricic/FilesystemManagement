#include "mkdir.h"

void Mkdir::operator()(const vector<string> &elem){
	if (!checkArg(elem)) return;
	if (create_directory(elem[0]))
		cout << "Folder created." << endl;
	else cout << "Folder already exists" << endl;
	
}

void Mkdir::help(){
	cout << "Make folder.\nSyntax  of command MKDIR is: mkdir [FOLDER_NAME]" << endl;
}