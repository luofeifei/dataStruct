#pragma once
/*
根节点
父节点
子节点
叶子节点
子树
*/
#include <iostream>
#define MANLEN 100
typedef int DATA;
typedef struct tree_node
{
	DATA NodeData;// 元素数据

	DATA bf; // 平衡因子
	DATA height; // 子树的高度
	DATA frequent;// 频率

	struct tree_node *lSonNode; // 左子树

	struct tree_node *rSonNode; // 右子树

	//struct tree_node *pSonNode; // 父节点
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
	// 计算二叉树深度
	int treeDepth(CBTType *node);
	// 清空二叉树
	void clear(CBTType *node);
	// 先序遍历二叉树
	void fdisplay(CBTType *node);
	// 中序遍历二叉树
	void mdisplay(CBTType *node);
	// 后序遍历二叉树
	void ldisplay(CBTType *node);
	// 按层遍历
	void floorDisplay(CBTType *node);
	Tree();
	~Tree();
};

