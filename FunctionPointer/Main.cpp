#include <iostream>
typedef int (*Adder)(int a, int b);

int Function(int a, int b, Adder adder)
{
    return adder(a,b);
}

int Add(int a, int b)
{
    return a + b;
}

class Operator
{
public:
    int Add(int a, int b)
    {
        return a + b;
    }
};

int main()
{

    std::cout << Function(10, 20, Add) << "\n";


    std::cin.get();
}