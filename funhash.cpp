#include "funhash.h"
#include "CMd5.h"
#include <string.h>
#include <stdio.h>

long CMDHashFun::getHashVal( const char *instr)
{
    int i;
    long hash = 0;
    unsigned char digest[16];
 
    /*调用MD5相关函数，生成instr的MD5码，存入digest*/
    md5_state_t md5state;
    md5_init(&md5state);
    md5_append(&md5state, (const unsigned char *)instr, strlen(instr));
    md5_finish(&md5state, digest);
 
    /* 每四个字节构成一个32位整数，
    将四个32位整数相加得到instr的hash值（可能溢出） */
    for(i = 0; i < 4; i++)
    {
        hash += ((long)(digest[i*4 + 3]&0xFF) << 24)
            | ((long)(digest[i*4 + 2]&0xFF) << 16)
            | ((long)(digest[i*4 + 1]&0xFF) <<  8)
            | ((long)(digest[i*4 + 0]&0xFF));
    }
    return hash;

}

CConHash::CConHash(CHashFun *pFunc)
{
    assert(pFunc != NULL);
    func = pFunc;
    vNodes = 0;
}

int CConHash::getVNodes()
{
    return vNodes;
}

void CConHash::setFunc(CHashFun * pFunc)
{
    assert(pFunc != NULL);
    func = pFunc;
}

ITERATOR CConHash::findHash(long hash)
{
    map<long,CVirtualNode*>::iterator it = vNode_data.find(hash);
    return it;
}

int CConHash::addNode_s(CNode * pNode)
{
    if(pNode == NULL) return -1;
    int vCount = pNode->getVNodeCount();
    if(vCount <= 0) return -1;
    CVirtualNode *virtualNode;
    char str[100];
    char num[100];
    strcpy(str,pNode->getIden());
    long hash = 0;

    for(int i = 0; i < vCount; ++i)
    {
        virtualNode  = new CVirtualNode(pNode);
        sprintf(num,"%d",i);
        strcat(str,num);
        hash = func->getHashVal(str);
        ITERATOR res = findHash(hash);
        if(res == vNode_data.end())
        {
            vNode_data.insert(std::pair<long,CVirtualNode*>(hash,virtualNode));
            vNodes++;
        }
    }
    return 0;
}

int CConHash::delNode_s(CNode * pNode)
{
    if(pNode == NULL) return -1;
    int vCount = pNode->getVNodeCount();
    if(vCount <= 0) return -1;
    char str[100];
    char num[10];
    strcpy(str,pNode->getIden());
    long hash = 0;
    CVirtualNode *virtualNode = NULL;
    for(int i = 0; i < vCount; ++i)
    {
        sprintf(num,"%d",i);
        strcat(str,num);
        hash = func->getHashVal(str);
        ITERATOR  res = findHash(hash);
        if(res != vNode_data.end())
        {
            vNode_data.erase(hash);
            vNodes--;
        }
    }
    return 0;
}

CNode * CConHash::findUpNode(const char *object)
{
    if(object == NULL || vNodes <= 0)
        return NULL;
    long key = func->getHashVal(object);
    ITERATOR res = vNode_data.upper_bound(key);
    if(res == vNode_data.end())
    {
        return NULL;
    }
    else
    {
        CVirtualNode * tmp = res->second;
        return tmp->getCNode();
    }

}
