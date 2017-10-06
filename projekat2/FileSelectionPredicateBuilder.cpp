#include "FileSelectionPredicateBuilder.h"
#include <regex>

FileSelectionPredicateBuilder* FileSelectionPredicateBuilder::instance = nullptr;

FileSelectionPredicate* FileSelectionPredicateBuilder::build(string &str) {
	if (!str.compare(0, 3, "AND")){
		AND *and = new AND();
		vector<string> params = getParams(str);
		for (string param : params)
			and->add(build(param));
		return and;
	}
	if (!str.compare(0, 2, "OR")){
		OR *or = new OR();
		vector<string> params = getParams(str);
		for (string param : params)
			or->add(build(param));
		return or;
	}
	if (!str.compare(0, 3, "NOT")){
		NOT *not = new NOT();
		vector<string> params = getParams(str);
		for (string param : params)
			not->add(build(param));
		return not;
	}
	return makeSimplePredicate(str);
}

FileSelectionPredicate* FileSelectionPredicateBuilder::makeSimplePredicate(string &str) {
	if (!str.compare(0, 4, "name")){
		regex reg("name=(.*)");
		smatch result;
		regex_match(str, result, reg);
		FileNamePredicate *name = new FileNamePredicate(result[1].str());
		return name;}
	if (!str.compare(0, 4, "size")){
		FileSizePredicate *size;
		regex reg("size=(.*)~(.*)");
		smatch result;
		regex_match(str, result, reg);
		if (result.size() == 3)
			size = new FileSizePredicate(stold(result[1].str()), stold(result[2].str()));
		else{
			reg = ("size=(.*)");
			regex_match(str, result, reg);
			size = new FileSizePredicate(stold(result[1].str()));
		}
		return size;
	}
	if (!str.compare(0, 4, "time")){
		regex reg("time=(.*)~(.*)");
		smatch result;
		regex_match(str, result, reg);
		FileTimestampPredicate *time;
		if (result.size() == 3)
			time = new FileTimestampPredicate(result[1].str(), result[2].str());
		else{
			reg = "time=(.*)";
			regex_match(str, result, reg);
			time = new FileTimestampPredicate(result[1].str());
		}
		return time;
	}
}

vector<string> FileSelectionPredicateBuilder::getParams(string &str){
	vector<string> temp;
	regex reg("([A-Z]+)\\((.*)\\)");
	smatch result;
	regex_match(str, result, reg);
	string help = result[1];
	str = result[2];
	if (help == "NOT") {
		temp.push_back(str);
		return temp;
	}
	int bracketCount = 0, oldpos = 0, newpos;
	while ((newpos = str.find(',', oldpos)) != std::string::npos){
		for (int i = oldpos; i < newpos; i++){
			if (str[i] == '(')
				bracketCount++;
			if (str[i] == ')')
				bracketCount--;
		}
		if (!bracketCount){
			temp.push_back(str.substr(0, newpos));
		}
		oldpos = newpos + 1;
		if (temp.size()) break;
	}
	temp.push_back(str.substr(oldpos, str.length() - oldpos));
	return temp;
}
