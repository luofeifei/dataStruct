#include "AVLTree.h"
#include <iostream>
using namespace std;


CBTType AVLTree::find(DATA t)
{
	CBTType p;
	return p;
}
void AVLTree::insertAVL(CBTType* &node,int data)
{
	if (node == NULL)
	{
		node = new CBTType();
		node->NodeData = data;
		return;
	}

	if (data<node->NodeData)
	{
		// С�� �������
		insertAVL(node->lSonNode,data);
		//  ���� 
		if (height(node->lSonNode) - height(node->rSonNode) ==2)
		{
			if (data < node->lSonNode->NodeData)
			{
				// LL 
				LL_Rotate(node);
			}
			else
			{
				// LR 
				LR_Rotate(node);
			}
		}
	}
	if (data>node->NodeData)
	{
		// С�� �������
		insertAVL(node->rSonNode, data);
		//  ���� 
		if (height(node->rSonNode) - height(node->lSonNode) == 2)
		{
			if (data > node->rSonNode->NodeData)
			{
				// RR
				RR_Rotate(node);
			}
			else
			{
				// RL
				RL_Rotate(node);
			}
		}
	}
	
	// ���� height
	node->height = Max(height(node->rSonNode), height(node->lSonNode))+1;
	cout <<  node->NodeData << " is "<<"  height = " << node->height << endl;
}

int AVLTree::height(CBTType * node)
{

	if (node!= NULL)
	{
		return node->height;
	}
	return -1;
}

AVLTree::AVLTree()
{
	m_root = NULL;

}


AVLTree::~AVLTree()
{
}
