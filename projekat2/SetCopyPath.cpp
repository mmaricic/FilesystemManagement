#include "CopySetPathClasses.h"

string SetCopyPath::set(string str) {
	File f(str);
	string s;
	f.exists();
	if (exists(s = current_path().string() + "/" + str))
		f.changePath(s);
	return f.getPath();
}