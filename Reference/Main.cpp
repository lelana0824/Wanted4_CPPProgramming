#include <iostream>

// call by value;
//void Increment(int value)
//{
//	value++;
//}

void Increment(int& value) {
	value++;
}

int main()
{
	int number = 10;
	Increment(number);

	std::cin.get();
}