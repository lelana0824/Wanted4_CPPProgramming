#include "Entity.h"
#include "../Vector.h"
#include "../Vector.h"
#include <iostream>

namespace Wanted
{

}


Entity::Entity(int x, int y)
{
    position = new Vector();
    position->x = x;
    position->y = y;
}

Entity::Entity(const Entity& other)
{

    std::cout << "copy constructor called\n";
    position = other.position;
}


Entity::~Entity()
{
    if (position)
    {
        delete position;
        position = nullptr;
    }
}