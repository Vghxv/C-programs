#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node_s{
	int val;
	struct node_s *next;
	struct node_s *prev;
}node_t;
typedef node_t* nodep_t;
nodep_t newnode(int x){
	nodep_t k=(nodep_t)malloc(sizeof(node_t));
	k->val=x;
	k->next=NULL;
	k->prev=NULL;
	return k;
}
void printlistnode(nodep_t head){//6
	if(head==NULL){
		printf("None any node");
		return ;
	}
	while(head!=NULL){
		printf("%d ",head->val);
		head=head->next;
	}
}
void enqueue(nodep_t* head,nodep_t* tail,int x){//1
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
void insbyval(nodep_t *head,nodep_t *tail,int x,int y){//2
	nodep_t cur=*head;
	while(cur!=NULL){
		if(cur->val==x)break;
		cur=cur->next;
	}
	if(cur==NULL)return;
	else{
		nodep_t new = newnode(y);
		if(cur->next!=NULL){
			new->prev=cur;
			new->next=cur->next;
			cur->next->prev=new;
			cur->next=new;
		}
		else{
			new->prev=cur;
			cur->next=new;
			*tail=new;//vital
		}
	}
}
void delbyval(nodep_t *head,nodep_t *tail,int x){//3
	nodep_t cur=*head;
	while(cur!=NULL){
		if(cur->val==x)break;
		cur=cur->next;
	}
	if(cur==NULL)
		return;
	else{
		nodep_t tmp = cur;
		if(cur->next==NULL){
			if(cur->prev==NULL){
				*head=NULL;
				*tail=NULL;
			}
			else{
				cur->prev->next=NULL;
			}
		}
		else{
			if(cur->prev==NULL){
				cur->next->prev=NULL;
				*head=cur->next;//head got freed!!! 
			}
			else{
				cur->prev->next=cur->next;
				cur->next->prev=cur->prev;
			}
		}
		free(tmp);
	}
}
void deque(nodep_t* head,nodep_t* tail){//4
	if((*head)==NULL&&(*tail)==NULL){
		return;
	}
	nodep_t tmp = *head;
	*head=(*head)->next;
	if(*head==NULL){
		*tail=NULL;
	}
	else{
		(*head)->prev=NULL;
	}
	free(tmp);
}
void deltail(nodep_t *head,nodep_t *tail){//5
	if((*head)==NULL&&(*tail)==NULL){
		return;
	}
	nodep_t tmp = *tail;
	(*tail)=(*tail)->prev;
	if((*tail)==NULL){
		*head=NULL;
	}
	else{
		(*tail)->next=NULL;
	}
	free(tmp);
}
int main(){
	int L=0;
	int val=0;
	scanf("%d",&L);
	nodep_t head = NULL;
	nodep_t tail = NULL;
	int i;
	for(i=0;i<L;i++){
		scanf("%d",&val);
		enqueue(&head,&tail,val);
	}
	int ins=0;
	while(1){
		scanf("%d",&ins);
		if(ins==1){
			int x;
			scanf("%d",&x);
			enqueue(&head,&tail,x);
		}
		else if(ins==2){
			int x,y;
			scanf("%d%d",&x,&y);
			insbyval(&head,&tail,x,y);
		}
		else if(ins==3){
			int x;
			scanf("%d",&x);
			delbyval(&head,&tail,x);
		}
		else if(ins==4){
			deque(&head,&tail);
		}
		else if(ins==5){
			deltail(&head,&tail);
		}
		else if(ins==6){
			printlistnode(head);
			break;
		}
	}
	return 0 ;
}