#include "Invoker.h"

Invoker::Invoker()
{
	history.clear();
}

void Invoker::push(Command* command)
{
	history.push_back(command);
}

Command& Invoker::pop()
{
	if (history.empty())
	{
		cout << endl
			<< "You've ran out of undo/redo action"
			<< endl;
	}
	else
	{
		Command* temp = move(history.back());
		Fill* a;

		//cout << temp->getQuery(0) << temp->getQuery(1) << temp->getQuery(2) << temp->getType();

		history.pop_back();

		return *temp;
	}
}

bool Invoker::isEmpty()
{
	return history.empty();
}

int Invoker::getSize()
{
	return history.size();
}