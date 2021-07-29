#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;



/*

Push
Pop
ShowALL


*/

struct Node {
	int data;
	Node* next;
};

struct Stack {
	Node* top;
};


Node* head;

void Push(Stack* stack,int data)
{
	Node* cur = head->next;
	Node* node;
	node->data = data;

	head->next = node;
	node->next = cur;

	//Set stack top
	stack->top = node;

}

void Pop()
{

}

void ShowAll()
{
	Node* cur = head->next;
	while (cur != NULL)
	{
		cout << cur->data << " ";
		cur = cur -> next;
	}


}

int main()
{
	head->next = NULL;
	Stack* stack = new Stack;
	stack->top = NULL;

	Push(stack,3);
	Push(stack,4);
	Push(stack,6);





	return 0;
}