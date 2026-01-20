#include <iostream>


// 매크로 지양. 왜? 중첩해서 쓸때 넘어짐
/**


*/


//#define Square(x) ( (x) * (x) )
#define FORCEINLINE __forceinline

FORCEINLINE int Square(int x) {
	return x * x;
}

int main() {
	int number = Square(10);
}