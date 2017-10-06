#include "FileSelectionDerived.h"

class LogicalOp : public CompositePredicate {};

class AND : public LogicalOp{
public:
	bool operator()(File &file) override{
		for (FileSelectionPredicate *pred : predicates){
			if (!pred->operator()(file)) return false;
		}
		return true;
	}
};

class OR : public LogicalOp{
public:
	bool operator()(File &file) override{
		for (FileSelectionPredicate *pred : predicates){
			if (pred->operator()(file)) return true;
		}
		return false;
	}
};

class NOT : public LogicalOp{
public:
	bool operator()(File &file) override{
		return !(predicates[0]->operator()(file));
	}
};