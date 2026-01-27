#pragma once


class Vector;


class Entity
{
public:
    Entity() = default;
    Entity(int x, int y);
    Entity(const Entity& other);

    ~Entity();
private:
    Vector* position = nullptr;
};

