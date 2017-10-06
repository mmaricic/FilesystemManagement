#include "Select.h"
#include "FileSelectionPredicateBuilder.h"


void Select::operator()(const vector<string> &elem) {
	if (!checkArg(elem)) return;
	string temp = elem[1];
	vector<File *> helpVector;
	FileSelectionPredicateBuilder* fspb = FileSelectionPredicateBuilder::makeObject();
	FileSelectionPredicate *fsp = fspb->build(temp);
	for (auto i = directory_iterator(current_path()); i != directory_iterator(); i++){
		File *file = new File(i->path().string());
		if ((*fsp)(*file)) helpVector.push_back(file);
	}
	if (!helpVector.empty()){
		ptrSel->insert(make_pair(elem[0], helpVector));
		cout << "Selection made." << endl;
		return;
	}
	cout << "Selection is not made." << endl;
}

void Select::help() {
	cout << "Make selection.\nSyntax  of command SELECT is: select SELECT_OPT = [LOGICAL_OP]([SIMPLE_OP] || [SELECT_OPT])" << endl
		<< "[SIMPLE_OP] = [name=[JOKER]||[NAME]] || [size=[SIZE]||[SIZE_RANGE]] || [time=[TIME]||[TIME_RANGE]]" << endl
		<< "[LOGICAL_OP] = AND || OR || NOT" << endl;
}