#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// typedef struct p_t{
	// char name[50];
	// int age;
// };
// int main(){
	// p_t a;
	// p_t b;
	// scanf("%s",a.name);
	// scanf("%s",b.name);
	// scanf("%d%d",&a.age,&b.age);
	// printf("%d",(a.age>b.age)?a.age:b.age);
	// return 0;
// }
	
	// while(p!=NULL&&p->score!=score)p=p->next;
	// strcpy(name,p->name);
	// return name;
// int main{
	// nodep_t p=NULL;
	// insertFromFront(&p,5);
	// insertFromFront(&p,3);
	// insertFromBack(&p,8);
	// insertFromBack(&p,7);
	// printList(p);
	// return 0;
// }

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
void push(nodep_t * p_top, int x) {
	nodep_t new=create(x);
	new->next=(*p_top);
	(*p_top)=new;
}
void printStack(nodep_t top) {
	nodep_t now=top;
	while(now!=NULL){
		printf("%d ",now->data);
		now=now->next;
	}
}
void pop(nodep_t *p_top){
	int data=(*p_top)->data;
	
}
int main() {
	nodep_t top = NULL;
	push(&top, 5);
	push(&top, 8);
	printStack(top); // 8 5
	return 0;
}