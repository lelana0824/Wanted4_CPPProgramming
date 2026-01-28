#include <iostream>



int main()
{

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