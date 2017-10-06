#include "Compare.h"
#include "FileSelectionPredicateBuilder.h"
#include "CompareClass.h"
#include "CompareBuilder.h"

void Compare::operator()(const vector<string> &elem){
	if (!checkArg(elem)) return;
	string temp = elem[0];
	CompareBuilder *cb = CompareBuilder::makeObject();
	string sel = elem[0];
	vector<string> selections = cb->getSelections(sel);
	CompareClass *cmpObj = cb->getCompareType(elem[0]);
	CompareClass::setPtr(ptrSel);
	vector<File *> newSel = cmpObj->run(selections);
	if (!newSel.empty()) ptrSel->insert(make_pair(elem[1], newSel));
}

void Compare::help() {
		cout << "Compare 2 selections and make a new one.\nSyntax of command COMPARE is: compare [DIFERENCE][INTERSECT](sel1,sel2) [NAME]" << endl;
}
