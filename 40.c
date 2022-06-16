#include<stdio.h>
#include<stdlib.h>
typedef struct node_s{
	char data;
	struct node_s *left;
	struct node_s *right;
}node_t;
typedef node_t * nodep_t;
nodep_t newnode(char data){
	nodep_t k;
	k->data=data;
	k->left=NULL;
	k->right=NULL;
	return k;
}
int main(){
	char a[50];
	char b[50];
	scanf("%d",a);
	scanf("%d",b);
	
	return 0;
}