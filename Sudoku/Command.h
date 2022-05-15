#include "Helper.h"
#include "Board.h"

class Command
{
protected:
	int query[3]{};
	Board* board{};
	string type = "";
public:
	Command();
	~Command() = default;
	virtual void undo() {}
	virtual void redo() {}
	virtual void execute() {}
	void setBoard(Board* board);
	int getQuery(int index);
	string getType();
};

class Fill : public Command
{
public:
	Fill();
	~Fill();
	virtual void undo();
	virtual void redo();
	virtual void execute(int x, int y, int value);
};

class Delete : public Command
{
public:
	Delete();
	~Delete();
	virtual void undo();
	virtual void redo();
	virtual void execute(int x, int y);
};

class SaveLoad
{
private:
	string const path = "saveload/";
	vector <string> file;
public:
	SaveLoad();
	void Save(Board* board, string name);
	void Load(Board* board, string name);
	void showSaveList();
};