#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;



/*

increse order Twoway LinkedList

functin list :
insert
delete (insert)
showall
DeleteAll



*/
typedef struct {
	int data;
	Node* prev;
	Node* next;
} Node;


Node* head;
Node* tail;

void insert(int data)
{
	Node* node = new Node;
	node->data = data;
	Node* cur;
	cur = head->next;


	while (data < cur->data && cur != tail)
	{
		cur = cur->next;
	}
}

int main()
{

	return 0;
}