#include <iostream>
#include "Player.h"

int main() {
    Player player1;
    Player* player2 = new Player("Test");

    player1.Move(2, 3);
    delete player2;
    player2 = nullptr;

    std::cin.get();
}