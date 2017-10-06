#include "user.h"
#include "Compare.h"
#include "ComplexCommandContainer.h"

Admin* Admin::instance = nullptr;

Admin::Admin(Alias *a, Selection* s) : User(a, s) {
	this->insert(make_pair("assign", new Assign()));
	this->insert(make_pair("cd", new Cd()));
	this->insert(make_pair("copy", new Copy()));
	this->insert(make_pair("delete", new Delete()));
	this->insert(make_pair("exit", new Exit()));
	this->insert(make_pair("list", new List()));
	this->insert(make_pair("mkdir", new Mkdir()));
	this->insert(make_pair("path", new Path()));
	this->insert(make_pair("remove", new Remove()));
	this->insert(make_pair("rename", new Rename()));
	this->insert(make_pair("select", new Select()));
	this->insert(make_pair("move", new Move()));
	this->insert(make_pair("setts", new Setts()));
	this->insert(make_pair("compare", new Compare()));
	this->insert(make_pair("cc", new ComplexCommandContainer()));
	this->insert(make_pair("info", new Info()));
}

Admin* Admin::makeObject(Alias *a, Selection* s){
	if (instance == nullptr){
		instance = new Admin(a, s);
		return instance;
	}
	else return nullptr;
}

void Admin::loadConf(Alias *a, Selection* s) {
	std::ifstream file;
	string str;
	vector<string> v;
	if (exists("configuration.txt")){
		file.open(("configuration.txt"));
		getline(file, str);
		while (str != "$end$") {
			v = split(str, ' ');
			a->insert(make_pair(v[0], new File(v[1])));
			getline(file, str);
		}
		getline(file, str);
		while (str != "$end$") {
			v = split(str, ' ');
			string name = v[1];
			vector<File*> f;
			getline(file, str);
			v = split(str, ' ');
			while (v[0] != "***" && str != "$end$"){
				f.push_back(new File(str));
				getline(file, str);
				v = split(str, ' ');
			}
			s->insert(make_pair(name, f));
		}
		file.close();
	}
	else cout << "There is no configuration file" << endl;
}
