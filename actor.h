#ifndef _ACTOR_H_
#define _ACTOR_H_

#include "image.h"

class Actor
{
public:
    const Image &image;
    Actor(const Image &_image, int _y = 0, int _x = 0);
    const int h, w;
    int y, x;
    void go(int _y, int _x);
    void mv(int _y, int _x);
    bool collided(const Actor& actor) const;
};

#endif