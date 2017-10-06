#include "CompareClass.h"

Selection* CompareClass::ptrSel = nullptr;

vector<File *> CompareClass::run(vector<string> selections){
	vector<File *> selection1 = ptrSel->find(selections[0])->second;
	vector<File *> newSel, selection2 = ptrSel->find(selections[1])->second;
	for (int i = 0; i < selection1.size(); i++){
		File file1 = File(selection1[i]->getPath());
		if (exists(selection1[i]->getPath())){
			for (int j = 0; j < selection2.size(); j++){
				File file2 = File(selection2[j]->getPath());
				if (exists(selection1[j]->getPath()) && compare(file1, file2))
					newSel.push_back(new File(file1));
			}
		}
	}
	return newSel;
}