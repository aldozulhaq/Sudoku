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