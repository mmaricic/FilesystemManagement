#include "list.h"
#include <iomanip>

void List::operator()(const vector<string> &elem) {
	if (!checkArg(elem)) return;
	path p = current_path();
	for (auto i = directory_iterator(p); i != directory_iterator(); i++){
		cout << left << setw(35) << i->path().filename().string() << setw(6);
		if (!is_directory(i->path())){
			cout << file_size(i->path());
			time_t t = time(NULL);
			last_write_time(i->path(), t);
			tm * ptm = localtime(&t);
			char buffer[32];
			std::strftime(buffer, 32, "%d.%m.%Y %H:%M:%S", ptm);
			cout << buffer << endl;
		}
		else cout << "<DIR>" << endl;
	}
}

void List::help() {
	cout << "List content of working folder.\nSyntax  of command LIST is: list" << endl;
}