#ifndef _USER_H
#define _USER_H


#include <map>
#include "cmnd.h"
#include "Alias.h"
#include "Selection.h"
#include "Assign.h"
#include "Cd.h"
#include "Copy.h"
#include "Delete.h"
#include "Exit.h"
#include "list.h"
#include "mkdir.h"
#include "Path.h"
#include "Move.h"
#include "remove.h"
#include "rename.h"
#include "Select.h"
#include "Setts.h"
#include "Info.h"

using namespace std;

vector<string> split(string s, char delim);

class User: public map<string, Cmnd*>{
public:
	User(Alias *a, Selection* s){ Cmnd::setPtr(a, s); }
	virtual ~User() =0;
};


class PublicUser : public User{
	static PublicUser* instance;
	PublicUser(Alias *a, Selection* s);
	PublicUser(PublicUser const&) = delete;
	void operator=(PublicUser const&) = delete;
public:
	static PublicUser* makeObject(Alias *a, Selection* s);
	~PublicUser(){
		for (auto itr = this->begin(); itr != this->end(); itr++)
			delete itr->second;
	}
};

class Admin : public User{
	static Admin* instance;
	Admin(Alias *a, Selection* s);
	Admin(Admin const&) = delete;
	void operator=(Admin const&) = delete;
public:
	static void loadConf(Alias *a, Selection* s);
	static Admin* makeObject(Alias *a, Selection* s);
	~Admin(){
		for (auto itr = this->begin(); itr != this->end(); itr++)
			delete itr->second;
	}
};

#endif