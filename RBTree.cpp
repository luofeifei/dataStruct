#include "RBTree.h"

#include <iostream>
using namespace std;

bool RBTree::Insert(const int key, const int value)
{
	// （1）当前节点的父节点为红 叔叔节点也为红
	// （2）当前节点的父节点为红 叔叔节点黑或者不存在，当前节点是右孩子
	// （1）当前节点的父节点为红 叔叔节点黑或者不存在，当前节点是左孩子
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
	while (parent && parent->_col ==RED)// 父节点为红
	{
		Node *grandfather = parent->_parent;
		if (grandfather->_left == parent) // 父节点为左孩子 
		{
			Node *uncle = grandfather->_right;
			if (uncle &&uncle->_col == RED) // 叔叔节点为红
			{
				parent->_col = uncle->_col = BLACK;
				grandfather->_col = RED;
				cur = grandfather;
				parent = cur->_parent;

			}
			else // 叔叔节点不存在 或者不为红
			{
				if (cur == parent->_right) // 插入节点为右孩子
				{
					RotateL(parent);  // 左旋

					Swap(cur,parent); // 调整父子关系
				}
				// 右旋后调色
				RotateR(parent->_parent);
				grandfather->_col = RED;
				parent->_col = BLACK;
				break;

			}
		}
		else  // 父节点为右孩子 
		{
			Node *uncle = grandfather->_left;
			if (uncle &&uncle->_col == RED) // 叔叔节点为红
			{
				parent->_col = uncle->_col = BLACK;
				grandfather->_col = RED;
				cur = grandfather;
				parent = cur->_parent;

			}
			else // 叔叔节点不存在 或者不为红
			{
				if (cur == parent->_left) // 插入节点为右孩子
				{
					RotateR(parent);
					//Swap(cur,parent);
				}
				// 右旋后调色
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
	// parent 应该是4
	parent = cur;

}

RBTree::RBTree()
{
}


RBTree::~RBTree()
{
}
