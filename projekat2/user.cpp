#include "user.h"
 
vector<string> split(string s, char delim){
	vector<string> elems;
	stringstream ss(s);
	string word;
	while (getline(ss, word, ' '))
		elems.push_back(word);
	return elems;
}

User::~User() {}