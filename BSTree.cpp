#include "BSTree.h"
#include <iostream>
using namespace std;


CBTType * CBSTree::find(const int ndata, const CBTType * p) const
{
	return nullptr;
}

CBTType * CBSTree::findMin(const CBTType * p) const
{
	return nullptr;
}

CBTType * CBSTree::findMax(const CBTType * p) const
{
	return nullptr;
}

CBTType * CBSTree::insertByRecursion(const int data, CBTType *p) const
{
	CBTType *pnode = new CBTType();

	// 递归实现
	// 二叉搜索树 左边的比节点X的值小 右边的大
	if (p == NULL)
	{
		p = pnode;
	}
	if (data < p->NodeData) 
	{

		p->lSonNode = insertByRecursion(data, p->lSonNode);
	}
	if (data > p->NodeData)
	{
		p->rSonNode =insertByRecursion(data, p->rSonNode);
	}
	return p;
}
CBTType * CBSTree::insert(const int data) const
{
    CBTType *pnode = new CBTType();
	CBTType *cur;
	int head = 0, tail = 0;
	CBTType *q[MANLEN];
	
	// 二叉搜索树 左边的比节点X的值小 右边的大
	if ( this->parent==NULL)
	{
		wcout << "节点为空" << endl;

		return NULL;
	}
	tail = 1;

	q[tail] = this->parent;

	while (true)
	{
		
		cur = q[tail];

		if (data > cur->NodeData )
		{
			if (cur->rSonNode) {
				tail++;
				q[tail] = cur->rSonNode;
			
			}
			else {
				cur->rSonNode = pnode;
				return NULL;
				break;
			}

		}
		if (data < cur->NodeData)
		{
			if (cur->lSonNode) {
				tail++;
				q[tail] = cur->lSonNode;
			

			}
			else {
				cur->lSonNode = pnode;
				return NULL;
				break;
			}
		}

	}
	
	

	return nullptr;
}
CBTType * CBSTree::deleteNode(const int data) const
{
	return nullptr;
}

CBSTree::CBSTree()
{

}


CBSTree::~CBSTree()
{
}
