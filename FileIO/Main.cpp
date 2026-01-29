#include <iostream>
#include "Player.h"
#include <vector>


int main()
{
    std::vector<int> array;
    array.push_back(10);
    array.emplace_back(10);

    // 객체를 파일에 쓰기 (파일 직렬화)
    //Player player(3, 200, 30.0f);

    Player player;
    player.Deserialize("PlayerData.txt");

    // 문자열 입출력
    int score = 100;
    float pi = 3.14f;

    char formatString[256] = {};
    sprintf_s(formatString, 256, "score=%d pi=%f",
        score, pi);

    int intValue = 0;
    float floatValue = 0.0;
    sscanf_s(formatString, "score=%d pi=%f",
        &intValue, &floatValue);

    FILE* file = nullptr;
    fopen_s(&file, "Test.txt", "rt");

    if (file == nullptr)
    {
        std::cout << "Failed to read file.\n";
        __debugbreak();
    }

    // 파일 크기 가늠
    fseek(file, 0, SEEK_END);
    size_t fileSize = ftell(file);

    // ! 파일 크기 기늠한 뒤 다시 처음부터 읽으려면 FP 되돌려야 함
    fseek(file, 0, SEEK_SET);
    rewind(file);

    std::cout << "FileSize: " << fileSize << "\n";
    // 파일 쓰기
 /*   const char* message = "뭐라고 하지 고승민\n";
    fread(message, file);*/

    char buffer[1024] = {};
    size_t readSize = fread(buffer, sizeof(char), 1024, file);
    

    std::cout << readSize << "\n";
    std::cout << buffer;
    //char data[256] = {};
    //while (true)
    //{
    //    if (fgets(data, 256, file) == nullptr)
    //    {
    //        break;
    //    }

    //    std::cout << data;
    //}


    fclose(file);

    std::cin.get();
}