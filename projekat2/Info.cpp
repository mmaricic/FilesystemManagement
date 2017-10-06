#include "Info.h"
#include <iomanip>

void Info::operator()(const vector<string> &elem) {
	char drive = 'A';
	while (drive <= 'Z'){
		try {

			string stringPath = string(1,drive) + ":\\";
			path p(stringPath);
			space_info  s = space(p);
			cout  << "Name: " << drive << endl
				<< "Capacity: " << s.capacity/1000000.00 << " MB"<< endl
			<< "Free memory: " << s.available/1000000.00 << " MB" << endl << endl;
		}
		catch (...) {}
		drive++;
	}
}

void Info::help() {
	cout << "Detect logical devices and get info about them.\nSyntax of INFO is: info" << endl;
}
