#include <iostream>
using namespace std;

int main()
{
	//�߿����� ������� ���Ÿ���.


	
	int* p = new int(100);
	char* c = reinterpret_cast<char*> (p);
	//printf("*c = %d\n", *c);

	int* temp = reinterpret_cast<int*>(c);
	//printf("*temp = %d\n", *temp);

	// ���� ����Ʈ ���������� ���� ex) int->long
	// ǥ���Ҽ��ִ� ũ��� ���� ũ��� ��ȯ�� �κ������� ���� int->char

	//int ->longlong��?
	//�������ŭ ������ ��Ʈ�� ����. ����.

	long long* la = reinterpret_cast<long long*>(p);
	cout << la << endl;
	//����׿��� �޸𸮴ܿ� Ȯ���ϴ¹�.

	
}