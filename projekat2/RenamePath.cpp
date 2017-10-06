#include "RenameRunClasses.h"

void RenamePath::run(string oldn, string newn){
	string s = oldn;
	if (exists(current_path().string() + "\\" + oldn)) s = current_path().string() + "\\" + oldn;
	path p(s);
	string temp = p.remove_filename().string() + "\\" + newn;
	rename(s, temp);
}