#ifndef _VNODE_H
#define _VNODE_H
#include "cnode.h"
class CVirtualNode
{
    public:
    CVirtualNode( CNode*pnode);
    ~CVirtualNode(){}
    long getHash();
    void setHash(long phash);
    CNode *getCNode();
    void setCNode(CNode* pCNode);
    private:
    long hash;
    CNode *Node;
};
#endif
