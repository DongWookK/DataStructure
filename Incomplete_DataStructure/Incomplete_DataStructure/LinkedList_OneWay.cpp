#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


// Incomplete Code     *****************************


/*

addFront
FreeAll
deleteFront;
ShowAll;


*/
typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* head;

void AddFront(Node* root, int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = root->next;
	root->next = temp;

}

void DeleteFront()
{

}

void ShowAll()
{
	Node* temp = head->next;
	while (temp != NULL)
	{
		cout << temp->data;
		temp = temp->next;
	}
	cout << endl;

}



int main(void) {

	head = new Node;
	head->next = NULL;
	int input = 1;
	int data;

	while (input != 5)
	{
		cout << "OneWay LinkedList :)" << endl;
		cout << "Enter the under choice" << endl;
		cout << "1. Add Front, 2.DeleteFront, 3.ShowAll, 4.FreeAll, 5.Exit" << endl;
		cin >> input;

		switch (input)
		{
		case 1:
			cout << "Enter the input(Data)" << endl;
			cin >> data;
			break;
		case 2:
			break;
		case 3:
			ShowAll();
			break;
		default:
			break;
		}
	}
	return 0;
}
