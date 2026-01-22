#include <iostream>
#include <WIndows.h>

#define MYTEXT(value) L##value

class Player
{

public:
	Player(const char* inName) {
		//name = inName;

		// 1. 저장 공간 확보
		// 확보할 공간의 크기를 알아야 함.
		// 특별한 함수 strlen 쓴다.
		size_t length = strlen(inName) + 1;
		name = new char[length];

		// 2. 문자열 복사
		strcpy_s(name, length, inName);

	}
	~Player()
	{
		if (name) {
			delete[] name;
		}
	}

private:
	// 문자열 저장할 변수
	char* name = nullptr;

};


int main()
{
	// 문자열
	// 문자열은 불변성을 가짐.
	const char* test = "Test";
	test = "1234";

	Player player("mw");

	//const wchar_t* wideString = L"Hello wide string";
	const wchar_t* wideString = MYTEXT("123");

	std::wcout << wideString << TEXT("\n");

	
	std::cin.get();
}