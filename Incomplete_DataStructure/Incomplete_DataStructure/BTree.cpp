#pragma once
#define CRT_SECURE_NO_WARNING
#include "BTree.h"
using namespace std;

Node* Node::InitialNode(Node* node, int data, Node* LeftChild, Node* RightChild)
{
	node->LeftChild = LeftChild;
	node->RightChild = RightChild;
	node->data = data;
	return node;
}
