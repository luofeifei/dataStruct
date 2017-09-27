#pragma once
/*
���ڵ�
���ڵ�
�ӽڵ�
Ҷ�ӽڵ�
����
*/
#include <iostream>
#define MANLEN 100
typedef int DATA;
typedef struct tree_node
{
	DATA NodeData;// Ԫ������

	DATA bf; // ƽ������
	DATA height; // �����ĸ߶�
	DATA frequent;// Ƶ��

	struct tree_node *lSonNode; // ������

	struct tree_node *rSonNode; // ������

	//struct tree_node *pSonNode; // ���ڵ�
	tree_node()
	{
		lSonNode = NULL;
		rSonNode = NULL;
		height = 0;
		frequent = 1;
	};
}CBTType;


class Tree
{

public:

	CBTType *parent;

	void initTree();
	void addTreeNode(CBTType *node);
	CBTType * findTreeNode(CBTType *node,DATA data);
	CBTType * getLeftNode(CBTType *node);
	CBTType * getRightNode(CBTType *node);
	void displayNodeData(CBTType *node);
	int isEmpty(CBTType *node);
	// ������������
	int treeDepth(CBTType *node);
	// ��ն�����
	void clear(CBTType *node);
	// �������������
	void fdisplay(CBTType *node);
	// �������������
	void mdisplay(CBTType *node);
	// �������������
	void ldisplay(CBTType *node);
	// �������
	void floorDisplay(CBTType *node);
	Tree();
	~Tree();
};

