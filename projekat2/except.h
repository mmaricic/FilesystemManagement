#ifndef _EXCEPT_H
#define _EXCEPT_H

#include <iostream>

using namespace std;

class EInvalidPath {
	friend ostream& operator<<(ostream& os, const EInvalidPath& e){
		return os << "Invalid path!" << endl;
	}
};

class EAliasEmpty {
	friend ostream& operator<<(ostream& os, const EAliasEmpty& e){
		return os << "Alias is empty!There is no valid file/folder." << endl;
	}
};

class EIsParent{
	friend ostream& operator<<(ostream& os, const EIsParent& e){
		return os << "Can't move folder in his child folder." << endl;
	}
};

class EIsChild{
		friend ostream& operator<<(ostream& os, const EIsChild& e){
			return os << "You can't delete root folder of current working directory" << endl;
		}
};

class EInvalidArg{
	friend ostream& operator<<(ostream& os, const EInvalidArg& e){
		return os << "Invalid source/destination!" << endl;
	}
};

class ECopyInSel{
	friend ostream& operator<<(ostream& os, const ECopyInSel& e){
		return os << "You can't copy in selection!" << endl;
	}
};


class Einput{
	friend ostream& operator<<(ostream& os, const Einput& e){
		return os << "Invalid input" << endl;
	}
};

class ENotSelection{
	friend ostream& operator<<(ostream& os, const ENotSelection& e){
		return os << "There is no selection with the given name" << endl;
	}
};

#endif