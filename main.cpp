#include <iostream>

#include "Tree.h"
#include "BSTree.h"
//#include "AVLTree.h"
//#include "AVLTreeNode.h"
#include "RBTree.h"
#include <string.h>
#include <windows.h>
using namespace std;
int main()
{

	RBTree *rbtree = new RBTree();
	int a[] = { 5,3,8,2};
	int b[] = { 5,3,4 };
	int c[] = { 5,3,1 };
	unsigned long time = GetTickCount();
	/*for (int n : a)
	{
		int flag = int(n);
		cout << "Insert " << n << endl;
		rbtree->Insert(n, 0);
	}*/
	for (int n : b)
	{
		int flag = int(n);
		cout << "Insert " << n << endl;
		rbtree->Insert(n, 0);
	}
	unsigned long time2 = GetTickCount();

	cout << time2 - time << endl;
	rbtree->mdisplay(rbtree->_root);
	/*AVLTreeNode *avltree = new AVLTreeNode();
	char a[] = {'a','e','f','b','c','d'};

	unsigned long time = GetTickCount();
	for (char n : a)
	{
		int flag = int(n);
		cout << "Insert "<< n << endl;
		avltree->Insert(n, 0);
	}
	unsigned long time2 = GetTickCount();

	cout << time2 - time << endl;*/
	//avltree->mdisplay(avltree->_root);
	//avltree->Insert('a', 0);
	/*AVLTree *avltree = new AVLTree();

	int a[10] = {2, 1,0,3,4,5,6,9,8,7 };
	for (int n : a)
	{
		cout << "insert " << n << endl;
		avltree->insertAVL(avltree->m_root,n);
	}
	avltree->mdisplay(avltree->m_root);*/
	/*CBSTree *bs = new CBSTree();

	bs->insertByRecursion(50,bs->parent);
	bs->insertByRecursion(150, bs->parent);
	bs->insertByRecursion(40, bs->parent);
	bs->insertByRecursion(200, bs->parent);
	bs->insertByRecursion(140, bs->parent);
	bs->insertByRecursion(250, bs->parent);*/
	/*bs->insert(50);
	bs->insert(150);
	bs->insert(40);
	bs->insert(200);
	bs->insert(140);
	bs->insert(250);*/
	//// test
	//int age = 30;
	//int oldAge = 50;
	//int *t = &age;
	//*t = 20;
 //   const int *p = &age;
	//int * const c = &age;
	//*c = oldAge;
	//age = 51;
	//p = &oldAge;
	//// test
	//Tree *tree = new Tree();
	//
	//tree->initTree();

	//int flag;

	//do
	//{
	//	wcout << "请选择添加二叉树的节点" << endl;
	//	wcout << "0 退出\t" << endl;
	//	wcout << "1 添加二叉树的节点" << endl;
	//	wcout << "2 显示二叉树的深度" << endl;
	//	wcout << "3 清空二叉树" << endl;
	//	wcout << "4 先序遍历二叉树" << endl;
	//	wcout << "5 中序遍历二叉树" << endl;
	//	wcout << "6 后序遍历二叉树" << endl;
	//	wcout << "7 按层遍历二叉树" << endl;
	//	cin >> flag;

	//	switch (flag)
	//	{
	//	case 2:
	//		wcout << "二叉树深度" << tree->treeDepth(tree->parent)<< endl;
	//		break;
	//	case 1:
	//		tree->addTreeNode(tree->parent);
	//		wcout << "二叉树大小" <<sizeof(tree->parent) <<endl;
	//		break;
	//	case 3:
	//		tree->clear(tree->parent);
	//		wcout << "清空二叉树" << tree->parent->NodeData<< endl;
	//		break;
	//	case 4:
	//		wcout << "先序遍历二叉树" << endl;
	//		tree->fdisplay(tree->parent);
	//		break;
	//	case 5:
	//		tree->mdisplay(tree->parent);
	//		wcout << "中遍历二叉树" << endl;
	//		break;
	//	case 6:
	//		tree->ldisplay(tree->parent);
	//		wcout << "后遍历二叉树" << endl;
	//		break;
	//	case 7:
	//		wcout << "按层遍历二叉树" << endl;
	//		tree->floorDisplay(tree->parent);

	//		break;
	//	case 0:
	//		break;
	//	default:
	//		break;
	//	}
	//} while (flag!='0');

	//bs->mdisplay(bs->parent);
	getchar();
	return 0;
	

}