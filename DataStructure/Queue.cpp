#define CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <iostream>
using namespace std;
#define SIZE 10000
#define INF 999999


int queue[SIZE];
int front = 0;
int rear = 0;

void Push(int data)
{
	if (rear >= SIZE)
	{
		cout << "오버플로우 발생" << endl;
		return;
	}
	queue[rear++] = data;
	return;
}

int Pop()
{
	if (front == rear)
	{
		cout << "언더플로우 발생" << endl;
		return 0;
	}

	return queue[front++];
}

void ShowAll()
{
	int i = 0;
	while (i != rear)
	{
		cout << queue[i] << " ";
		i++;
	}
	cout << endl;
	return;
}

int main()
{
	Push(3);
	Push(4);
	Push(5);
	ShowAll();
	return 0;
}