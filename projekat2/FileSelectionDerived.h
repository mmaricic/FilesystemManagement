#pragma once
#include "FileSelectionPredicate.h"
#include <vector>

class FileNamePredicate : public FileSelectionPredicate{
	string name;
public:
	static string setName(string &str);
	FileNamePredicate(string &str) { name = setName(str); }
	bool operator()(File &file) override;
};

class FileSizePredicate : public FileSelectionPredicate{
	long double maxSize, minSize;
	bool range;
public:
	FileSizePredicate(long double mins, long double maxs) :maxSize(maxs), minSize(mins) { range = 1; }
	FileSizePredicate(long double size) { minSize = size; maxSize = 0; range = 0; }
	bool operator()(File &file) override;
};

class FileTimestampPredicate : public FileSelectionPredicate{
	time_t startTime, stopTime;
	bool range;
public:
	FileTimestampPredicate(string startt, string stopt);
	FileTimestampPredicate(string time);
	bool operator()(File &file) override;
};

class CompositePredicate : public FileSelectionPredicate{
protected:
	vector<FileSelectionPredicate *> predicates;
public:
	CompositePredicate& add(FileSelectionPredicate* fsp){
		predicates.push_back(fsp);
		return *this;
	}
~CompositePredicate() {
	for (FileSelectionPredicate * iterate : predicates)
		delete iterate;
	}
};