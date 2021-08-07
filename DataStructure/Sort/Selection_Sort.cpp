#define CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX 999999;


void Swap(int* A, int* B)
{
	int temp;

	temp = *A;
	*A = *B;
	*B = temp;
	return;
}

void main()
{
	int i, j,min,index;
	int temp[9] = { 1,5,6,3,6,7,8,9,0 };
	for (i = 0; i < 9; i++)
	{
		min = MAX;
		for (j = i; j < 9; j++)
		{
			if (temp[j] < min)
			{
				min = temp[j];
				index = j;
			}
		}
		Swap(&temp[i], &temp[index]);
	}

	for (i = 0; i < 9; i++)
	{
		cout << temp[i] << " ";
	}

}
