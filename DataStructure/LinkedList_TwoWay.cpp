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
struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
};


Node* head;
Node* tail;

void insert(int data)
{
	Node* node = new Node;
	node->data = data;
	Node* cur = head->next;


	while (data < cur->data && cur != tail)
	{
		cur = cur->next;

	}
	Node* prev = cur->prev;
	// 노드 삽입과정 검토 필요
	prev->next = node;
	node->prev = prev;
	node->next = cur;
	cur->prev = node;

}

void removeFront()
{
	Node* cur = head->next;

	if (cur != tail)
	{
		Node* beNext = cur->next;
		head->next = beNext;
		beNext->prev = head;
		free(cur);
	}

}

void showAll()
{
	Node* cur = head->next;
	while (cur != tail)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
}

int main()
{
	// 메인에서 헤드,테일 동적할당?
	// 앞에서 전역변수로 선언되게 이미 메모리할당된거아닌가?
	head = new Node;
	tail = new Node;
	head->next = tail;
	tail->next = tail;
	tail->prev = head;
	head->prev = head;

	insert(3);
	insert(4);
	insert(7);
	insert(6);
	showAll();
	removeFront();
	showAll();


	return 0;
}