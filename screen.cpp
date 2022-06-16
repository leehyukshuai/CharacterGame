#include "screen.h"
#include <iostream>
#include <algorithm>
#include <windows.h>

Screen::Screen(int h, int w) : Map(h, w) {}

void Screen::setCaption(std::string str)
{
    caption = str;
}

void Screen::show()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {0, 0};
    SetConsoleCursorPosition(hOut, pos);
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
            std::cout << p[i][j];
        std::cout << std::endl;
    }
    std::cout << caption;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 20; ++j)
            std::cout << " ";
        std::cout << std::endl;
    }
}

void Screen::render()
{
    set(' ');
    for (Actor *actor : actors)
        Map::paste(actor->image, actor->y, actor->x);
}

void Screen::paste(Actor *actor)
{
    actors.push_back(actor);
}

void Screen::erase(Actor *actor)
{
    actors.erase(std::find(actors.begin(), actors.end(), actor));
}