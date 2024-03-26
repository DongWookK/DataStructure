#pragma once
#define CRT_SECURE_NO_WARNING
#include "BTree.h"
#include <iostream>
using namespace std;

Node* Node::InitialNode(Node* node, int data, Node* LeftChild, Node* RightChild)
{
	node->LeftChild = LeftChild;
	node->RightChild = RightChild;
	node->data = data;
	return node;
}


void BTree::PreOrder(Node* pNode)
{
	cout << pNode->data << " ";
	if (pNode->LeftChild != NULL)
		PreOrder(pNode->LeftChild);
	if (pNode->RightChild != NULL)
		PreOrder(pNode->RightChild);

}