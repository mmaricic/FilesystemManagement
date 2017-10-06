#include "DeleteRunClasses.h"

bool DeleteBoth::run(string str){
	string c;
	if (!flag){
		std::cout << "Do you want to delete Alias folder or elements of Selection? Type a for Alias, s for Selection: ";
		getline(cin, c);
		if (c == "a"){
			DeleteAlias da(flag);
			da.run(str);
		}
		else
			if (c == "s"){
			DeleteSelection ds(flag);
			ds.run(str);
			}
			else
				throw Einput();
		return true;
	}
}