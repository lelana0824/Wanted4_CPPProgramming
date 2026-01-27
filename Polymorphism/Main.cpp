#include <iostream>

#define NAME(x) #x


class NameInterface
{
public:
    virtual const char* GetName() const = 0;
};

class Entity: public NameInterface
{
public:
     virtual const char* GetName() const override {
        return NAME(Entity);
    }

private:
};


class Player : public Entity
{
public:
    Player(const char* inName)
    {
        // 내부 name 설정
        // 크기.
        size_t length = strlen(inName) + 1;

        this->name = new char[length];
        strcpy_s(this->name, length, inName);
    }
    ~Player()
    {
        if (name)
        {
            delete[] name;
            name = nullptr;
        }
    }

     virtual const char* GetName() const override  { return name; }

private:
    char* name = nullptr;
};
int main()
{
    Entity* entities[250] = {};


    Entity* entity = new Entity();
    std::cout << entity->GetName() << "\n";
    entities[0] = entity;

    Player* player = new Player("c");
    //Entity* player = new Player("hi");
    std::cout << player->GetName() << "\n";
    entities[1] = player;

    std::cout << sizeof(Entity) << "\n";
    std::cout << sizeof(Player) << "\n";


    delete player;
    delete entity;

    entity = nullptr;

    std::cin.get();
}