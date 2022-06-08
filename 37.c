#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node_s{
	int val;
	struct node_s *next;
	struct node_s *prev;
}node_t;
typedef node_t* nodep_t;

typedef struct list_s{
	nodep_t head;
	nodep_t tail;
}list_t;
typedef list_t* listp_t;

listp_t newlist(){
	listp_t k=(listp_t)malloc(sizeof(list_t));
	k->head=NULL;
	k->tail=NULL;
	return k;
}
nodep_t newnode(int x){
	nodep_t k=(nodep_t)malloc(sizeof(node_t));
	k->val=x;
	k->next=NULL;
	k->prev=NULL;
	return k;
}
void printlistnode(nodep_t head){
	if(head==NULL){
		printf("None any node");
		return ;
	}
	while(head!=NULL){
		printf("%d ",head->val);
		head=head->next;
	}
}
void enqueue(nodep_t* head,nodep_t* tail,int x){
	nodep_t new=newnode(x);
	if((*head)==NULL){
		(*head) = new;
		(*tail) = new;
		return;
	}
	(*tail)->next = new;
	new->prev=(*tail);
	(*tail) = new;
}
// int dequeue(nodep_t* head,nodep_t*tail){
	// nodep_t tmp = *head;;
	// if((*head)!=NULL){
		// int val = (*head)->val;
		
	// }
	// return val;
// }
int main(){
	char buff[100];
	int i,sign,num;
	listp_t E1=newlist();
	listp_t E2=newlist();
	memset(buff,0,sizeof(buff));
	fgets(buff,100,stdin);
	int L=strlen(buff);
	sign=1;
	num=0;
	for(i=0;i<L;i++){
		if(buff[i]=='-'){
			sign=-1;
		}
		else if(buff[i]==32||buff[i]==10){
			printf("%d ",num*sign);
			enqueue(&(E1->head),&(E1->tail),num*sign);
			num=0;
			sign=1;
		}
		else{
			num=num*10+buff[i]-48;
		}
	}
	// puts("");
	// printlistnode(E1->head);
	
	return 0 ;
}