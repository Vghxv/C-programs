#include<stdio.h>
#include<stdlib.h>

typedef struct listNode{
    int val;
    struct listNode *next;
}listNode;

listNode* createList(int*a,int len){
    listNode* head=(listNode*)malloc(sizeof(listNode));
    listNode* cur=head;
    for(int i=0;i<len;i++){
        cur->val=a[i];
        if(i!=len-1){
            cur->next=(listNode*)malloc(sizeof(listNode));;
            cur=cur->next;
        }
    }
    cur->next=NULL;
    return (len)?head:NULL;
}

void printList(listNode* head){
    if(head){
        printf("%d ",head->val);
        while(head=head->next)
            printf("%d ",head->val);
        printf("\n");
    }
    return;
}

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

int main(){
    int testCase[]={1,2,3,4,5,6,7};
    listNode* head=createList(testCase,sizeof(testCase)/sizeof(int));
    printList(swapPairs(head));
    return 0;
}