//����	24. �������������еĽڵ�
//��ͨ�� 



#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
	struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head, int k){
    struct ListNode *tail_temp=NULL;
    struct ListNode *headr,*headt=head,*p=head;
    struct ListNode *Atf[k];
	int flag=0,num;
    
    for(num=0;num<k-1;num++)
    {
    	if(p->next!=NULL)
    		p=p->next;
    	else
    		return head;
	}
	headr=p;
    while(true)//�����������ڵ��ҽڵ���Ϊż��;
    {
        for(num=0,p=headt;num<k;num++)//�������ڵ�ͷָ��
        {
        	Atf[num]=p;
        	
        	if(p==NULL)
        	{
        		flag=1;
        		break;
			}
    		p=p->next;    	
	    }
		if(flag)
			break;	   
        headt=p;
        
        for(num-=1;num>=0;num--) 
        	if(num!=0)
        		Atf[num]->next=Atf[num-1];
        		
		
        if(tail_temp!=NULL)
        	tail_temp->next=Atf[k-1];
        tail_temp=Atf[0];
    	
        if(headt==NULL)
        	break;
    }
    
    if(flag)
        tail_temp->next=headt;
    else
        tail_temp->next=NULL;
        
    return headr;
}



int main()
{
	struct ListNode *head=NULL,*pt,*ptr;
	int it;
	for(it=0;it<20;it++)	
	{
		pt=(struct ListNode *)malloc(sizeof(struct ListNode));
		if(head==NULL)
			head=pt;
		else
			ptr->next=pt;
		pt->val=it+1;
		ptr=pt;
	}
	ptr->next=NULL;
	ptr=swapPairs(head,7);

	while(ptr)
	{
		printf("%d:\n",ptr->val);
		ptr=ptr->next;
	}
	
	
	return 0;
}







