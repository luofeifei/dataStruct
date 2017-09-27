#pragma once
#include <iostream>
template <class k,class v>
 struct AVLTreeData
{
	AVLTreeData<k, v> * _left;
	AVLTreeData<k, v> * _right;
	AVLTreeData<k, v> * _parent; // ���ڵ� ������ת
	k _key;
	v _value;
	int _bf; // ƽ������
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
	// �ж��Ƿ�ƽ��
	bool IsBalance();
	// ɾ���ڵ�
	bool Move(const char key);
	// ����ڵ�
	bool Insert(const char key,const char value);
	// ����
	void RotateR(Node *parent);
	// ����
	void RotateL(Node *parent);
	// ������
	void RotateLR(Node *parent);
	// ������
	void RotateRL(Node *parent);

	// �����
	Node* _root = NULL;
	AVLTreeNode();
	virtual ~AVLTreeNode();
private:


};

