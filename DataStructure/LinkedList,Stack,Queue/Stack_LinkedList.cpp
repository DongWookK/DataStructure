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
	Node* node = new Node;
	node->data = data;

	head->next = node;
	node->next = cur;

	//Set stack top
	stack->top = node;

}

void Pop(Stack* stack)
{
	Node* top = stack->top;
	if (top != NULL)
	{
		head->next = top->next;
		stack->top = head->next;
		free(top);
	}
	else
	{
		cout << "there's No Top" << endl;
	}
	
}

void ShowAll(Stack* stack)
{
	Node* cur = head->next;
	while (cur != NULL)
	{
		if (cur == stack->top)
		{
			cout << "(Top)";
		}
			cout << cur->data << " ";
			cur = cur->next;
	}
	cout << endl;


}

int main()
{
	head = new Node;
	head->next = NULL;
	Stack* stack = new Stack;
	stack->top = NULL;

	Push(stack,3);
	Push(stack,4);
	Push(stack,6);
	ShowAll(stack);
	Pop(stack);
	Pop(stack);
	ShowAll(stack);





	return 0;
}