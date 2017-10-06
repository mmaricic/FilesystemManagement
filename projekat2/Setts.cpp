#include "Setts.h"
#include "RunClass.h"
#include <iomanip> 

void Setts::operator()(const vector<string> &elem) {
	if (!checkArg(elem)) return;
	string source = elem[0], timestr = elem[1];
	bool rem = 0;
	std::time_t rawtime;
	if (source.find('*') != std::string::npos){
		vector<string> temp;
		rem = ptrSel->makeTempSel(elem[0], temp, source);
	}
	if (RunClass::getType(source) != "s") throw ENotSelection();
	if (elem.size() == 4){
		timestr = timestr + " " + elem[2];
		struct tm structtime;
		std::istringstream ss(timestr);
		ss >> get_time(&structtime, "%d.%m.%Y. %H:%M:%S");
		rawtime = mktime(&structtime);
	}
	else 
		time(&rawtime);
	vector<File *> v = ptrSel->find(source)->second;
	for (int i = 0; i < v.size(); i++){
		path p(v[i]->getPath());
		last_write_time(p, rawtime);
	}
	if (rem) ptrSel->removeTempSel();
}

void Setts::help(){
	cout << "Change selections timestamp.\nSyntax  of command SETTS is: setts [SELECTION] [NEW_TIMESTAMP(format dd.mm.yyyy hh:mm:ss)]" << endl;
}