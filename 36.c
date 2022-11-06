// 輸入說明
// 第一行輸入 n，代表初始Link List有多少個節點
// 第二行輸入 n 個整數，依序分別為每個節點的值，第一個整數為起始節點，最後一個整數為結束節點

// 接下來有多行，總共有6種操作:
// 1 x，代表從尾端插入數值為 x 的新節點。

// 2 x y，代表搜尋數值為 x 的節點，並在其之後插入數值為 y 的新節點；
// 若 x 不在Link List中，則不必插入 y 。

// 3 x，代表刪除數值為 x 的節點；若 x 不在Link List中，則不必刪除任何節點。

// 4 代表 刪除起始節點，須將起始節點的下一個節點做為新的起始節點。
// 若 Link List 已無節點，則不必刪除任何節點。

// 5 代表 刪除結束節點，須將結束節點的前一個節點做為新的結束節點。
// 若 Link List 已無節點，則不必刪除任何節點。

// 6 代表 結束程式，並從起始節點到結束節點，依序輸出各個節點的值；
// 若Link List已無任何節點，則輸出"None any node"。

// 輸出說明
// 輸出共一行，從起始節點到結束節點，依序輸出各個節點的值；每個數字中間以空格間隔
// 若Link List已無任何節點，則輸出"None any node"

#include<stdio.h>
#include<stdlib.h>
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
	// puts("gg");
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
void dequeue(nodep_t* head,nodep_t* tail){//4
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
void swap(nodep_t *head,nodep_t *tail,int x,int y){
	nodep_t n1 = NULL;
	nodep_t n2 = NULL; 
	nodep_t tmp = NULL;
	nodep_t cur = *head;
	int p=0;
	while(cur!=NULL){
		if (cur->val==x){
			n1 = cur;
			p=1;
		}
		else if ( cur->val==y){
			n2 = cur;
			p=0;
		}
		cur=cur->next;
	}
	if (n1==NULL || n2==NULL || x==y)return ;
	if(p){
		tmp=n1;
		n1=n2;
		n2=tmp;
	}
	if(n1==*head)*head=n2;
	else if (n2==*head) *head=n1;
	if(n1==*tail)*tail=n2;
	else if (n2==*tail) *tail=n1;
	tmp=n1->next;
	n1->next=n2->next;
	if( n1->next!=NULL)
		n1->next->prev=n1;
	n2->next=tmp;
	if (n2->next!=NULL)
		n2->next->prev=n2;
	tmp=n1->prev;
	n1->prev=n2->prev;
	if(n1->prev!=NULL)
		n1->prev->next=n1;
	n2->prev=tmp;
	if (n2->prev!=NULL)
		n2->prev->next=n2;
	// free(tmp);
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
			dequeue(&head,&tail);
		}
		else if(ins==5){
			deltail(&head,&tail);
		}
		else if(ins==6){
			printlistnode(head);
			break;
		}
		else if(ins==7){
			int x,y;
			scanf("%d%d",&x,&y);
			swap(&head,&tail,x,y);
		}
	}
	free(head);
	free(tail);
	return 0 ;
}