#include<stdio.h>
#include<stdlib.h>
typedef struct listnode listnode;
struct listnode{
	int val;
	struct listnode *next;
};
listnode* save(int *b,int len){
	if(!len)return NULL;
	listnode* head=(listnode*)malloc(sizeof(listnode));
	listnode* c_node = head;
	int i;
	for(i=0;i<len;i++){
		c_node->val=b[i];
		if(i!=len-1){
			c_node->next = (listnode*)malloc(sizeof(listnode));
			c_node = c_node->next;
		}
	}
	c_node->next=NULL;
	return head;
}
void debug(listnode* head){
	if(head){
		printf("%d ",head->val);
		while(head=head->next)printf("%d ",head->val);
		puts("");
	}
	return ;
}
void freelist(){
	
	return ;
}
int main(){
	int a[3]={3,4,5};
	listnode *head = save(a,sizeof(a)/sizeof(int));
	debug(head);
	printf("5 4 3");
	return 0;
}