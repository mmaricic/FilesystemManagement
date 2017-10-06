#include "CompareBuilder.h"

CompareBuilder* CompareBuilder::instance = nullptr;

CompareClass* CompareBuilder::getCompareType(const string &str){
	if (str.compare(0, 5, "DIFERENCE")) return new Diference();
	if (str.compare(0, 12, "INTERSECTION")) return new Intersection();
	throw Einput();
}

vector<string> CompareBuilder::getSelections(string &str){
	vector<string> temp;
	regex reg("[A-Z]+\\((.*)\\)");
	smatch result;
	regex_match(str, result, reg);
	str = result[1];
	reg = "(.*?),(.*?)";
	regex_match(str, result, reg);
	temp.push_back(result[1].str());
	temp.push_back(result[2].str());
	return temp;
}