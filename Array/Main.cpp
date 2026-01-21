#include <iostream>

// 배열을 함수에 전달

void PrintArray(const char* array, int length)
{
	for (int ix = 0; ix < length; ix++)
	{
		std::cout << array[ix] << "\n";
	}
}


const int TEST = 10;
int main()
{
	char t = 1;
	int array[TEST] = {};
	memset(array, 0, sizeof(int) * 10);

	array[0] = 1;
	array[3] = 10;
	array[9] = 100;

	const char* test = "Asdf";
	PrintArray(test, TEST);

	std::cin.get();
}