#define CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <iostream>
using namespace std;

void Swap(int* A, int* B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
	return;
}

void main()
{
	int i, j;
	int temp[9] = { 1,5,6,3,9,7,8,9,0 };

	//Ascending order
	
	/*
	for (i = 0 ; i<9 ; i++)
	{
		j = i;
		while (j > 0 && temp[j] < temp[j-1])
		{
			Swap(&temp[j], &temp[j - 1]);
			j--;
		}

	}
	*/
	
	

	//descending order
	
	for (i=0;i<8;i++)
	{
		j = i;
		while (j >0 && temp[j] > temp[j-1])
		{
			Swap(&temp[j], &temp[j - 1]);
			j--; 
		}
	}
	
	

	for (i = 0; i < 9; i++)
	{
		cout << temp[i] << " ";
	}

	return;
}