#ifndef _SCREEN_H_
#define _SCREEN_H_

#include "image.h"
#include "map.h"
#include "actor.h"
#include <list>
#include <string>

class Screen : public Map
{
private:
    std::list<Actor *> actors;
    std::string caption;

public:
    Screen(int h, int w);
    void setCaption(std::string str);
    void paste(Actor * actor);
    void erase(Actor * actor);
    void render();
    void show();
};

#endif