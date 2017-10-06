#include "DeleteRunClasses.h"

bool DeletePath::run(string str){
	File f(str);
	f.exists();
	string s = f.getPath();
	if (!flag)
	{
		if (exists(current_path().string() + "\\" + str)) s = current_path().string() + "\\" + str;
		f.changePath(current_path().string());
		f.isChild(s);
	}
	BasicDelete::run(str);
	return true;
}