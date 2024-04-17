#pragma once
#include <vector>
#include <array>
#include <tuple>>
using namespace std;
constexpr int M = 3;

class Node {
public:
	using SplitNode = std::pair<Node*, Node*>;
public:
	const static Node& GetDefault();

public:
	void Insert(const int32_t pKey, const Node* pFromNode = &Node::GetDefault());
	SplitNode Split(void);
	const bool IsLeaf(void) const;

public:
	vector<int32_t> mKey;
	vector<Node*> mChild;
	Node* mParent = nullptr;
};

class BTree
{
	using TKeys = std::vector<int32_t>;
public:
	enum EState
	{
		ESAFE
		, EOVER
		, EUNDER
	};
public:

public:
	Node*							Insert(Node* pNode
											, int32_t pKey
											, const Node* = &Node::GetDefault());
	void							PreOrder(Node* pNode);
	Node*							GetRoot(void);

private:

	Node*							FindLeafNode(Node* pNode, int32_t pKey);
	BTree::EState					Check(Node* pNode)const;
	void							Balancing(const EState pState, Node* pNode);


private:
	Node mInitialNode{};
	__int32 mSize = 0;
};