#ifndef _FUNHASH_H
#define _FUNHASH_H
#include <iostream>
#include <map>
#include <assert.h>
#include <string.h>
#include "vnode.h"
#include "cnode.h"
#include "CMd5.h"

using std::map;

class CHashFun
{
    public:
    virtual long getHashVal(const char *) = 0;
};

class CMDHashFun : public CHashFun
{
    public:
    virtual long getHashVal(const char *);
};

typedef map<long,CVirtualNode*>::iterator  ITERATOR;

class CConHash
{
    public:
    CConHash(CHashFun *pFunc);
    ~CConHash(){}
    int getVNodes();
    void setFunc(CHashFun *pFunc);
    int addNode_s(CNode *pNode);
    int delNode_s(CNode* pNode);
    ITERATOR findHash(long hash);
    CNode* findUpNode(const char *object);
    private:
    CHashFun *func;
    int vNodes;
    map<long,CVirtualNode*> vNode_data;
};
#endif
