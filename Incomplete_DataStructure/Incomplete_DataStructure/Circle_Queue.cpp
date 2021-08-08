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


void Enqueue(Queue* queue, int data)
{
	bool FullCheck = IsFull(queue);

	if (FullCheck == false)
	{
		if (queue->front == -1) // When Queue is Empty
		{
			queue->front = 0;
		}
		queue->rear = (queue->rear+1) % SIZE;       //Initialize 'rear' by Modular
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
		if (queue->front == queue->rear)   //After dequeue, Queue Is Empty. Initialize Queue
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