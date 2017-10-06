#include "Selection.h"
#include "Select.h"

Selection* Selection::instance = nullptr;

bool Selection::makeTempSel(string str, vector<string> temp, string &source){
	Select s;
	temp.push_back("select");
	temp.push_back("%temp%");
	temp.push_back(str);
	s(temp);
	source = "%temp%";
	return true;
}

void Selection::removeTempSel(){
	vector<File *> v = instance->find("%temp%")->second;
	for (int i = 0; i < v.size(); i++)
		delete v[i];
	instance->erase("%temp%");
}
