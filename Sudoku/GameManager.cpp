#include "GameManager.h"

GameManager::GameManager(Board* board, Player* player)
{
	this->board = board;
	this->player = player;
}

bool GameManager::checkWin()
{
	return board->isSolRight();
}

void GameManager::setPlayerUsername()
{
	string username;
	cout << endl
		 << "Insert username : "; cin >> username;
	player->setUsername(username);
}

void GameManager::play()
{
	board->generate();
	
	int op = 0;
	int x, y, z;
	while (op != 99)
	{
		board->draw();
		cout << endl
			<< "[1] Fill" << endl
			<< "[2] Delete " << endl
			<< "[3] Undo " << endl
			<< "[4] Redo " << endl
			<< "[99] Exit" << endl
			<< "[] : "; cin >> op;
		switch (op)
		{
		case 1:
			cout << "X     :"; cin >> x;
			cout << "Y     :"; cin >> y;
			cout << "Value :"; cin >> z;
			fillCell(x, y, z);
			break;
		case 2:
			cout << "X     :"; cin >> x;
			cout << "Y     :"; cin >> y;
			deleteCell(x, y);
			break;
		case 3:
			undoAct();
			break;
		case 4:
			redoAct();
			break;
		}
	}
}

void GameManager::undoAct()
{
	Command* a; 
	a = &undo.pop();
	cout << a->getType();
	redo.push(a);
	a->undo();

	cout << "Undo action on cell ["
		<< a->getQuery(0) << "]["
		<< a->getQuery(1) << "]" << endl;
}

void GameManager::redoAct()
{
	Command* a;
	a = &redo.pop();
	undo.push(a);
	a->redo();
	cout << "Redo action on cell ["
		<< a->getQuery(0) << "]["
		<< a->getQuery(1) << "]" << endl;
}

void GameManager::fillCell(int x, int y, int value)
{
	Fill *a = new Fill;
	a->setBoard(board);
	if (board->getCellValue(x,y) != 0)
	{
		cout << endl << "Cell already has value!" << endl;
	}
	else
	{
		a->execute(x, y, value);
	}
	undo.push(a);
}

void GameManager::deleteCell(int x, int y)
{
	Delete* a = new Delete;
	a->setBoard(board);
	undo.push(a);
	a->execute(x, y);
}