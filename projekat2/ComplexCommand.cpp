#include "ComplexCommand.h"

void ComplexCommand::run(vector<string> arg){
	int numarg;
	int curr = 0;
	vector<string> cmndArgs;
	for (int j = 0; j < commands.size(); j++){
		numarg = user->find(commands[j])->second->argNum();
		for (int k = curr; k < curr + numarg; k++)
			cmndArgs.push_back(arg[k]);
		curr += numarg;
		(*(user->find(commands[j])->second))(cmndArgs);
		cmndArgs.clear();
	}
}

int ComplexCommand::argNum(){
	int count =0;
	for (int j = 0; j < commands.size(); j++){
		count += user->find(commands[j])->second->argNum();
	}
	return count;
}