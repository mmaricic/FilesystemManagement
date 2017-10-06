#pragma once
#include "FileSelectionDerived.h"
#include "FileSelectionPredicate.h"
#include "LogicalOp.h"



class FileSelectionPredicateBuilder{
	static FileSelectionPredicateBuilder* instance;
	FileSelectionPredicateBuilder() {}
	FileSelectionPredicateBuilder(FileSelectionPredicateBuilder const&) = delete;
	void operator=(FileSelectionPredicateBuilder const&) = delete;
public:
	static FileSelectionPredicateBuilder* makeObject(){
		if (instance == nullptr){
			static FileSelectionPredicateBuilder something;
			instance = &something;
		}
		return instance;
	}
	FileSelectionPredicate* build(string &str);
	vector<string> getParams(string &str);
	FileSelectionPredicate* makeSimplePredicate(string &str);
	
};

