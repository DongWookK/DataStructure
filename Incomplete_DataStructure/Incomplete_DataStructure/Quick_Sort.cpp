#define CRT_SECURE_NO_WARNING	
#include <stdio.h>
#include <iostream>
using namespace std;

void Swap(int* A, int* B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}

void QuickSort(int Arr[],int Start, int End)
{
	if (Start >= End)
	{
		return;
	}
	while (Start < End)
	{
		if (Arr[Start + 1] < Arr[End])
		{
			Swap(&Arr[Start + 1], &Arr[End]);
		}
		Start++;
		End--;
	}

	//여기서 피벗 바꾸기 ?? 두개로 나눠서 recursive하게 실행

}

void main()
{
	int i;
	int temp[10] = { 1,5,6,3,6,7,8,9,0,9 };
	QuickSort(temp, 0, 10);

	for (i = 0; i < 10; i++)
	{
		cout << temp[i] << " ";
	}
}