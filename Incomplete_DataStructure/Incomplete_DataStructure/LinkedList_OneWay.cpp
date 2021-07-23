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
	//Insert data in list
	Node* temp = new Node;
	temp->data = data;

	//connect with head
	temp->next = root->next;
	root->next = temp;

}

void DeleteFront()
{
	//헤드 next를 헤드next의 next로 설정.
	Node* cur = head->next;
	if (cur != NULL)
	{
		head->next = cur->next;
		free(cur);

	}


}

void ShowAll()
{
	Node* temp = head->next;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;

}

void DeleteAll()
{
	/*
	Node* cur = head->next;
	while (head->next != NULL )
	{
		Node* beNext = cur->next;
		free(cur);
		head->next = beNext;
	}
	*/
}



int main(void) {

	head = new Node;
	head->next = NULL;
	int input = 1;
	int data;

	cout << "OneWay LinkedList :)" << endl;
	while (input != 5)
	{
		cout << "Enter the under choice" << endl;
		cout << "1. Add Front, 2.DeleteFront, 3.ShowAll, 4.FreeAll, 5.Exit" << endl;
		cin >> input;

		switch (input)
		{
			//Add Front
		case 1:
			cout << "Enter the input(Data)" << endl;
			cin >> data;
			AddFront(head,data);
			break;
			//Delete Front
		case 2:
			DeleteFront();
			break;
			//Showall
		case 3:
			ShowAll();
			break;
			//FreeAll
		case 4:
			DeleteAll();
			break;
		default:
			break;
		}
	}
	return 0;
}
