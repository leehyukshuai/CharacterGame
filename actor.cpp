#include "actor.h"

Actor::Actor(const Image &_image, int _y, int _x) : image(_image), y(_y), x(_x), h(_image.Height()), w(_image.Width()) {}

void Actor::go(int _y, int _x)
{
    x = _x;
    y = _y;
}

void Actor::mv(int _y, int _x)
{
    x += _x;
    y += _y;
}

bool Actor::collided(const Actor &actor) const
{
    return (x < actor.x + actor.w && x + w > actor.x && y < actor.y + actor.h && y + h > actor.y);
}