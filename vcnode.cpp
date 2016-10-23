#include<iostream>
#include "vnode.h"
#include "cnode.h"
CVirtualNode::CVirtualNode( CNode *pnode)
{
    Node = pnode;
}

long CVirtualNode::getHash()
{
    return hash;
}

void CVirtualNode::setHash(long phash)
{
    hash = phash;
}

CNode *CVirtualNode::getCNode()
{
    return Node;
}

void CVirtualNode::setCNode(CNode * pnode)
{
    Node = pnode;
}



