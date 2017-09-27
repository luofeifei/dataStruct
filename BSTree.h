#pragma once
#include "Tree.h"
class CBSTree:public Tree
{
public:
	
	CBTType * find(const int ndata,const CBTType*p) const;
	CBTType * findMin(const CBTType*p) const;
	CBTType * findMax(const CBTType*p) const;
	CBTType * insert(const int ndata) const;
	CBTType * insertByRecursion(const int ndata, CBTType * p) const;
	CBTType * deleteNode(const int ndata) const;
	CBSTree();
	virtual ~CBSTree();
};

