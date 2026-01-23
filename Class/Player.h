#pragma once


// 클래스.
class Player
{
public:
    Player();
    Player(const char* inName);
    ~Player();

    void Move(int inX, int inY);

private:
    int x = 0;
    int y = 0;
    int speed = 0;

    // 이름값 문자열
    char* name = nullptr;
};