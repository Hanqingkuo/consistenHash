#ifndef _CNODE_H
#define _CNODE_H

class CNode
{
    public:
    CNode( char *piden,int pVNodecount, void *pdata);
    ~CNode(){}
    char *getIden();
    int getVNodeCount();
    void *getData();
    void setData(void *pdata);
    private:
    void setCnode(char *piden,int pVNodecount, void *pdata);
    char iden[100];
    int vNodeCount;
    void *data;
};
#endif
