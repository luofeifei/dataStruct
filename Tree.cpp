#include "Tree.h"
#include <iostream>
#include <math.h>
using namespace std;

void Tree::initTree()
{
	parent->NodeData = 100;
	parent->lSonNode = NULL;
	parent->rSonNode = NULL;
	/*CBTType *nodeA= new CBTType{ '100',NULL,NULL };
	CBTType *nodeE = new CBTType{ 'E',NULL,NULL };
	CBTType *nodeC = new CBTType{ 'C',NULL,NULL };
	CBTType *nodeB = new CBTType{ 'B',nodeD,nodeE };*/
	//parent = new CBTType{100,NULL,NULL };
	/*parent =(CBTType *)malloc(sizeof(CBTType));
	parent->NodeData = 'A';
	parent->lSonNode = NULL;
	parent->rSonNode = NULL;*/
}

void Tree::addTreeNode(CBTType * node)
{
	CBTType * pnode, *pparent;
	DATA data;
	int menusel=0;

	if (pnode = new CBTType())
	{
		cout << "please input the data of node" << endl;
		cin >> pnode->NodeData;
		pnode->lSonNode = NULL;
		pnode->rSonNode = NULL;

		// 父节点数据

		cout << "please input the data of parentnode" << endl;
		cin >> data;

		pparent = findTreeNode(node, data);
		if (!pparent)
		{
			cout << "not found parentnode" << endl;
			delete pnode;
			return;
		}
		// 添加该节点到左子树  /添加该节点到右子树
		cout << "please enter l add left or enter r add right" << endl;
		
		do
		{

			cin >> menusel;
			//menusel = getchar();
			if (menusel == 1 || menusel == 2)
			{
				if (pparent == NULL)
				{
					wcout << "不存在父节点!\n" << endl;
				}
				else {
					switch (menusel)
					{
					case 1: // 添加到左节点
						if (pparent->lSonNode) // 左子树不为空
						{
							wcout << "左子树不为空!\n" << endl;
						}
						else 
						{
							pparent->lSonNode = pnode;
						
						}
						break;
					case 2: // 添加到左节点
						if (pparent->rSonNode) // 右子树不为空
						{
							wcout << " 右子树不为空!\n" << endl;
						}
						else
						{
							pparent->rSonNode = pnode;

						}
						break;
					default:
						wcout << " 无效参数!\n" << endl;
						break;
					}
				}
			}


		} while (menusel != 1 && menusel !=2);
	}
}

CBTType * Tree::findTreeNode(CBTType * node, DATA data)
{
	CBTType *ptr;
	if (node == NULL)
	{
		return NULL;
	}
	else
	{
		if (node->NodeData == data)
		{
			return node;
		}
		else 
		{
			if (ptr = findTreeNode(node->lSonNode, data))
			{
				return ptr;
			}
			else if (ptr = findTreeNode(node->rSonNode, data))
			{
				return ptr;
			}
			else
			{
				return NULL;
			}
		}
	
	}

}

CBTType * Tree::getLeftNode(CBTType * node)
{
	if (node == NULL && node->lSonNode ==NULL)
	{
		return NULL;
	}
	else
	{
		return node->lSonNode;
	}
}

CBTType * Tree::getRightNode(CBTType * node)
{
	if (node == NULL && node->rSonNode == NULL)
	{
		return NULL;
	}
	else
	{
		return node->rSonNode;
	}
}

void Tree::displayNodeData(CBTType * node)
{
	cout << node->NodeData<<endl;
}

int Tree::isEmpty(CBTType * node)
{
	if (node)
	{
		return 0;
	}
	else 
	{
		return 1;
	}
}

int Tree::treeDepth(CBTType * node)
{
	int lDepth, rDepth;
	if (node == NULL)
	{
		return 0;
	}
	else
	{
		cout << node->NodeData << endl;
		lDepth = treeDepth(node->lSonNode);
		rDepth = treeDepth(node->rSonNode);
		if (lDepth > rDepth)
		{
			return lDepth + 1;
		}
		else {
			return rDepth+1;
		}
	}
}

void Tree::clear(CBTType * node)
{
	if (node == NULL)
	{
		return;
	}
	node->NodeData = '0';
	node->lSonNode = NULL;
	node->rSonNode = NULL;
	clear(node->lSonNode);
	clear(node->rSonNode);
}
// DLR
void Tree::fdisplay(CBTType * node)
{
	if (node==NULL) 
		return;
	cout << node->NodeData<<endl;
	fdisplay(node->lSonNode);
	fdisplay(node->rSonNode);
}
// LDR
void Tree::mdisplay(CBTType * node)
{
	if (node == NULL)
		return;

	mdisplay(node->lSonNode);
	cout << node->NodeData << endl;
	mdisplay(node->rSonNode);
}
// LRD
void Tree::ldisplay(CBTType * node)
{
	if (node == NULL)
		return;
	ldisplay(node->lSonNode);
	ldisplay(node->rSonNode);
	cout << node->NodeData << endl;
}
void Tree::floorDisplay(CBTType * node)
{
	//int depth = treeDepth(node);
	//int step = 1;
	//while (step<=depth)
	//{
	//	int maxlen = pow(2.0, step - 1);
	//	for (int i = 0; i < maxlen; i++)
	//	{
	//		//动态内存  需要存起来
	//		//if()
	//	}

	//}
	CBTType *p;
	CBTType *q[MANLEN];

	int head = 0, tail = 0;

	if (node)
	{
		tail = (tail + 1) % MANLEN;
		q[tail] = node;
	}
	while (head!=tail)
	{
		
		head = (head + 1) % MANLEN;
		p = q[head];
		
		displayNodeData(p);

		if (p->lSonNode != NULL)
		{
			tail = (tail + 1) % MANLEN;
			q[tail] = p->lSonNode;
		}
		if (p->rSonNode != NULL)
		{ 
			tail = (tail + 1) % MANLEN;
			q[tail] = p->rSonNode;
		}

	}










}
Tree::Tree()
{
	
}


Tree::~Tree()
{
}
