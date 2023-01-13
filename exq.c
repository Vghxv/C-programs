#include<stdio.h>
#include<stdlib.h>
typedef struct node_s{
	int val;
	struct node_s *next;
	struct node_s *prev;
}node_t;
typedef struct queue_s{
	node_t* head;
	node_t* tail;
}queue_t;
node_t* newnode(int val){
	node_t* k=(node_t*)malloc(sizeof(node_t));
	k->next=NULL;
	k->val=val;
	return k;
}
int dequeue(queue_t k){
	if(k->head==NULL){
		return -1;
	}
	node_t *tmp=k->head;
	int val=tmp->val;
	k->head=k->head->next;
	if(k->head==NULL)k->tail=NULL;
	else k->head->prev=NULL;
	free(tmp);
	return val;
}
void enqueue(queue_t k,int val){
	node_t* new=newnode(val);
	if(k->tail==NULL){
		k->head=new;
		k->tail=new;
		return ;
	}
	k->tail->next=new;
	new->prev = k->tail;
	k->tail=k->tail->next;
}
void enqueuef1(queue_t k,int val){
	node_t* new=newnode(val);
	if(k->head==NULL){
		k->head=new;
		k->tail=new;
		return ;
	}
	k->tail->next=new;
	new->prev = k->tail;
	k->tail=k->tail->next;
}