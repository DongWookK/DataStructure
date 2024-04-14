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

void Node::Insert(const int32_t pKey, const Node* pFromNode)
{
	if (mKey.empty())
	{
		mKey.push_back(pKey);

		if (&Node::GetDefault() != pFromNode)	// Internal Node
		{

		}
		else									// LeafNode
		{
			if (&Node::GetDefault() != pFromNode)
			{
				cout << "Error" << endl;
			}
		}
	}
	else
	{
		int32_t aIndex = 0;
		for (aIndex = 0; aIndex < mKey.size(); ++aIndex)
		{
			if (pKey < mKey[aIndex])
			{
				continue;
			}
			else
			{
				break;
			}
		}

		// 기존 Key,Child를 한칸씩 뒤로 밀고 aIndex에 삽입
		for (int32_t i = aIndex; i < mKey.size(); ++i)
		{
			mKey[i + 1] = mKey[i];
		}

		if (aIndex == mKey.size() -1)
		{
			mKey[aIndex] = pKey;
		}
	}
}

const bool Node::IsLeaf(void) const
{
	for (const auto& aChild : mChild)
	{
		if (false == aChild->mKey.empty())
		{
			return false;
		}
	}
	
	return true;
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
	Node* aNode = &mInitialNode;
	while (nullptr != aNode->mParent)
	{
		aNode = aNode->mParent;
	}
	return aNode;
}

Node* BTree::Insert(Node* pNode
					, int32_t pKey
					, const Node* pFromNode
					, const TKeys& pLeftKey
					, const TKeys& pRightKey)
{
	Node* aInsertNode = nullptr;
	if (&Node::GetDefault() != pFromNode) // balancing
	{
		aInsertNode = pNode;
	}
	else
	{
		aInsertNode = FindLeafNode(pNode, pKey);
	}

	aInsertNode->Insert(pKey, pFromNode);

	// TODO :: pKey만 올리고 삽입된 인덱스에 따라서 pFromNode를 어느 차일드에 둘지
	// 나머지 부족한 차일드를 어디서 가져올지 결정한다.

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
		if (0 == pNode->mKey.size() % 2) // Key가 짝수일때 Median값은 항상 N/2 - 1로 정한다.
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
		
		pNode->mKey.erase(pNode->mKey.begin() + aMedianIndex);

		Insert(pNode->mParent, aMedianValue, pNode);
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
