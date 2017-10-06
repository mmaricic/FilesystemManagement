#include "cd.h"

void Cd::operator()(const vector<string> &elem){
	if (!checkArg(elem)) return;
	bool check = 0;
	if (exists(elem[0])){
		current_path(elem[0]);
		set();
		return;
	} 
	if (ptrAlias->count(elem[0])){
		File f(ptrAlias->find(elem[0])->second->getPath());
		f.exists();
			current_path(ptrAlias->find(elem[0])->second->getPath());
			set();
			return;
	}
	throw EInvalidPath();
}

void Cd::set() {
	cout << "Path changed" << endl;
	delete ptrAlias->find("#cur")->second;
	delete ptrAlias->find("#par")->second;
	ptrAlias->find("#cur")->second = new File(current_path().string());
	ptrAlias->find("#par")->second = new File(current_path().remove_filename().string());
}

void Cd::help(){
	cout << "Change working folder.\nSyntax of command CD is: cd [PATH]" << endl;
}