#include "AVLTreeNode.h"
#include <iostream>
#include <math.h>
using namespace std;


AVLTreeNode::AVLTreeNode()
{
}
AVLTreeNode::~AVLTreeNode()
{
}

// ÇóÉî¶È
size_t _Depth(Node* root)
{
	if (root == NULL)return 0;
	rsize_t leftDepth = _Depth(root->_left);
	rsize_t rightDepth = _Depth(root->_right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

bool _IsBalance(Node *root)
{
	if (root == NULL) return true;
	rsize_t leftH = _Depth(root->_left);
	rsize_t rightH = _Depth(root->_right);
	if ((rightH - leftH) != root->_bf)
	{
		wcout << "Æ½ºâÒò×ÓÒì³£" << root->_key << endl;
	}
	return  abs(int(rightH - leftH)) <= 1
		&& _IsBalance(root->_left)
		&& _IsBalance(root->_right);
}

bool AVLTreeNode::IsBalance()
{
	size_t depth = 0;
	return _IsBalance(_root);
}

bool _Move(Node *root, const int key)
{
	return false;
}
bool AVLTreeNode::Move(const char key)
{

	return _Move(_root, key);;
}

bool AVLTreeNode::Insert(const char key, const char value)
{
	if (_root == NULL)
	{
		_root = new Node(key, value);
		return true;
	}
	Node* parent = NULL;
	Node* cur = _root;

	while (cur)
	{
		if (key < cur->_key)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (key > cur->_key)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
			return false;
		}
	}

	cur = new Node(key, value);

	if (key < parent->_key)
	{
		parent->_left = cur;
		cur->_parent = parent;
	}
	else
	{
		parent->_right = cur;
		cur->_parent = parent;
	}
	if (key == 'd')
	{
		int i = 3;
	}
	while (parent)
	{
		if (parent->_left == cur)
			parent->_bf -= 1;
		else
			parent->_bf += 1;
		if (parent->_bf == 0) break;
		else if (parent->_bf == 1 || parent->_bf == -1)
		{
			cur = parent;
			parent = cur->_parent;
		}
		else if (parent->_bf == 2 || parent->_bf == -2)
		{
			if (parent->_bf == 2) {

				if (cur->_bf == 1)
				{
					RotateL(parent);
				}
				else {
					RotateRL(parent);
				}
			}
			else
			{
				if (cur->_bf == -1)
				{
					RotateR(parent);
				}
				else {
					RotateLR(parent);
				}
			}

			break;

		}
	}


	return false;
}

// ÓÒÐý
void AVLTreeNode::RotateR(Node * parent)
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
	parent->_bf = subL->_bf = 0;
}
// ×óÐý
void AVLTreeNode::RotateL(Node *parent)
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
	parent->_bf = subR->_bf = 0;
}
// ×óÓÒÐý
void AVLTreeNode::RotateLR(Node *parent)
{
	Node* subL = parent->_left;
	Node* subLR = subL->_right;

	int bf = subLR->_bf;

	RotateL(parent->_left);
	RotateR(parent);

	if (bf == 1)
	{
		subL->_bf = -1;
		parent->_bf = 0;
	}
	else if (bf == -1)
	{
		subL->_bf = 0;
		parent->_bf = 1;
	}
	else
	{
		parent->_bf = subL->_bf = 0;
	}
	subLR->_bf = 0;
}
// ÓÒ×óÐý

void AVLTreeNode::RotateRL(Node *parent)
{
	Node* subR = parent->_right;
	Node* subRL = subR->_left;

	int bf = subRL->_bf;

	RotateR(parent->_right);
	RotateL(parent);

	if (bf == 1)
	{
		subR->_bf = -1;
		parent->_bf = 0;
	}
	else if (bf == -1)
	{
		subR->_bf = 0;
		parent->_bf = 1;
	}
	else
	{
		parent->_bf = subR->_bf = 0;
	}
	subR->_bf = 0;
}
// LDR
void AVLTreeNode::mdisplay(Node * node)
{
	if (node == NULL)
		return;

	mdisplay(node->_left);
	cout << node->_key << endl;
	mdisplay(node->_right);
}