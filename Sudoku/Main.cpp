#include <iostream>
#include "GameManager.h"

int main() {
	Board sudoku;
	Player player;
	GameManager gm(&sudoku, &player);

	int menuOpt = 0;
	while (menuOpt != 99)
	{
		cout << "---Menu---" << endl
			<< "1. Play" << endl
			<< "2. Contibue " << endl
			<< "3. Set Player Name" << endl
			<< "4. Save" << endl
			<< "5. Load" << endl
			<< "99. Exit" << endl
			<< "[] : "; cin >> menuOpt;

		switch (menuOpt)
		{
		case 1:
			gm.play();
			break;
		case 2:
			gm.continueGame();
			break;
		case 3:
			gm.setPlayerUsername();
			break;
		case 4:
			gm.saveFile();
			break;
		case 5:
			gm.loadFile();
			break;
		case 99:
			break;
		default:;
		}
	}
}