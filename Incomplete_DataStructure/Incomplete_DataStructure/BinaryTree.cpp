#define CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* LeftChild;
	Node* RightChild;
};

Node* InitialNode(Node* node, int data, Node* LeftChild, Node* RightChild)
{
	node->LeftChild = LeftChild;
	node->RightChild = RightChild;
	node->data = data;
	return node;
}

Node* InitialNode(Node* node, int data)
{
	node->LeftChild = NULL;
	node->RightChild = NULL;
	node->data = data;
	return node;
}

//preorder 전위순회

void PreOrder(Node* root)
{
	cout << root->data << " ";
	if (root->LeftChild != NULL)
		PreOrder(root->LeftChild);
	if (root->RightChild != NULL)
		PreOrder(root->RightChild);

}

//inorder 중위순회

void InOrder(Node* root)
{
	if (root->LeftChild != NULL)
		InOrder(root->LeftChild);
	cout << root->data << " ";
	if (root->RightChild != NULL)
		InOrder(root->RightChild);
}

//postorder 후위순회

void PostOrder(Node* root)
{
	if (root->LeftChild != NULL)
		PostOrder(root->LeftChild);
	if (root->RightChild != NULL)
		PostOrder(root->RightChild);
	cout << root->data << " ";
}



/*
			8
		4		6
	2	   3  5		7
*/

int main()
{
	Node* Root = new Node;
	Node* SRoot1 = new Node;
	Node* SRoot2 = new Node;
	Node* LNode1 = new Node;
	Node* LNode2 = new Node;
	Node* LNode3 = new Node;
	Node* LNode4 = new Node;
	InitialNode(Root, 8,
		InitialNode(SRoot1, 4, InitialNode(LNode1, 2), InitialNode(LNode2, 3)),
		InitialNode(SRoot2, 6, InitialNode(LNode3, 5), InitialNode(LNode4, 7)));

	PreOrder(Root);
	cout << endl;
	InOrder(Root);
	cout << endl;
	PostOrder(Root);
	return 0;

}