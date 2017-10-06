#include "Help.h"

Help* Help::instance = nullptr;

Help* Help::makeObject(User *u){
	if (instance == nullptr){
		instance = new Help(u);
		return instance;
	}
	else return nullptr;
}

void Help::manual() {
	cout <<"\n****************HELP****************" << endl;
	for (auto iter = user->begin(); iter != user->end(); iter++){
		cout << "Command: " << (iter->first=="cc"?"new":iter->first) << endl;
		iter->second->help();
		cout << endl
		<<"---------------------------------------------------------------------------" << endl;
	}
}

