#include "ComplexCommandBuilder.h"

ComplexCommandBuilder* ComplexCommandBuilder::instance = nullptr;

ComplexCommandBuilder* ComplexCommandBuilder::makeObject(){
	if (instance == nullptr){
		static ComplexCommandBuilder something;
		instance = &something;
	}
	return instance;
}

void ComplexCommandBuilder::operator()(const vector<string> &elem, User* user){
	if (elem.size() != 2) {
		cout << "Wrong syntax!" << endl;
		help();
		return;
	}
	else if (elem[1] == "help"){
		help();
		return;
	}
	string line, name = elem[1];
	getline(cin, line);
	vector<string> parsedLine = split(line, ' ');
	vector<string> commands;
	while (parsedLine[0] != "end"){
		if (parsedLine[0] == "add" && parsedLine.size() == 2){
			if (user->count(parsedLine[1])) commands.push_back(parsedLine[1]);
			else throw Einput();
		}
		else throw Einput();
		getline(cin, line);
		parsedLine = split(line, ' ');
	}
	ComplexCommand* cc = new ComplexCommand(commands, user);
	ComplexCommandContainer* tempccc = (ComplexCommandContainer*)(user->find("cc")->second);
	tempccc->newCommands.insert(make_pair(name, cc));
}


void ComplexCommandBuilder::help(){
	cout << "Make complex command using simple and old complex commands.\nSyntax is: new [NAME]" << endl
		<< "(add [COMMAND])+" << endl
		<< "end" << endl;
}