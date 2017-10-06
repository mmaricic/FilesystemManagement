#include "DeleteRunClasses.h"

bool DeleteAlias::run(string str){
	string s = ptrAlias->find(str)->second->getPath();
	if (s[1] == ':' && s[2] == '\\' && s.length() == 3){
		cout << "Can't delete a partition!" << endl;
		return false;
	}
	if (exists(s)){
		File f(current_path().string());
		if (f.isChild(s)) throw EIsChild();
		if (BasicDelete::run(s)){
			delete ptrAlias->find(str)->second;
			ptrAlias->erase(str);
		}
	}
	return true;
}