#define CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX 99999

void RadixSort(int a[], int n)
{
	int exp = 1;
	int max = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}

	while (max / exp > 0)
	{
		int bucket[10] = { 0, };
		int Result[MAX];
		
		for (i = 0; i < n; i++)bucket[a[i] / exp % 10]++;
		for (i = 1; i < 10; i++)bucket[i] += bucket[i - 1];
		for (i = n-1; i >= 0; i--)
		{
			Result[--bucket[a[i] / exp % 10]] = a[i];
		}

		for (int i = 0; i < n; i++) a[i] = Result[i];
		exp *= 10;
	}

}

int main()
{
	int i, n;

	cin >> n;
	int a[MAX];
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	RadixSort(a, n);

	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}