#include <iostream>


template<typename T>
void Swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

//void Swap(float& a, float& b)
//{
//    float temp = a;
//    a = b;
//    b = temp;
//}

int main()
{
    int a = 10;
    int b = 20;
    Swap(a, b);

    Swap("a", "b");

    std::cin.get();

}