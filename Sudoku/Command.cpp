#include "Command.h"

Command::Command()
{
	type = "base";
}

Fill::Fill()
{
	type = "fill";
}

Delete::Delete()
{
	type = "delete";
}

string Command::getType()
{
	return type;
}

void Command::setBoard(Board* board)
{
	this->board = board;
}

void Fill::execute(int x, int y, int value)
{
	query[0] = x;
	query[1] = y;
	query[2] = value;
	board->fillCell(query[0], query[1], query[2]);
}

void Fill::undo()
{
	board->deleteCell(query[0], query[1]);
}

void Delete::execute(int x, int y)
{
	query[0] = x;
	query[1] = y;
	query[2] = board->getCellValue(x, y);
	board->deleteCell(query[0], query[1]);
}

void Delete::undo()
{
	board->fillCell(query[0], query[1], query[2]);
}

int Command::getQuery(int i)
{
	return query[i];
}

void Delete::redo()
{
	board->deleteCell(query[0], query[1]);
}

void Fill::redo()
{
	board->fillCell(query[0], query[1], query[2]);
}

SaveLoad::SaveLoad()
{
	namespace fs = filesystem;
	for (const auto& entry : fs::directory_iterator(path))
		file.push_back(entry.path().string());
}

void SaveLoad::Save(Board* board, string name)
{
	string destination = path + name + ".txt";
	ofstream out(destination);
	for (int i = 0; i < GRID_SIZE; i++)
	{
		for (int j = 0; j < GRID_SIZE; j++)
		{
			out << board->getCellValue(i, j) << " ";
		}
		out << endl;
	}
	cout << endl << "Save Successfully!" << endl;
	cout << destination;
	out.close();
}

void SaveLoad::Load(Board* board, string name)
{
	string loadFile = path + name + ".txt";
	ifstream inputFile(loadFile);
	Board tempBoard;

	if (!inputFile.is_open())
		cout << "Error opening loadfile!";

	int temp[GRID_SIZE][GRID_SIZE];

	for (int i = 0; i < GRID_SIZE; i++)
	{
		for (int j = 0; j < GRID_SIZE; j++)
		{
			inputFile >> temp[i][j];
			board->setCell(i, j, temp[i][j]);
			tempBoard.setCell(i, j, temp[i][j]);
		}
	}

	tempBoard.solve();
	for (int i = 0; i < GRID_SIZE; i++)
	{
		for (int j = 0; j < GRID_SIZE; j++)
		{
			board->setSolCell(i, j, tempBoard.getCellValue(i, j));
		}
	}
}

void SaveLoad::showSaveList()
{
	for (string i : file)
	{
		cout << endl << file.back() << endl;
		file.pop_back();
	}
}