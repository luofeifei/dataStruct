#pragma once
#include "Tree.h"
class AVLTree:public Tree
{
public:
	CBTType *m_root;
	int Max(int a, int b) { return a > b ? a : b; }
	// LL 左左旋转 调整
	void LL_Rotate(CBTType* &k2)
	{
		CBTType *k1;
		k1 = k2->lSonNode;
		k2->lSonNode = k1->rSonNode;
		k1->rSonNode = k2;
		k2 = k1;

	}
	// RR 右右调整
	void RR_Rotate(CBTType* &k2)
	{
		CBTType *k1;
		k1 = k2->rSonNode;
		k2->rSonNode = k1->lSonNode;
		k1->lSonNode = k2;
		k2 = k1;

	}
	// LR 左右调整
	void LR_Rotate(CBTType* &k2)
	{
		RR_Rotate(k2->lSonNode);
		LL_Rotate(k2);

	}
	// RL 右左调整
	void RL_Rotate(CBTType* &k2)
	{
		LL_Rotate(k2->rSonNode);
		RR_Rotate(k2);
	}
	// 添加节点
	void insertAVL(CBTType* &k2,int data);
	// 查找结点
	CBTType find(DATA t);
	// 获取该节点的深度
	int height(CBTType* node);
	AVLTree();
	virtual ~AVLTree();
};

