#ifndef _SELECTION_H
#define _SELECTION_H

#include <boost\filesystem.hpp>
#include <iostream>
#include <string>
#include <map>
#include "File.h"

using namespace std;
using namespace boost::filesystem;

class Selection : public map < string, vector<File*> > {
	static Selection* instance;
	Selection() {}
	Selection(Selection const&) = delete;
	void operator=(Selection const&) = delete;
public:
	bool makeTempSel(string str, vector<string> temp, string &source);
	void removeTempSel();
	static Selection* makeObject(){
		if (instance == nullptr){
			static Selection something;
			instance = &something;
		}
			return instance;
	}
	~Selection() {
		for (auto itr = this->begin(); itr != this->end(); itr++)
			for (int i = 0; i < itr->second.size(); i++)
				delete itr->second[i];
	}
};

#endif