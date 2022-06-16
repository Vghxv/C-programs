#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node_s{
	char data;
	struct node_s *left,*right;
}node_t;
node_t* newnode(char data){
	node_t* k=(node_t*)malloc(sizeof(node_t));
	k->data=data;
	k->left=NULL;
	k->right=NULL;
	return k;
}
int cmp(char *I,char curdata,char data){
	int i,a=0,b=0;
	for(i=0;i<strlen(I);i++){
		if(I[i]==curdata)a=i;
		else if(I[i]==data)b=i;
	}
	return a-b;
}
void bfs_print(node_t** unvisited,int n){
	int i,listn=0;
	node_t **t = (node_t**)malloc(sizeof(node_t*)*10);
	for(i=0;i<10;i++)*(t+i)=(node_t*)malloc(sizeof(node_t));
	for(i=0;i<n;i++){
		printf("%c",unvisited[i]->data);
		if(unvisited[i]->left!=NULL)t[listn++]=unvisited[i]->left;
		if(unvisited[i]->right!=NULL)t[listn++]=unvisited[i]->right;
	}
	if(listn)bfs_print(t,listn);
	for(i=0;i<10;i++)free(*(t+i));
	free(t);
}
void create_tree(char *I,char *P,node_t **root){
	int i;
	for(i=0;i<strlen(P);i++){
		node_t* new = newnode(P[i]);
		if(*root==NULL){
			(*root)=new;
			continue;
		}
		node_t *cur=*root,*prev=NULL;
		while(cur!=NULL){
			prev=cur;
			if(cmp(I,cur->data,new->data)>0)cur=cur->left;
			else cur=cur->right;
		}
		if(cmp(I,prev->data,new->data)>0)prev->left=new;
		else prev->right=new;
	}
}
void swap(char* a,char* b){
	char k=*a;
	*a=*b;
	*b=k;
}
void inv(char (*k)[50]){
	int i;
	for(i=0;i<strlen(*k)/2;i++)
		swap(*k+i,*k+strlen(*k)-i-1);
}
int main(){
	char a[50];
	char b[50];
	char a1,b1;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	scanf("%c%s%*c%c%s",&a1,a,&b1,b);
	node_t *root=NULL;
	if(a1=='I'){
		if(b1=='O')inv(&b);
		create_tree(a,b,&root);
	}
	else{
		if(a1=='O')inv(&a);
		create_tree(b,a,&root);
	}
	node_t **unvisited = &root;
	bfs_print(unvisited,1);
	free(root);
	return 0;
}