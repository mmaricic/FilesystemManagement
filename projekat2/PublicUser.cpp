#include "user.h"
#include "ComplexCommandContainer.h"

PublicUser* PublicUser::instance = nullptr;

PublicUser::PublicUser(Alias *a, Selection* s) : User(a, s) {
	this->insert(make_pair("cd", new Cd()));
	this->insert(make_pair("exit", new Exit()));
	this->insert(make_pair("list", new List()));
	this->insert(make_pair("path", new Path()));
	this->insert(make_pair("remove", new Remove()));
	this->insert(make_pair("cc", new ComplexCommandContainer()));
	this->insert(make_pair("info", new Info()));
}

PublicUser* PublicUser::makeObject(Alias *a, Selection* s){
	if (instance == nullptr){
		instance = new PublicUser(a, s);
		return instance;
	}
	else return nullptr;
}

