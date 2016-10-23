#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "cnode.h"
#include "vnode.h"
#include "funhash.h"

using namespace std;

int main()
{
	srand(time(0));
	freopen("out.txt","r",stdin);
	CHashFun * func = new CMDHashFun();
	CConHash * conhash = new CConHash(func);
    char a1[30] = "machineA";
    char a2[30] = "machineB";
    char a3[30] = "machineC";
    char a4[30] = "machineD";
    CNode * node1 = new CNode(a1,9,(void*)"10.3.0.201");
    CNode * node2 = new CNode(a2,8,(void*)"10.3.0.202");
    CNode * node3 = new CNode(a3,3,(void*)"10.3.0.203");
    CNode * node4 = new CNode(a4,10,(void*)"10.3.0.204");

    conhash->addNode_s(node1);
    conhash->addNode_s(node2);
    conhash->addNode_s(node3);
    conhash->addNode_s(node4);

//	node1->setData("99999999");
	
	int ans1 ,ans2 ,ans3 ,ans4;
	ans1=ans2=ans3=ans4=0;
	
	char object[100];
	CNode * node ;
	/*¶¯Ì¬É¾³ý½áµã*/
	//conhash->delNode_s(node2);
	for(int i =0;i<40;i++)
	{
		cin>>object;
		node = conhash->findUpNode(object);
		if(node!=NULL)
		{
			cout<<object<<"----->\t"<<node->getIden()<<" \t "<<(char *)node->getData()<<endl;
			if(strcmp(node->getIden(),"machineA")==0) ans1++;
			if(strcmp(node->getIden(),"machineB")==0) ans2++;
			if(strcmp(node->getIden(),"machineC")==0) ans3++;
			if(strcmp(node->getIden(),"machineD")==0) ans4++;
		}
	}

	cout<<"Total test cases : "<<ans1+ans2+ans3+ans4<<endl;
	cout<<"Map to MachineA : "<<ans1<<endl;
	cout<<"Map to MachineB : "<<ans2<<endl;
	cout<<"Map to MachineC : "<<ans3<<endl;
	cout<<"Map to MachineD : "<<ans4<<endl;
	fclose(stdin);
	return 0;
}
