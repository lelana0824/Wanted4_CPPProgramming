#include <iostream>



class Entity
{
public:
    Entity()
    {
        std::cout << "Constructor call\n";
    }
    ~Entity() = default;

    void ShowName() const
    {
        std::cout << "Entity.\n";
    }

    Entity* GetSelf()
    {
        return this;
    }
};

int main()
{
    /*const int count = 5;
    Entity entities[count];


    for (const Entity& entity : entities)
    {
        entity.ShowName();
    }*/

    /*const int count = 5;
    Entity* entities[count] = {};

    for (int ix = 0; ix < count; ix++)
    {
        entities[ix] = new Entity();
    }

    for (Entity*& entity : entities)
    {
        delete entity;
        entity = nullptr;
    }*/

    Entity* entity = new Entity();

    std::cout << entity << "\n";
    std::cout << entity->GetSelf() << "\n";


    delete entity;
    entity = nullptr;


    std::cin.get();
}