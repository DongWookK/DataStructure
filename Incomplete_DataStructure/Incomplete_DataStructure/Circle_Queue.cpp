#include <iostream>
#define SIZE 5
#include <stdio.h>
using namespace std;


struct Queue {
	int Arr[SIZE];
	int front = -1;
	int rear = -1;
};

bool IsFull(Queue* queue)
{
	if (queue->front == 0 && queue->rear == SIZE - 1)
	{
		cout << "Queue Is full!" << endl;
		return true;
	}
	return false;

}

//처음 엔큐할경우 front도 0으로 바꿔서 Full과 구분시켜줄것.
void Enqueue(Queue* queue, int data)
{
	bool FullCheck = IsFull(queue);

	if (FullCheck == false)
	{
		if (queue->front == -1)
		{
			queue->front = 0;
		}
		queue->rear = (queue->rear+1) % SIZE;       //모듈러 연산을 통해 순환하게끔
		queue->Arr[queue->rear] = data;
		cout << "Enqueue" << endl;
	}

	return;;

	
}

bool IsEmpty(Queue* queue)
{
	if (queue->front ==-1)
	{
		cout << "Queue Is Empty!" << endl;
		return true;
	}
	else
		return false;
}

void Dequeue(Queue* queue)
{
	bool EmptyCheck = IsEmpty(queue);
	if (EmptyCheck == false)
	{
		int data = queue->Arr[queue->front];
		if (queue->front == queue->rear)   //고려해야될것. 오직 하나의 Element만 있을때!  근데 이게 꼭 초기화를 해줘야하나 ?
		{
			queue->front = -1;
			queue->rear = -1;
		}
		else
		{
			queue->front = (queue->front + 1) % SIZE;
		}
		cout << data << endl;

	}

}

void main()
{
	Queue* queue = new Queue;
	Dequeue(queue);
	Enqueue(queue, 3);
	Enqueue(queue, 4);
	Enqueue(queue, 5);
	Enqueue(queue, 5);
	Enqueue(queue, 5);
	Enqueue(queue, 5);


	Dequeue(queue);

}