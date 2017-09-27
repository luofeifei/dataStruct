#pragma once
#include <iostream>
template <class k,class v>
 struct AVLTreeData
{
	AVLTreeData<k, v> * _left;
	AVLTreeData<k, v> * _right;
	AVLTreeData<k, v> * _parent; // 父节点 方便旋转
	k _key;
	v _value;
	int _bf; // 平衡因子
	AVLTreeData(const k key, const v value)
		:_left(NULL),
		_right(NULL),
		_parent(NULL),
		_key(key),
		_value(value),
		_bf(0) {};
};
typedef AVLTreeData<char, char> Node;

class AVLTreeNode
{
public:
	void mdisplay(Node *node);
	// 判断是否平衡
	bool IsBalance();
	// 删除节点
	bool Move(const char key);
	// 插入节点
	bool Insert(const char key,const char value);
	// 右旋
	void RotateR(Node *parent);
	// 左旋
	void RotateL(Node *parent);
	// 左右旋
	void RotateLR(Node *parent);
	// 右左旋
	void RotateRL(Node *parent);

	// 根结点
	Node* _root = NULL;
	AVLTreeNode();
	virtual ~AVLTreeNode();
private:


};

