#pragma once
#include "Helper.h"
#include "Command.h"

class Invoker
{
private:
	vector<Command*> history;
public:
	Invoker();
	~Invoker() = default;
	void push(Command* command);
	Command& pop();
	bool isEmpty();
	int getSize();
};
