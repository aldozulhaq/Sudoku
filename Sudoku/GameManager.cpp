#include "GameManager.h"

GameManager::GameManager(Board* board, Player* player)
{
	this->board = board;
	this->player = player;
}

void GameManager::checkWrongCell()
{
	struct wrongCell
	{
		int x;
		int y;
		int value;
	};

	vector <wrongCell> Cell;

	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			if (this->board->getCellValue(i, j) != this->board->getCellSolValue(i, j)) {
				Cell.push_back({ i, j, this->board->getCellValue(i,j) });
			}
		}
	}

	cout << endl
		<< "Every cell are correct exept for these : " << endl;
	for (const auto& arr : Cell)
	{
		cout << "Cell "
			<< "[" << arr.x << "]"
			<< "[" << arr.y << "] : ";
		if (arr.value == 0)
		{
			cout << "Still Empty";
		}
		else {
			cout << arr.value;
		}
		cout << endl;
		Cell.pop_back();
	}
}

void GameManager::saveFile()
{
	SaveLoad save;
	string filename;
	save.showSaveList();
	cout << endl << "Save as : "; cin >> filename;
	save.Save(board, filename);
}

void GameManager::loadFile()
{
	SaveLoad load;
	string filename;
	load.showSaveList();
	cout << endl << "Load from : "; cin >> filename;
	load.Load(board, filename);
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
	cout << endl << "Set Difficulty, how many cell to remove : ";
	int r = 0; cin >> r;
	this->board->difficulty(r);
	board->generate();
	continueGame();
}

void GameManager::continueGame()
{
	int op = 0;
	int x, y, z;
	while (op != 99)
	{
		if (this->board->isSolRight())
		{
			cout << endl << "Congratulations!!" << endl
				<< "you have finished the sudoku with "
				<< (undo.getSize() + redo.getSize())
				<< " action!" << endl << endl;
			break;
		}
		board->draw();
		cout << endl
			<< "[1] Fill" << endl
			<< "[2] Delete " << endl
			<< "[3] Undo " << endl
			<< "[4] Redo " << endl
			<< "[5] Check Wrong Cell" << endl
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
		case 5:
			checkWrongCell();
		default:;
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
	Fill* a = new Fill;
	a->setBoard(board);
	if (board->getCellValue(x, y) != 0)
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