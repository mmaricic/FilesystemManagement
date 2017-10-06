#pragma once
#include "File.h"

class FileSelectionPredicate{
public:
	virtual bool operator()(File &file) = 0;
};