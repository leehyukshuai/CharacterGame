#ifndef _MAP_H_
#define _MAP_H_


#include <string>

class Map
{
protected:
    char **p;
    int height;
    int width;
private:
    void malloc();
    void free();
public:
    Map(int h, int w);
    Map(std::string filename);
    ~Map();
    int Height() const;
    int Width() const;
    void set(char c);
    void paste(const Map &map, int y, int x);
};

#endif