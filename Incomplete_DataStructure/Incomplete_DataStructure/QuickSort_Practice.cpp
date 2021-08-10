#define PRAGMA_SUCURE_NO_WARNING
#include <iostream>
#include <stdio.h>
using namespace std;

void Swap(int* A, int* B)
{
	int temp = *A;
	*A = *B;
	*B = temp;

	return;
}

void QuickSort(int Arr[],int start, int end)
{
	int i = start + 1;
	int j = end;
	int key = start;
	if (start >= end)
		return;
	else
	{
		while (i <= j)
		{
			while (i <= end && Arr[i] <= Arr[key]) i++;
			while (j > start && Arr[j] >= Arr[key]) j--;
			if(i>j)
				Swap(&Arr[key], &Arr[j]);
			else
				Swap(&Arr[i], &Arr[j]);
		}

		for (int k = start; k <= end; k++)
		{
			cout << Arr[k] << " ";
		}
		cout << endl;
		
		QuickSort(Arr, start, j - 1);
		QuickSort(Arr, j+1, end);

	}
}

void main() {
	int i;
	int temp[6] = { 5, 3, 6, 7, 4, 2 };
	QuickSort(temp, 0, 5);

	for (i = 0; i < 6; i++)
	{
		cout << temp[i] << " ";
	}
	

}