#include "FileSelectionDerived.h"
#include <regex>

bool FileNamePredicate::operator()(File &file) {
	if (name.find('*') != std::string::npos){
		regex cmpreg(name);
		if (regex_match(file.getPath(), cmpreg)) return true;
		return false;
	}
	path p = file.getPath();
	return name == p.filename().string();
}

string FileNamePredicate::setName(string &str) {
	if (str.find('*') != std::string::npos){
		size_t pos = 0;
		while ((pos = str.find(".", pos)) != std::string::npos){
			str.replace(pos, 1, "\\.");
			pos += 2;
		}
		pos = 0;
		while ((pos = str.find("*", pos)) != std::string::npos){
			str.replace(pos, 1, ".*");
			pos += 2;
		}
	}
	return str;
}