#include <iostream>


// 매크로 지양. 왜? 중첩해서 쓸때 넘어짐
/**
* 

최적화 - 용량측면, 속도측면 
인라인 함수 -> 속도 때문에 씀. (용량 포기. 속도 좋아!)
지금은 용량 버리고 속도 챙기면 장땡임.

델리게이트 - 멤버함수호출 일반적이고 안전한 방식으로 호출?
임의 오브젝트의 멤버함수에 동적으로 바인딩, 호출가능
가급적 델리게이트는 참조 전달.


*/


//#define Square(x) ( (x) * (x) )
#define FORCEINLINE __forceinline

FORCEINLINE int Square(int x) {
	return x * x;
}

int main() {
	int number = Square(10);
}