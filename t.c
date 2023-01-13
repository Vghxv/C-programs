#include <stdio.h>
#include <stdlib.h>
typedef struct node_s {
	int data;
	struct node_s * next;
} node_t;
typedef node_t * nodep_t;
nodep_t create(int data){
	nodep_t new;
	new=(nodep_t)malloc(sizeof(node_t));
	new->data=data;
	new->next=NULL;
	return new;
}
void enqueue(nodep_t* head,nodep_t *tail, int x) {
	nodep_t new=create(x);
	if((*head)==NULL){
		*head = new;
		*tail = new;
		return;
	}
	(*tail)->next=new;
	(*tail)=new;
}
int dequeue(nodep_t *head) {
	int data=(*head)->data;
	nodep_t k=*head;
	*head=(*head)->next;
	free(k);
	return data;
}
int main() {
	int x;
	nodep_t tail = NULL, head=NULL;
	enqueue(&head,&tail, 5);
	enqueue(&head,&tail, 8);
	x = dequeue(&head);
	printf("%d\n", x);
	x = dequeue(&head);
	printf("%d\n", x);
	return 0;
}
