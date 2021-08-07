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
	cout << "Sort" << endl;
	if (Start >= End)
	{
		return;
	}

	int key = Start;
	int i = Start+1; int j = End;int temp;
	while (i <= j)
	{
		while (i <= End && Arr[i] <= Arr[key]) i++;
		while (j > Start && Arr[j] >= Arr[key]) j--;
		if (i > j) Swap(&Arr[key], &Arr[j]);
		else Swap(&Arr[i], &Arr[j]);

		for (int k = Start; k < End; k++)
		{
			cout << Arr[k] << " ";
		}
		cout << endl;

	}

	QuickSort(Arr, Start, j-1);
	QuickSort(Arr, j+1, End);

}


void TestPrint(int Arr[], int Start, int End)
{
	int i;
	for (i = Start; i < End; i++)
	{
		cout << Arr[i] << " ";
	}
}

void main()
{
	int i;
	int Arr[6] = { 3,0,5,1,6,2 };
	QuickSort(Arr, 0, 5);

	for (i = 0; i < 6; i++)
	{
		cout << Arr[i] << " ";
	}
}