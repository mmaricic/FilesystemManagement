#ifndef _ALIAS_H
#define _ALIAS_H

#include <boost\filesystem.hpp>
#include <iostream>
#include <string>
#include <map>
#include "File.h"

using namespace std;
using namespace boost::filesystem;

class Alias : public map < string, File* > {
	static Alias* instance;
	Alias() {}
	Alias(Alias const&) = delete;
	void operator=(Alias const&) = delete;
public:
	static void exist(string s) {
		if (!exists(s))
			throw EAliasEmpty();
	}

	static Alias* makeObject(){
		if (instance == nullptr){
			static Alias something;
			instance = &something;
		}
		return instance;
	}
	~Alias() {
		for (auto itr = this->begin(); itr != this->end(); itr++)
			delete itr->second;
	}
};

#endif