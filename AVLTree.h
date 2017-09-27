#pragma once
#include "Tree.h"
class AVLTree:public Tree
{
public:
	CBTType *m_root;
	int Max(int a, int b) { return a > b ? a : b; }
	// LL ������ת ����
	void LL_Rotate(CBTType* &k2)
	{
		CBTType *k1;
		k1 = k2->lSonNode;
		k2->lSonNode = k1->rSonNode;
		k1->rSonNode = k2;
		k2 = k1;

	}
	// RR ���ҵ���
	void RR_Rotate(CBTType* &k2)
	{
		CBTType *k1;
		k1 = k2->rSonNode;
		k2->rSonNode = k1->lSonNode;
		k1->lSonNode = k2;
		k2 = k1;

	}
	// LR ���ҵ���
	void LR_Rotate(CBTType* &k2)
	{
		RR_Rotate(k2->lSonNode);
		LL_Rotate(k2);

	}
	// RL �������
	void RL_Rotate(CBTType* &k2)
	{
		LL_Rotate(k2->rSonNode);
		RR_Rotate(k2);
	}
	// ��ӽڵ�
	void insertAVL(CBTType* &k2,int data);
	// ���ҽ��
	CBTType find(DATA t);
	// ��ȡ�ýڵ�����
	int height(CBTType* node);
	AVLTree();
	virtual ~AVLTree();
};

