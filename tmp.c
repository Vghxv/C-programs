#include<stdio.h>
#include<math.h>
listNode* swapPairs(listNode* head){
    //before: p > a > b > n
    //after : p > b > a > n
    if(!head||!head->next)
        return head;
    listNode *p=NULL,*a=head,*b=head->next,*n=head->next->next;
    head=head->next;
    while(b){
        if(p) p->next=b;
        if(a) a->next=n;
        if(b) b->next=a;
        p=a;
        a=n;
        b=a? a->next:NULL;
        n=b? b->next:NULL;
    }
    return head;
}