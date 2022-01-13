#include <iostream>
using namespace std;

int main()
{
	//중요한점 상수성은 제거못함.


	
	int* p = new int(100);
	char* c = reinterpret_cast<char*> (p);
	//printf("*c = %d\n", *c);

	int* temp = reinterpret_cast<int*>(c);
	//printf("*temp = %d\n", *temp);

	// 같은 바이트 변수끼리는 가능 ex) int->long
	// 표현할수있는 크기면 작은 크기로 변환도 부분적으로 가능 int->char

	//int ->longlong은?
	//빈공간만큼 쓰레기 비트가 잡힘. 오염.

	long long* la = reinterpret_cast<long long*>(p);
	cout << la << endl;
	//디버그에서 메모리단에 확인하는법.

	
}