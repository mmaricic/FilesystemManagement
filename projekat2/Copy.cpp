#include "Copy.h"

#include "user.h"
#include "Alias.h"


Copy::Copy() {
	SetFunc.insert(make_pair("a", new SetCopyAlias(flag)));
	SetFunc.insert(make_pair("p", new SetCopyPath(flag)));
	RunningFunc.insert(make_pair("S", new CopySkip(flag)));
	RunningFunc.insert(make_pair("A", new CopySkip(flag)));
	RunningFunc.insert(make_pair("O", new CopyOverwrite(flag)));
	RunningFunc.insert(make_pair("Y", new CopyOverwrite(flag)));
	RunningFunc.insert(make_pair("R", new CopyRename(flag)));
	RunningFunc.insert(make_pair("B", new CopyAbort(flag)));
	RunningFunc.insert(make_pair("C", new BasicCopy(flag)));

}

void Copy::operator()(const vector<string> &elem) {
	if (!checkArg(elem)) return;
	string choiceflag = "C";
	string in;
	bool rem = 0;
	string out, source = elem[0];
	if (source.find('*') != std::string::npos){
		vector<string> temp;
		rem = ptrSel->makeTempSel(elem[0], temp, source);
	}
	string temp = RunClass::getType(elem[1]);
	if (temp != "s")
		out = SetFunc.find(temp)->second->set(elem[1]);
	else throw ECopyInSel();
	if (!is_directory(out) && !flag){
		cout << "Can't copy into something that isn't directory!" << endl;
		return;
	}
	temp = RunClass::getType(source);
	if (temp != "s"){
		in = SetFunc.find(temp)->second->set(source);
		setAll(in, out, choiceflag);
	}
	else {
		vector<File *> p = ptrSel->find(source)->second;
		if (flag) {
			for (int i = 0; i < p.size(); i++){
				File f(p[i]->getPath());
				if (f.isParent(out)) throw EIsParent();
			}
		}
		for (int i = 0; i < p.size(); i++){
			if (exists(in = p[i]->getPath()))
				setAll(in, out, choiceflag);
		}
	}
	if (!flag) cout << "Copied" << endl;
	if (rem)
		ptrSel->removeTempSel();
}


void Copy::setAll(string in, string out, string &choiceflag) {
	if (out == "")
		throw EInvalidArg();
	if (in == out) return;
	queue<two> q;
	queue<two> fin;
	string help;
	size_t size = 0, copySize = 0;
	path p;
	if (flag) {
		File f(in);
		f.isParent(out);
	}
	p = in;
	help = out + "\\" + p.filename().string();
	q.push(two(in, help));
	fin.push(two(in, help));
	while (!q.empty()){
		in = q.front().first;
		out = q.front().second;
		q.pop();
		if (is_directory(in)){
			for (auto i = directory_iterator(in); i != directory_iterator(); i++){
				help = out + "\\" + i->path().filename().string();
				q.push(two(i->path().string(), help));
				fin.push(two(i->path().string(), help));
			}
		}
		else size += static_cast<size_t>(file_size(in));
	}
	StartCopy(fin, copySize, size, choiceflag);
}

void Copy::StartCopy(queue<two> fin, size_t &copySize, size_t &size, string &choiceflag){
	string in, out;
	while (!fin.empty()){
		string choice;
		bool check = 1;
		in = fin.front().first;
		out = fin.front().second;
		fin.pop();
		if (checkIfExists(out) && choiceflag != "A" && choiceflag != "Y") {
			path p(out);
			cout << "There already exists a file with the same name(" << p.stem().string() << "). Choose option: \n"
				<< "S: skip\n"
				<< "A: skip all\n"
				<< "O: overwrite\n"
				<< "Y: overwrite all\n"
				<< "R: rename(keep both files)\n"
				<< "B: abort\nChoice: ";
			getline(cin, choice);
			choiceflag = choice;
			if (RunningFunc.find(choice) == RunningFunc.end()) throw Einput();
			check = RunningFunc.find(choice)->second->run(in, out, copySize, size);
		}
		else if (!checkIfExists(out) && choiceflag != "A") check = RunningFunc.find("C")->second->run(in, out, copySize, size);
		if (!check) return;
	}
}

void Copy::help() {
	cout << "Copy files/folders.\nSyntax of command COPY is: copy [SOURCE] [DESTINATION]" << endl;
}

Copy::~Copy() {
	for (auto itr = SetFunc.begin(); itr != SetFunc.end(); itr++)
		delete itr->second;
	for (auto itr = RunningFunc.begin(); itr != RunningFunc.end(); itr++)
		delete itr->second;
}