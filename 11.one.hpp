#ifndef ONE_H
#define ONE_H

#include "11.two.hpp"

class One
{
    Two obj;
public:
    One(Two& ob)
    {
        obj = ob;
    }
    
};

#endif