#include "DeleteRunClasses.h"

bool DeleteSelection::run(string str){
	bool check = 1;
	vector<File*> v = ptrSel->find(str)->second;
	for (int i = 0; i < v.size(); i++) {
		string s = v[i]->getPath();
		if (exists(s)){
			File f(current_path().string());
			f.isChild(s);
			if (check) check = BasicDelete::run(s);
		}
		delete v[i];
	}
	ptrSel->erase(str);
	if (!check) std::cout << "Not all folders are deleted. Selection is removed!" << endl;
	return true;
}