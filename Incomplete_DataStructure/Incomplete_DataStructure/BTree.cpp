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

Node* Node::InitialNode(Node* pNode, int32_t pKey)
{
	pNode->Insert(pKey);
	return pNode;
}

void Node::Insert(int32_t pKey)
{
	// ������ �׻� leaf�� �Ѵ�.
	if (mKey.empty())
	{
		mKey[0] = pKey;

		mChild[0] = new Node();
		mChild[1] = new Node();
	}
	else
	{
		mKey[mKey.size()] = pKey;

		mChild[(mKey.size() + 1)] = new Node();
	}
}

const bool Node::IsLeaf(void) const
{
	return (mKey.empty());
}

#pragma endregion

void BTree::PreOrder(Node* pNode)
{
	for (auto aKey : pNode->mKey)
	{
		cout << aKey << " / ";
	}
	printf("\n");

	for (auto aNode : pNode->mChild)
	{
		PreOrder(aNode);
	}
}

Node* BTree::GetRoot(void)
{
	// TODO ******************** Get Top Parent
	return &mInitialNode;
}

/*
��������� ȣ���� �� �ְ� ���� �ʿ�
1.InSert ������ �˸´� Leaf�� ã�� ���̴�.
2. ������ �μ�Ʈ�Ѵ�.
3. ���¸� ����.
4. �߶������Ѵ�.
*/
Node* BTree::Insert(Node* pNode, int32_t pKey, bool pIsBalancing)
{
	Node* aInsertNode = nullptr;
	if (!pIsBalancing)
	{
		aInsertNode = pNode;
	}
	else
	{
		aInsertNode = FindLeafNode(pNode, pKey);
	}

	aInsertNode->Insert(pKey);
	auto aState = Check(aInsertNode);
	Balancing(aState, aInsertNode);
	
	return 0;
}

BTree::EState BTree::Check(Node* pNode) const
{
	if (M < pNode->mKey.size())
	{
		return EOVER;
	}
	else if (pNode->mKey.size() < ceil(((M / 2) - 1)))
	{
		return EUNDER;
	}
	
	return ESAFE;
}

Node* BTree::FindLeafNode(Node* pNode, int32_t pKey)
{
	if (pNode->IsLeaf())
	{
		return pNode;
	}

	size_t aIndex = 0;
	for(auto aKey : pNode->mKey)
	{
		if (aKey < pKey)
		{
			++aIndex;
			continue;
		}
		else if (pKey > aKey)
		{
			break;
		}
		else if (pKey == aKey)
		{
			cout << "Error 'duplicated key'" << endl;
			for (auto aKey : pNode->mKey)
			{
				cout << aKey << " / ";
			}
			return pNode;
		}
	}

	return pNode->mChild[aIndex];
}

void BTree::Balancing(const EState pState, Node* pNode)
{
	switch (pState)
	{
	case ESAFE:
	{
		return;
	}break;
	case EOVER:
	{
		size_t aMedianIndex = 0;
		int32_t aMedianValue = 0;
		if (0 == pNode->mKey.size() % 2) // Key�� ¦���϶� Median���� �׻� N/2 - 1�� ���Ѵ�.
		{
			aMedianIndex = pNode->mKey.size() / 2 - 1;
		}
		else
		{
			aMedianIndex = pNode->mKey.size() / 2;
		}

		aMedianValue = pNode->mKey[aMedianIndex];

		for (size_t i = aMedianIndex; i < pNode->mChild.size() - 1; i++)
		{
			pNode->mChild[i] = pNode->mChild[i+1];
		}
		

		if (nullptr == pNode->mParent)
		{
			pNode->mParent = new Node();
		}
		pNode->mParent->Insert(aMedianValue);
		
	}break;
	case EUNDER:
	{

	}break;
	default:
	{

	}break;
	}

	return;
}
