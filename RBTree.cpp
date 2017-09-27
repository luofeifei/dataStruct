#include "RBTree.h"

#include <iostream>
using namespace std;

bool RBTree::Insert(const int key, const int value)
{
	// ��1����ǰ�ڵ�ĸ��ڵ�Ϊ�� ����ڵ�ҲΪ��
	// ��2����ǰ�ڵ�ĸ��ڵ�Ϊ�� ����ڵ�ڻ��߲����ڣ���ǰ�ڵ����Һ���
	// ��1����ǰ�ڵ�ĸ��ڵ�Ϊ�� ����ڵ�ڻ��߲����ڣ���ǰ�ڵ�������
	if (_root == NULL)
	{
		_root = new Node(key,value);
		_root->_col = BLACK;
		return true;
	}

	Node *parent = NULL;
	Node *cur = _root;
	while (cur)
	{
		if (key<cur->_key)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (key>cur->_key)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
			return false;
		}
	}
	cur = new Node(key,value);
	if (key<parent->_key)
	{
		parent->_left = cur;
		cur->_parent = parent;
	}
	else if (key>parent->_key)
	{
		parent->_right =cur;
		cur->_parent = parent;
	}
	while (parent && parent->_col ==RED)// ���ڵ�Ϊ��
	{
		Node *grandfather = parent->_parent;
		if (grandfather->_left == parent) // ���ڵ�Ϊ���� 
		{
			Node *uncle = grandfather->_right;
			if (uncle &&uncle->_col == RED) // ����ڵ�Ϊ��
			{
				parent->_col = uncle->_col = BLACK;
				grandfather->_col = RED;
				cur = grandfather;
				parent = cur->_parent;

			}
			else // ����ڵ㲻���� ���߲�Ϊ��
			{
				if (cur == parent->_right) // ����ڵ�Ϊ�Һ���
				{
					RotateL(parent);  // ����

					Swap(cur,parent); // �������ӹ�ϵ
				}
				// �������ɫ
				RotateR(parent->_parent);
				grandfather->_col = RED;
				parent->_col = BLACK;
				break;

			}
		}
		else  // ���ڵ�Ϊ�Һ��� 
		{
			Node *uncle = grandfather->_left;
			if (uncle &&uncle->_col == RED) // ����ڵ�Ϊ��
			{
				parent->_col = uncle->_col = BLACK;
				grandfather->_col = RED;
				cur = grandfather;
				parent = cur->_parent;

			}
			else // ����ڵ㲻���� ���߲�Ϊ��
			{
				if (cur == parent->_left) // ����ڵ�Ϊ�Һ���
				{
					RotateR(parent);
					//Swap(cur,parent);
				}
				// �������ɫ
				RotateL(parent->_parent->_parent);
				grandfather->_col = RED;
				parent->_col = BLACK;
				break;

			}

		}

	}
	_root->_col = BLACK;
	return true;
}

void RBTree::RotateL(Node * parent)
{

	Node *subR = parent->_right;
	Node *subRL = subR->_left;

	if (subRL)
		subRL->_parent = parent;

	parent->_right = subRL;

	subR->_left = parent;
	Node *ppnode = parent->_parent;
	parent->_parent = subR;

	if (parent == _root)
	{
		_root = subR;
		_root->_parent = NULL;
	}
	else
	{
		if (ppnode->_right == parent)
		{
			ppnode->_right = subR;
		}
		else
		{
			ppnode->_left = subR;
		}
		subR->_parent = ppnode;
	}
}

void RBTree::RotateR(Node * parent)
{
	Node *subL = parent->_left;
	Node *subLR = subL->_right;

	if (subLR)
		subLR->_parent = parent;
	parent->_left = subLR;

	subL->_right = parent;
	Node *ppnode = parent->_parent;
	parent->_parent = subL;

	if (parent == _root)
	{
		_root = subL;
		_root->_parent = NULL;
	}
	else
	{
		if (ppnode->_left == parent)
		{
			ppnode->_left = subL;
		}
		else
		{
			ppnode->_right = subL;
		}
		subL->_parent = ppnode;
	}
}

void RBTree::mdisplay(Node * parent)
{
	if (parent == NULL) return;
	mdisplay(parent->_left);

	cout << parent->_key<< parent->_col << endl;

	mdisplay(parent->_right);
}

void RBTree::Swap(Node* &cur, Node* &parent)
{
	// parent Ӧ����4
	parent = cur;

}

RBTree::RBTree()
{
}


RBTree::~RBTree()
{
}
