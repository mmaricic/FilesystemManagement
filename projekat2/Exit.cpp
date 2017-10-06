#include "Exit.h"

void Exit::operator()(const vector<string> &elem){
	if (!checkArg(elem)) return;
	saveConf();
	exit(1);
}

void Exit::help(){
	cout << "Close program.\nSyntax  of command EXIT is: exit" << endl;
}

void Exit::saveConf() {
	std::ofstream file;
	string str = ptrAlias->find("_ROOT_PATH_")->second->getPath();
	vector<string> v;
	str += "\\configuration.txt";
		file.open(str);
		for (auto iter = ptrAlias->begin(); iter != ptrAlias->end(); iter++){
			file << iter->first << " " << iter->second->getPath() << endl;
		}
		file << "$end$" << endl;
		for (auto iter = ptrSel->begin(); iter != ptrSel->end(); iter++){
			file << "*** " << iter->first << endl;
			vector<File *> v = iter->second;
			for (int i = 0; i < v.size(); i++) {
				file << v[i]->getPath() << endl;
			}
			}
		file << "$end$";

		file.close();
	}