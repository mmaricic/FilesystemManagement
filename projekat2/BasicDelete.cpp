#include "DeleteRunClasses.h"

bool BasicDelete::run(string str){
	if (is_directory(str))
		if (!boost::filesystem::is_empty(str)){
		string c;
		path temp = str;
		if (!flag) {
			std::cout << "Folder " << temp.filename().string() << " is not empty! Do you want to delete it and all of its content? y/n" << endl;
			getline(cin, c);
			if (c == "y"){
				remove_all(str);
				return true;
			}
			else if (c == "n") return false;
			else {
				std::cout << "Wrong input" << endl;
				return false;
			}
		}
		else remove_all(str);
		}
	remove(str);
	return true;
}