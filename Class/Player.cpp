#include "Player.h"
#include <iostream>

// 기본값 설정/ 자원할당.
// 엔진의 특수한 상황에는 자원할당은 엔진이 담당함.
Player::Player()
{

}

Player::Player(const char* inName)
{
    size_t length = strlen(inName) + 1;
    name = new char[length];

    strcpy_s(name, length, inName);
}

// 자원 해제.
Player::~Player()
{
    if (name) {
        delete[] name;
        name = nullptr;
    }
}

void Player::Move(int inX, int inY)
{
    x = inX;
    y = inY;
}