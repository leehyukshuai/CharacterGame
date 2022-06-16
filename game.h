#ifndef _GAME_H_
#define _GAME_H_
#include "screen.h"
#include "image.h"
#include "actor.h"

class Game
{
private:
    int key;
    const int FPS = 60;
    Screen &screen;

public:
    Game(Screen &_screen);
    void Prep();
    void Init();
    void Handle();
    void Update();
    void Show();
    void Run();
};

#endif