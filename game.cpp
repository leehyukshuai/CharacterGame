#include "game.h"
#include <ctime>
#include <conio.h>
#include <windows.h>

Game::Game(Screen &_screen) : screen(_screen), key('\0') {}

void Game::Show()
{
    screen.render();
    screen.show();
}

void Game::Prep()
{
    system("chcp 65001");
    system("cls");
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = false;
    SetConsoleCursorInfo(handle, &CursorInfo);
    Init();
}

void Game::Run()
{
    static clock_t t0 = clock(), t1;
    Prep();
    while (1)
    {
        t1 = clock();
        if (_kbhit())
            key = getch();
        if (t1 - t0 > CLOCKS_PER_SEC * 1.0 / FPS)
        {
            t0 = t1;
            Handle();
            Update();
            Show();
        }
    }
}