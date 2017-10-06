#pragma once
#include "CompareClass.h"



class CompareBuilder{
	static CompareBuilder* instance;
	CompareBuilder() {}
	CompareBuilder(CompareBuilder const&) = delete;
	void operator=(CompareBuilder const&) = delete;
public:
	CompareClass* getCompareType(const string &str);
	static CompareBuilder* makeObject(){
		if (instance == nullptr){
			static CompareBuilder something;
			instance = &something;
		}
		return instance;
	}
	vector<string> getSelections(string &str);

};

