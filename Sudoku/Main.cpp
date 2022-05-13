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
             << "2. Set Player Name" << endl
             << "99. Exit" << endl
             << "[] : "; cin >> menuOpt;

        switch (menuOpt)
        {
        case 1:
            gm.play();
            break;
        case 2:
            gm.setPlayerUsername();
            break;
        }
    }
    
}