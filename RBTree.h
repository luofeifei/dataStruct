#pragma once
#pragma once
#include <iostream>

enum Color
{
	RED,
	BLACK
};

template <class k, class v>
struct AVLTreeData
{
	AVLTreeData<k, v> * _left;
	AVLTreeData<k, v> * _right;
	AVLTreeData<k, v> * _parent; // ���ڵ� ������ת
	k _key;
	v _value;
	Color _col; // ƽ������
	AVLTreeData(const k key, const v value)
		:_left(NULL),
		_right(NULL),
		_parent(NULL),
		_key(key),
		_value(value),
		_col(RED) {};
};
typedef AVLTreeData<int, int> Node;
class RBTree
{
public:
	Node *_root = NULL;
	bool Insert(const int key, const int value);
	void RotateL(Node* parent);
	void RotateR(Node* parent);
	void mdisplay(Node* parent);
	void Swap(Node* &cur, Node* &parent);
	RBTree();
	virtual ~RBTree();
};

