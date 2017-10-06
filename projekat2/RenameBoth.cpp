#include "RenameRunClasses.h"

void RenameBoth::run(string oldn, string newn){
	string c;
	std::cout << "Do you want to rename Alias folder or Selection? Type a for Alias, and s for Selection: ";
	getline(cin, c);
	if (c == "a"){
		RenameAlias ra;
		ra.run(oldn, newn);
	}
	else
	if (c == "s"){
		RenameSelection rs;
		rs.run(oldn, newn);
	}
	else
	throw Einput();
}