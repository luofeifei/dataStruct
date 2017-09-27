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

	// ��ȡ�ڵ�ĸ���
	unsigned int GetNodeCount() const;
	// ��ȡҶ�ӵĸ���
	unsigned int GetLeafCount() const;
	// �������
	unsigned int GetDepth() const;
	// ָ��ڵ�����
	unsigned int GetDepth(const CBTNode <T> *p) const;
	
	CBTree();
	virtual ~CBTree();
protected:
	//CBTNode<T> *m_pNodeRoot;
};

