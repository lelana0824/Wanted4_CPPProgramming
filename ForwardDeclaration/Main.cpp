#include <iostream>
#include "Entity/Entity.h"

class Calculator
{
public:
    void ShowOperationCount()
    {
        std::cout << "µ¡¼À: " << addCount << "»¬¼À: " << subCount << "°ö¼À: " << mulCount << "³ª´°¼À: " << divideCount;
    }
    int Add(int a, int b)
    {
        addCount++;
        return a + b;
    }
    float Divide(float a, float b)
    {
        divideCount++;
        return a / b;
    }
    int Substract(int a, int b)
    {
        subCount++;
        return a - b;
    }
    int Multiply(int a, int b)
    {
        mulCount++;
        return a * b;
    }

private:
    int addCount = 0;
    int divideCount = 0;
    int subCount = 0;
    int mulCount = 0;
};

class Printer
{
public:
    Printer() = default;
    ~Printer()
    {
        if (text) {
            delete[] text;
            text = nullptr;
        }
    }
    void ShowString()
    {
        if (!text) {
            std::cout << "Can`t show the string value" << "\n";
            return;
        }
        std::cout << text << "\n";
    }
    void SetString(const char* t)
    {
        size_t s = strlen(t) + 1;
        text = new char[s];
        strcpy_s(text, s, t);
    }


private:
    char* text = nullptr;
};

class Rectangle
{
public:
    Rectangle(int a, int b): width(a), height(b)
    {

    }
    int GetArea()
    {
        return width * height;
    }
    int GetGirth()
    {
        return width * 2 + height * 2;
    }

private:
    int width, height;
};

class Circle
{
public:
    Circle(int h_radius): r(h_radius) {

    }
    float GetArea()
    {
        return  3.14 * r * r;
    }
    float GetGirth()
    {
        return 2 * 3.14 * r;
    }

private:
    int r = 0;
};

class NameCard
{
public:
    NameCard(char* inName, char* inNumber,
         char* inEmail, char* inJob)
    {
        size_t nameLen = strlen(inName) + 1;
        size_t numberLen = strlen(inNumber) + 1;
        size_t emailLen = strlen(inEmail) + 1;
        size_t jobLen = strlen(inJob) + 1;

        name = new char[nameLen];
        number = new char[numberLen];
        email = new char[emailLen];
        job = new char[jobLen];

        strcpy_s(name, nameLen, inName);
        strcpy_s(number, numberLen, inNumber);
        strcpy_s(email, emailLen, inEmail);
        strcpy_s(job, jobLen, inJob);
    }
    ~NameCard()
    {
        delete[] name;
        delete[] number;
        delete[] email;
        delete[] job;

        name = nullptr;
        number = nullptr;
        email = nullptr;
        job = nullptr;
    }

    void ShowData()
    {
        std::cout << "ÀÌ   ¸§: " << name << "\n";
        std::cout << "ÀüÈ­¹øÈ£: " << number << "\n";
        std::cout << "ÀÌ ¸Þ ÀÏ: " << email << "\n";
        std::cout << "Á÷   ¾÷: " << job << "\n";
    }

private:
    char* name = nullptr;
    char* number = nullptr;
    char* email = nullptr;
    char* job = nullptr;

};
int main() {
 

    std::cin.get();
}