#include "Helper.h"
#include "Invoker.h"
#include "Player.h"

class GameManager
{
private:
	Board* board;
	Player* player;
	Invoker undo;
	Invoker redo;
public:
	GameManager(Board* board, Player* player);
	bool checkWin();
	void undoAct();
	void setPlayerUsername();
	void redoAct();
	void fillCell(int x, int y, int value);
	void deleteCell(int x, int y);
	void play();
};