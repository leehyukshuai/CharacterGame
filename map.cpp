#include <fstream>
#include "map.h"

Map::Map(int h, int w) : height(h), width(w)
{
    malloc();
}

Map::Map(std::string filename)
{
    std::ifstream in(filename);
    in >> height >> width;
    in.get();
    malloc();
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (in.peek() == '\n')
                break;
            p[i][j] = in.get();
            if (p[i][j] == ' ')
                p[i][j] = '\0';
        }
        if (in.peek() == '\n')
            in.get();
    }
    in.close();
}

Map::~Map()
{
    free();
}

void Map::malloc()
{
    p = new char *[height];
    for (int i = 0; i < height; ++i)
        p[i] = new char[width]();
}

void Map::free()
{
    for (int i = 0; i < height; ++i)
        delete[] p[i];
    delete[] p;
}

void Map::set(char c)
{
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width; ++j)
            p[i][j] = c;
}

int Map::Height() const
{
    return height;
}

int Map::Width() const
{
    return width;
}

void Map::paste(const Map &map, int y, int x)
{
    for (int i = 0; i < map.Height(); ++i)
        for (int j = 0; j < map.Width(); ++j)
            if (0 <= y + i && y + i < height && 0 <= x + j && x + j < width && map.p[i][j] != '\0')
                p[y + i][x + j] = map.p[i][j];
}