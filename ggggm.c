#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node_s{
	int val;
	struct node_s *next;
}node_t;

node_t* createlist(int *data,int L){
	node_t* head=(node_t*)malloc(sizeof(node_t));
	node_t* now=head;
	int i;
	for(i=0;i<L;i++){
		now->val=data[i];
		if(i!=L-1){
			now->next=(node_t*)malloc(sizeof(node_t));
			now=now->next;
		}
	}
	now->next=NULL;	
	return L?head:NULL;
}
void printlist(node_t *p){
	while(p!=NULL){
		printf("%d ",p->val);
		p=p->next;
	}
	puts("");
	return;
}

int main(){
	int a[10]={1,3,5,7,9,11,13,15,17,19};
	node_t *b=createlist(a,sizeof(a)/sizeof(int));
	printlist(b);
	printlist(b);
	return 0;
}
