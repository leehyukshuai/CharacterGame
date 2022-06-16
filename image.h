#ifndef _IMAGE_H_
#define _IMAGE_H_


#include "map.h"
#include <string>


class Image : public Map
{
public:
    Image(std::string filename);
};

#endif