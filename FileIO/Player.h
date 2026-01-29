#pragma once

class Player
{
public:
    Player();
    Player(int id, int score, float attack);
    ~Player();

    void Serialize(const char* path);
    void Deserialize(const char* path);
private:
    int score = 0;
    int id = 0;
    float attack = 0.0f;
};
