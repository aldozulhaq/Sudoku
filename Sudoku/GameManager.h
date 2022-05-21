#pragma once
#include "Helper.h"
#include "Invoker.h"
#include "Player.h"
#include "Command.h"
#include "SaveLoad.h"

class GameManager
{
private:
	Board* board;
	Player* player;
	Invoker undo;
	Invoker redo;
public:
	GameManager(Board* board, Player* player);
	void checkWrongCell();
	void undoAct();
	void setPlayerUsername();
	void redoAct();
	void fillCell(int x, int y, int value);
	void deleteCell(int x, int y);
	void play();
	void continueGame();
	void saveFile();
	void loadFile();
};