#include "game.h"
#define HEIGHT 32
#define WIDTH 20

Screen screen(HEIGHT, WIDTH);
Game game(screen);

Image image_boy("boy.img");
Actor boy(image_boy);

Image image_step("step.img");
Actor step(image_step, HEIGHT - 1, 0);

Image image_ball("ball.img");
Actor ball(image_ball, 0, 16);
float a = 20;
float v = 0;
float y = 0;

void Game::Init()
{
    screen.paste(&boy);
    screen.paste(&step);
    screen.paste(&ball);
}

void Game::Update()
{
    std::string caption;
    std::string prompt("按WSAD上下左右移动");
    if (boy.collided(ball))
        prompt = "啊~~被撞了！";
    std::string v_str("v:");
    v_str += std::to_string(v);
    std::string y_str("y:");
    y_str += std::to_string(y);

    caption = prompt + '\n' + v_str + '\n' + y_str;
    screen.setCaption(caption);

    v += a / FPS;
    y += v / FPS;
    if (y > HEIGHT - ball.h)
    {
        v = -v;
        y = HEIGHT - ball.h;
    }

    ball.y = y;
}

void Game::Handle()
{
    switch (key)
    {
    case 'a':
        boy.x -= 1;
        break;
    case 'd':
        boy.x += 1;
        break;
    case 'w':
        boy.y -= 1;
        break;
    case 's':
        boy.y += 1;
        break;
    }
    key = '\0';
}