#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node_s{
	int val;
	int power;
	struct node_s *next;
	struct node_s *prev;
}node_t;
typedef node_t* nodep_t;
typedef struct list_s{
	nodep_t head;
	nodep_t tail;
}list_t;
typedef list_t* listp_t;
// void denode(nodep_t no){
	// printf("val:%d\tpower:%d",no->val,no->power);
	// printf("\tnext:");
	// if(no->next!=NULL)printf("%d",no->next->val);
	// else printf("NULL");
	// printf("\tprev:");
	// if(no->prev!=NULL)printf("%d",no->prev->val);
	// else printf("NULL");
	// puts("");
// }
// void delist(nodep_t tail){
	// // nodep_t cur=head;
	// // puts("normal");
	// // while(cur!=NULL){
		// // denode(cur);
		// // cur=cur->next;
	// // }
	// puts("reverse");
	// nodep_t cur=tail;
	// while(cur!=NULL){
		// denode(cur);
		// cur=cur->prev;
	// }
// }
void printlistnode(nodep_t head){
	int first=1;
	if(head==NULL){
		printf("0\n");
		return ;
	}
	while(head!=NULL){
		if(first&&head->next!=NULL&&head->next->next!=NULL){
			if(head->val==1){
				printf("x^%d",head->power);
			}
			else if(head->val==-1){
				printf("-x^%d",head->power);
			}
			else if(head->val!=0){
				printf("%dx^%d",head->val,head->power);
			}
			else{
				printf("0");
			}
		}
		else if(head->power==1){
			if(head->val==1){
				if(first){
					printf("x");
				}
				else
					printf("+x");
			}
			else if(head->val==-1){
				printf("-x");
			}
			else if(head->val>0){
				if(first){
					printf("%dx",head->val);
				}
				else
					printf("+%dx",head->val);
			}
			else if(head->val<0){
				printf("%dx",head->val);
			}
		}
		else if(head->power==0){
			if(head->val>0){
				if(first){
					printf("%d",head->val);
				}
				else
					printf("+%d",head->val);
			}
			else if(head->val<0){
				printf("%d",head->val);
			}
		}
		else{
			if(head->val==1){
				if(first){
					printf("x^%d",head->power);
				}
				else
					printf("+x^%d",head->power);
			}
			else if(head->val==-1){
				printf("-x^%d",head->power);
			}
			else if(head->val>0){
				if(first){
					printf("%dx^%d",head->val,head->power);
				}
				else
					printf("+%dx^%d",head->val,head->power);
			}
			else if(head->val<0){
				printf("%dx^%d",head->val,head->power);
			}
		}
		first=0;
		head=head->next;
	}
	puts("");
}
nodep_t newnode(int x){
	nodep_t k=(nodep_t)malloc(sizeof(node_t));
	k->val=x;
	k->next=NULL;
	k->prev=NULL;
	return k;
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
void enqueuefront(nodep_t* head,nodep_t* tail,int x){
	nodep_t new=newnode(x);
	if((*tail)==NULL){
		(*head) = new;
		(*tail) = new;
		return;
	}
	(*head)->prev = new;
	new->next=(*head);
	(*head) = new;
}
void enqueuefrontv2(nodep_t* head,nodep_t* tail,int x,int y){
	nodep_t new=newnode(x);
	new->power=y;
	if((*tail)==NULL){
		(*head) = new;
		(*tail) = new;
		return;
	}
	(*head)->prev = new;
	new->next=(*head);
	(*head) = new;
}
listp_t newlistin(){
	int num=0;
	int i=0;
	char ch=' ';
	listp_t k=(listp_t)malloc(sizeof(list_t));
	k->head=NULL;
	k->tail=NULL;
	while(1){
		scanf("%d%c",&num,&ch);
		enqueue(&(k->head),&(k->tail),num);
		if(ch==10)break;
	}
	nodep_t cur=k->tail;
	while(cur!=NULL){
		cur->power=i++;
		cur=cur->prev;
	}
	return k;
}
listp_t add(listp_t E1,listp_t E2){
	listp_t res=(listp_t)malloc(sizeof(list_t));
	int i=0;
	res->head=NULL;
	res->tail=NULL;
	nodep_t cur1=E1->tail;
	nodep_t cur2=E2->tail;
	while(cur1!=NULL&&cur2!=NULL){
		enqueuefront(&(res->head),&(res->tail),cur1->val+cur2->val);
		cur1=cur1->prev;
		cur2=cur2->prev;
	}
	while(cur1!=NULL){
		enqueuefront(&(res->head),&(res->tail),cur1->val);
		cur1=cur1->prev;
	}
	while(cur2!=NULL){
		enqueuefront(&(res->head),&(res->tail),cur2->val);
		cur2=cur2->prev;
	}
	nodep_t cur=res->tail;
	while(cur!=NULL){
		cur->power=i++;
		cur=cur->prev;
	}
	while(res->head->val==0){
		deque(&(res->head),&(res->tail));
		if(res->head==NULL)break;
	}
	return res;
}
listp_t sub(listp_t E1,listp_t E2){
	listp_t res=(listp_t)malloc(sizeof(list_t));
	int i=0;
	res->head=NULL;
	res->tail=NULL;
	nodep_t cur1=E1->tail;
	nodep_t cur2=E2->tail;
	while(cur1!=NULL&&cur2!=NULL){
		enqueuefront(&(res->head),&(res->tail),cur1->val-cur2->val);
		cur1=cur1->prev;
		cur2=cur2->prev;
	}
	while(cur1!=NULL){
		enqueuefront(&(res->head),&(res->tail),cur1->val);
		cur1=cur1->prev;
	}
	while(cur2!=NULL){
		enqueuefront(&(res->head),&(res->tail),(-1)*cur2->val);
		cur2=cur2->prev;
	}
	nodep_t cur=res->tail;
	while(cur!=NULL){
		cur->power=i++;
		cur=cur->prev;
	}
	while(res->head->val==0){
		deque(&(res->head),&(res->tail));
		if(res->head==NULL)break;
	}
	return res;
}listp_t mul(listp_t E1,listp_t E2){
	listp_t res=(listp_t)malloc(sizeof(list_t));
	int i;
	res->head=NULL;
	res->tail=NULL;
	nodep_t cur1;
	nodep_t cur2;
	int *a=(int*)malloc(sizeof(int)*100);
	memset(a,0,sizeof(int)*100);
	int j,k;
	j=0;
	cur1=E1->tail;
	while(cur1!=NULL){
		k=0;
		cur2=E2->tail;
		while(cur2!=NULL){
			
			a[j+k]+=cur1->val*cur2->val;
			cur2=cur2->prev;
			k++;
		}
		cur1=cur1->prev;
		j++;
	}
	for(i=0;i<j+k;i++){
		enqueuefrontv2(&(res->head),&(res->tail),a[i],i);
	}
	while(res->head->val==0){
		deque(&(res->head),&(res->tail));
		if(res->head==NULL)break;
	}
	free(a);
	return res;
}
int main(){
	listp_t E1=newlistin();
	listp_t E2=newlistin();
	listp_t o=add(E1,E2);
	printlistnode(o->head);	
	
	o=NULL;
	o=sub(E1,E2);
	printlistnode(o->head);
	
	o=NULL;
	o=mul(E1,E2);
	printlistnode(o->head);
	
	free(E1);
	free(E2);
	free(o);
	
	return 0 ;
}