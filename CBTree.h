#pragma once
template<typename T>
class CBTNode
{
public:
	T data;
	CBTNode<T> *parent;
	CBTNode<T> *left;
	CBTNode<T> *right;
	CBTNode(T data = T(), CBTNode<T> * parent = NULL, CBTNode<T> * left = NULL, CBTNode<T> *right = NUL) :data(data), parent(parent), left(left), right(right) {}
};

template<typename T>
class CBTree
{
public:
	int IsEmpty() const;
	void Destroy();

	// 获取节点的个数
	unsigned int GetNodeCount() const;
	// 获取叶子的个数
	unsigned int GetLeafCount() const;
	// 树的深度
	unsigned int GetDepth() const;
	// 指点节点的深度
	unsigned int GetDepth(const CBTNode <T> *p) const;
	
	CBTree();
	virtual ~CBTree();
protected:
	//CBTNode<T> *m_pNodeRoot;
};

