#include "cmnd.h"
#include "user.h"
#include "ComplexCommandBuilder.h"
#include "ComplexCommandContainer.h"
#include <fstream>
#include "Help.h"

void main(int argc, char *argv[]) {
	vector<string>v;
	string str;
	bool flag = 1;
	string mainPath = current_path().string();
	Alias *a = Alias::makeObject();
	a->insert(make_pair("_ROOT_PATH_", new File(mainPath)));
	a->insert(make_pair("#cur", new File(current_path().string())));
	a->insert(make_pair("#par", new File(current_path().remove_filename().string())));
	Selection *s = Selection::makeObject();
	ComplexCommandBuilder *ccb = ComplexCommandBuilder::makeObject();
	RunClass::setPtr(a, s);
	User* user;
	if (argc == 2){
		string password = string(argv[1]);
		if (password == "12admin34") {
			flag = 0;
			user = Admin::makeObject(a, s);
			cout << "Administrator mode on." << endl;
			cout << "Load configuration? y/n" << endl;
			getline(cin, str);
			if (str == "y") Admin::loadConf(a, s);
			else if (str != "n") cout << "Invalid input" << endl;
		}
	}
	if (flag){
		user = PublicUser::makeObject(a, s);
		cout << "Public mode on" << endl;
	}
	Help *help = Help::makeObject(user);
	while (true) {
		try{
			cout << "Insert command: ";
			getline(cin, str);
			v = split(str, ' ');
			if (v.size() == 0) continue;
			string command = v[0];
			if (v.size() == 1 && command == "help") {
				help->manual();
				continue;
			}
			if (command == "new")
			{
				(*ccb)(v, user);
				continue;
			}
			if (user->count(command)){
				v.erase(v.begin());
				(*(user->find(command)->second))(v);
			}
			else{
				ComplexCommandContainer* tempccc = (ComplexCommandContainer*)(user->find("cc")->second);
				if (tempccc->newCommands.count(command))
					tempccc->operator()(v);
			else cout << "Command doesn\'t exists. For istruction manual type: help" << endl;
			}
		}
		catch (EInvalidPath &e) { cout << e; }
		catch (EInvalidArg &e) { cout << e; }
		catch (EAliasEmpty &e) { cout << e; }
		catch (Einput &e) { cout << e; }
		catch (ECopyInSel &e) { cout << e; }
		catch (EIsChild &e) { cout << e; }
		catch (EIsParent &e) { cout << e; }
		catch (ENotSelection &e) { cout << e; }
		catch (bad_alloc &e) { cout << "Memory allocation failed!" << endl; }
		catch (...) { cout << "Unknown exception!" << endl; }
 	}


}