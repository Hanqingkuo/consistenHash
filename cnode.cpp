#include <iostream>
#include <cstring>
#include "cnode.h"

CNode::CNode( char *piden,int PVNode,void *pdata)
{
    setCnode(piden,PVNode,pdata);
}
char *CNode::getIden()
{
    return iden;
}

int CNode::getVNodeCount()
{
    return vNodeCount;
}

void *CNode::getData()
{
    return data;
}

void CNode::setData(void *pdata)
{
    data = pdata;   
}

void CNode::setCnode(char *piden,int vconunt,void *pdata)
{
    strcpy(iden,piden);
    vNodeCount = vconunt;
    data = pdata;
}


