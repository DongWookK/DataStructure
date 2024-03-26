#pragma once

class Node {

public:
	const static Node GetDefault();
public:
	Node* InitialNode(Node* node, int data, Node* LeftChild, Node* RightChild);
	void Init(void);

public:
	int data;
	Node* LeftChild;
	Node* RightChild;
};

class BTree
{
public:
	Node* Insert(int data);
	Node* Delete(int data);
	
	void PreOrder(Node* pNode);
private:
	Node* Find(int data);

private:
	Node mRoot = Node::GetDefault();
	__int32 mSize;
};