#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node node_t;
struct node{
	// vicent is eidot;
	// he wants to play kirby 
	// amazing mirror
	int time;
	int nn;
	int *worklist;
	int totime;
};
void de(node_t *a,int n){
	int k;
	for(k=0;k<n;k++){
		printf("k:%d\ttime:%d\tlist:",k,a[k].time);
		int i;
		for(i=0;i<a[k].nn;i++)printf("%d ",a[k].worklist[i]);
		puts("");		
	}
}
int jj(node_t *data,int n){
	int ans;
	int i,j,k;
	for()
	
	return ans;
}
int main(){
	int n; 
	scanf("%d",&n);
	int i;
	node_t *data;
	data=(node_t*)malloc(sizeof(node_t*)*n);
	for(i=0;i<n;i++){
		data[i].totime=0;
		scanf("%d",&data[i].time);
		scanf("%d",&data[i].nn);
		data[i].worklist = malloc(sizeof(int)*data[i].nn);
		int j;
		for(j=0;j<data[i].nn;j++){
			scanf("%d",&data[i].worklist[j]);
		}
	}
	// de(data,n);
	return 0;
}