#include "CopyRunClasses.h"



bool BasicCopy::run(string in, string out, size_t &currCopy, size_t &all){
	if (is_directory(in)) {
		create_directory(out);
		return true;
	}
	size_t BUF_SIZE = 500 * 1024;
	size_t size;
	string c;
	char *buffer = new char[BUF_SIZE];
	std::ifstream inFile(in, ios::binary);
	std::ofstream outFile(out, ios::binary);
	inFile.read(buffer, BUF_SIZE);
	while (size = inFile.gcount()){
		outFile.write(buffer, size);
		inFile.read(buffer, BUF_SIZE);
		currCopy += size;
		if (!flag){
			if (currCopy >= BUF_SIZE * 50) {
				cout << "Copied " << currCopy * 100 / all << "\%. Do you want to continue? y/n" << endl;
				all -= currCopy;
				currCopy = 0;
				getline(cin, c);
				if (c == "n"){
					inFile.close();
					outFile.close();
					boost::filesystem::remove(out);
					return false;
				}
				if (c != "y" && c != "n") {
					cout << "Wrong input" << endl;
					return false;
				}
			}
		}
	}
	inFile.close();
	outFile.close();
	delete[] buffer;
	return true;
}