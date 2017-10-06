#pragma once
#include "user.h"

class Help{
	User *user;
	static Help* instance;
	Help(User *u) :user(u) {}
	Help(Help const&) = delete;
	void operator=(Help const&) = delete;
public:
	static Help* makeObject(User *u);
	void manual();
};

