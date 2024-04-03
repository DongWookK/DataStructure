#pragma once
#define CRT_SECURE_NO_WARNING
#include "BTree.h"
#include <iostream>
using namespace std;

#pragma region Node

const Node& Node::GetDefault()
{
	static Node aNode{};
	return aNode;
}

Node* Node::InitialNode(Node* pNode, vector<int>& pData, vector<Node*> pChild)
{
	pNode->mChild = pChild;
	pNode->mData = pData;
	return pNode;
}

#pragma endregion

void BTree::PreOrder(Node* pNode)
{
	for (auto aKey : pNode->mData)
	{
		cout << aKey << " / ";
	}

	for (auto aNode : pNode->mChild)
	{
		PreOrder(aNode);
	}
}

Node* BTree::Insert(int data)
{
	//Find
	//Insert
	//Check
	return 0;
}

BTree::EState BTree::Check(Node* pNode) const
{
	if (M < pNode->mData.size())
	{
		return EOVER;
	}
	else if (pNode->mData.size() < ceil(((M / 2) - 1)))
	{
		return EUNDER;
	}
	
	return ESAFE;
}

Node* BTree::Find(Node* pNode, int data)
{

}