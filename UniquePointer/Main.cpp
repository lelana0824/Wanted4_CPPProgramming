#include <iostream>
#include <memory>


class Player
{
};

void Function(std::unique_ptr<Player> player)
{
    std::cout << "Player ¹ÞÀ½\n";
}

int main()
{
    std::unique_ptr<Player> player = 
        std::make_unique<Player>();

    //Function(player);
    std::unique_ptr<Player> p = std::move(player);


    std::cin.get();
}