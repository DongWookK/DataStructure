#pragma once

class Node {

public:
	const static Node GetDefault();
public:
	Node* InitialNode(Node* node, int data, Node* LeftChild, Node* RightChild);
	void Init(void);

private:
	int data;
	Node* LeftChild;
	Node* RightChild;
};

class Btree
{
public:
	Node* Insert();
	Node* Delete();
	

private:
	Node mRoot = Node::GetDefault();
	__int32 mSize;
};