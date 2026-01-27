#include <iostream>

class Entity
{
public:
    Entity()
    {
        std::cout << "Entity() called\n";
    }
    ~Entity()
    {
        std::cout << "~Entity() called\n";
    }

protected:
    float x = 0.0f;
    float y = 0.0f;
};

class Player : public Entity
{
public:
    Player()
    {
        std::cout << "Player() called\n";
    }
    ~Player()
    {
        std::cout << "~Player() called\n";
    }

private:
    char* name = nullptr;

};


int main()
{
    Player player;

    std::cin.get();
}