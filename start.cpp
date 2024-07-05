#include <iostream>  // For cout, endl
#include <windows.h>
// #include "main.cpp" // For Sleep, SetConsoleCursorPosition, GetStdHandle

using namespace std;

COORD coord = {0, 0};

void gotoxy(int x, int y) // Function to set the cursor position
{
    coord.X = (SHORT)x;
    coord.Y = (SHORT)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int preintro()
{
    Sleep(800);
    gotoxy(29 + 15, 12);
    cout << " THIS";
    Sleep(800);
    cout << " GAME";
    Sleep(800);
    cout << " IS";
    Sleep(800);
    cout << " BROUGHT";
    Sleep(800);
    cout << " T0";
    Sleep(800);
    cout << " YOU";
    Sleep(800);
    cout << " BY";
    Sleep(2000);
    gotoxy(29 + 19, 14);
    cout << "P O W E R P U F F - GIRLS";
    Sleep(4200);
    gotoxy(29 + 26, 16);
    cout << "C";
    gotoxy(29 + 16, 16);
    cout << "C";
    gotoxy(29 + 36, 16);
    cout << "C";
    Sleep(200);
    gotoxy(29 + 27, 16);
    cout << "T";
    gotoxy(29 + 17, 16);
    cout << "T";
    gotoxy(29 + 37, 16);
    cout << "T";
    Sleep(200);
    gotoxy(29 + 28, 16);
    cout << "C";
    gotoxy(29 + 18, 16);
    cout << "C";
    gotoxy(29 + 38, 16);
    cout << "C";
    Sleep(200);
    gotoxy(29 + 29, 16);
    cout << "Y";
    gotoxy(29 + 19, 16);
    cout << "Y";
    gotoxy(29 + 39, 16);
    cout << "Y";
    Sleep(200);
    gotoxy(29 + 30, 16);
    cout << "-";
    gotoxy(29 + 20, 16);
    cout << "-";
    gotoxy(29 + 40, 16);
    cout << "-";
    Sleep(200);
    gotoxy(29 + 31, 16);
    cout << "0";
    gotoxy(29 + 21, 16);
    cout << "0";
    gotoxy(29 + 41, 16);
    cout << "0";
    Sleep(200);
    gotoxy(29 + 32, 16);
    cout << "0";
    gotoxy(29 + 22, 16);
    cout << "0";
    gotoxy(29 + 42, 16);
    cout << "0";
    Sleep(200);
    gotoxy(29 + 33, 16);
    cout << "3";
    gotoxy(29 + 23, 16);
    cout << "2";
    gotoxy(29 + 43, 16);
    cout << "7";
    gotoxy(29 + 16, 17);
    cout << "Fabiha.K";
    gotoxy(29 + 36, 17);
    cout << "Yumna.K";
    gotoxy(29 + 26, 17);
    cout << "AIMAN K.";
    Sleep(3000); // Wait for 3 seconds
    return 0;
}

int intro()
{
    bool continueAnimation = true;
    while (continueAnimation)
    {
        Sleep(150);
        gotoxy(29 + 26, 14);
        cout << "A";
        gotoxy(29 + 1, 5);
        cout << "SUDOKU ";
        gotoxy(29 + 1, 8);
        cout << "SUDOKU ";
        gotoxy(29 + 1, 11);
        cout << "SUDOKU ";
        gotoxy(29 + 1, 17);
        cout << "SUDOKU ";
        gotoxy(29 + 1, 20);
        cout << "SUDOKU ";
        gotoxy(29 + 1, 23);
        cout << "SUDOKU ";
        Sleep(150);
        gotoxy(29 + 27, 14);
        cout << "R";
        gotoxy(29 + 12, 5);
        cout << "SUDOKU ";
        gotoxy(29 + 12, 8);
        cout << "SUDOKU ";
        gotoxy(29 + 12, 11);
        cout << "SUDOKU ";
        gotoxy(29 + 12, 17);
        cout << "SUDOKU ";
        gotoxy(29 + 12, 20);
        cout << "SUDOKU ";
        gotoxy(29 + 12, 23);
        cout << "SUDOKU ";
        Sleep(150);
        gotoxy(29 + 28, 14);
        cout << "C";
        gotoxy(29 + 22, 5);
        cout << "SUDOKU ";
        gotoxy(29 + 22, 8);
        cout << "SUDOKU ";
        gotoxy(29 + 22, 11);
        cout << "SUDOKU ";
        gotoxy(29 + 22, 17);
        cout << "SUDOKU ";
        gotoxy(29 + 22, 20);
        cout << "SUDOKU ";
        gotoxy(29 + 22, 23);
        cout << "SUDOKU ";
        Sleep(150);
        gotoxy(29 + 29, 14);
        cout << "A";
        gotoxy(29 + 32, 5);
        cout << "SUDOKU ";
        gotoxy(29 + 32, 8);
        cout << "SUDOKU ";
        gotoxy(29 + 32, 11);
        cout << "SUDOKU ";
        gotoxy(29 + 32, 17);
        cout << "SUDOKU ";
        gotoxy(29 + 32, 20);
        cout << "SUDOKU ";
        gotoxy(29 + 32, 23);
        cout << "SUDOKU ";
        Sleep(150);
        gotoxy(29 + 30, 14);
        cout << "N";
        gotoxy(29 + 42, 5);
        cout << "SUDOKU ";
        gotoxy(29 + 42, 8);
        cout << "SUDOKU ";
        gotoxy(29 + 42, 11);
        cout << "SUDOKU ";
        gotoxy(29 + 42, 17);
        cout << "SUDOKU ";
        gotoxy(29 + 42, 20);
        cout << "SUDOKU ";
        gotoxy(29 + 42, 23);
        cout << "SUDOKU ";
        Sleep(150);
        gotoxy(29 + 31, 14);
        cout << "A";
        gotoxy(29 + 52, 5);
        cout << "SUDOKU ";
        gotoxy(29 + 52, 8);
        cout << "SUDOKU ";
        gotoxy(29 + 52, 11);
        cout << "SUDOKU ";
        gotoxy(29 + 52, 17);
        cout << "SUDOKU ";
        gotoxy(29 + 52, 20);
        cout << "SUDOKU ";
        gotoxy(29 + 52, 23);
        cout << "SUDOKU ";
        Sleep(150);
        gotoxy(29 + 32, 14);
        cout << " ";
        gotoxy(29 + 1, 5);
        cout << "       ";
        gotoxy(29 + 12, 5);
        cout << "       ";
        gotoxy(29 + 22, 5);
        cout << "       ";
        gotoxy(29 + 32, 5);
        cout << "       ";
        gotoxy(29 + 42, 5);
        cout << "       ";
        gotoxy(29 + 52, 5);
        cout << "       ";
        gotoxy(29 + 1, 8);
        cout << "       ";
        gotoxy(29 + 12, 8);
        cout << "       ";
        gotoxy(29 + 22, 8);
        cout << "       ";
        gotoxy(29 + 32, 8);
        cout << "       ";
        gotoxy(29 + 42, 8);
        cout << "       ";
        gotoxy(29 + 52, 8);
        cout << "       ";
        gotoxy(29 + 1, 11);
        cout << "       ";
        gotoxy(29 + 12, 11);
        cout << "       ";
        gotoxy(29 + 22, 11);
        cout << "       ";
        gotoxy(29 + 32, 11);
        cout << "       ";
        gotoxy(29 + 42, 11);
        cout << "       ";
        gotoxy(29 + 52, 11);
        cout << "       ";
        gotoxy(29 + 1, 23);
        cout << "       ";
        gotoxy(29 + 12, 23);
        cout << "       ";
        gotoxy(29 + 22, 23);
        cout << "       ";
        gotoxy(29 + 32, 23);
        cout << "       ";
        gotoxy(29 + 42, 23);
        cout << "       ";
        gotoxy(29 + 52, 23);
        cout << "       ";

        // Check if the user has pressed Enter
        if (GetAsyncKeyState(VK_RETURN))
        {
            continueAnimation = false;
            gotoxy(29, 26); // Move cursor away from animation area
        }
    }
    return 0;
}

int start()
{
    preintro();
    intro();

    // Continue with the rest of your main program logic
    // Here you would proceed to start the game after the animation loop
    cout << "Press Enter to start the game...";
    cin.ignore(); // Wait for Enter key press
    system("cls"); // Clear screen before starting the game

    // project();
    // Proceed with your game logic from here
    // For now, we'll just exit the program
    return 0;
}