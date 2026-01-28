#include <iostream>


void PrintString(char* s)
{
    std::cout << s << "\n";
}

class A {
    virtual void Test() {}
};
class B : public A {
    
};

int main()
{
    const char* name = "test";
    
    PrintString(const_cast<char*>(name));

    int number = 10;
    float floatNumber = static_cast<float>(number);

    A* a = new A();
    B* b = dynamic_cast<B*>(a);

    const auto& info = typeid(a);


    delete a;

    std::cin.get();
}