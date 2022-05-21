#pragma once
#include "Board.h"

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
