#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node* next;
};
struct queue{
    struct node* head;
    struct node* tail;
};
void push(struct queue* n,int value){
    struct node t = malloc(sizeof(struct node);
    n->tail->val = value;
    n->tail->next = t;
}
void pop(struct queue* n,int value){
	struct node t = malloc(sizeof(struct node);
	t->next = n->head->next;
	n->head->next = n->head->next->next;
	free(t);
}
int main(){
    return 0;
}
