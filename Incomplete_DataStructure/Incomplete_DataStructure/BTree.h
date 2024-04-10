#pragma once
#include <vector>
#include <array>
using namespace std;
constexpr int M = 3;

class Node {

public:
	const static Node& GetDefault();
public:
	void Insert(const int32_t pKey, const Node* pFromNode = &Node::GetDefault());
	const bool IsLeaf(void) const;
public:
	vector<int32_t> mKey;
	vector<Node*> mChild;
	Node* mParent = nullptr;
};

/*

M차 트리

노드는 최대 M개의 자식 노드를 가질 수 있다.
ex) 3차 B-트리라면 최대 3개의 자식 노드를 가질 수 있다.

노드에는 최대 M-1개의 KEY를 가질 수 있다.
ex) 3차 B-트리라면 최대 2개의 KEY를 가질 수 있다.

각 노드는 최소 ⌈M/2⌉개의 자식 노드를 가진다. (루트 노드와 leaf 노드 제외)
ex) 3차 B-트리라면 각 노드는 최소 2개의 자식 노드를 가진다.

각 노드는 최소 ⌈M/2⌉-1개의 키를 가진다. (루트 노드 제외)
ex) 3차 B-트리라면 각 노드는 최소 1개의 키를 가진다.


데이터는 Leaf에 추가된다고 가정. Key만 Insert한다.
*/

class BTree
{
public:
	enum EState
	{
		ESAFE
		, EOVER
		, EUNDER
	};
public:

public:
	Node*							Insert(Node* pNode, int32_t pKey, const Node* = &Node::GetDefault());
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