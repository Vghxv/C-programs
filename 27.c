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
int getfucking(node_t *data,int index){
	node_t a = data[index];
	if(a.nn){
		int res=0,tmp=0,i;
		for(i=0;i<a.nn;i++){
			tmp = a.time + getfucking(data,a.worklist[i]-1);
			res = res > tmp?res:tmp;
		}
		return res;
	} 
	return a.time;
}
int findans(node_t *data,int n){
	int i;
	int max=0;
	for(i=0;i<n;i++){
		int tmp=getfucking(data,i);
		max = max>tmp ? max : tmp;
	}
	return max;
}
int main(){
	int oo;
	scanf("%d",&oo);
	int yy;
	for(yy=0;yy<oo;yy++){
		int n; 
		scanf("%d",&n);
		int i;
		node_t *data;
		data=(node_t*)malloc(sizeof(node_t)*n);
		for(i=0;i<n;i++){
			data[i].totime=0;
			scanf("%d%d",&data[i].time,&data[i].nn);
			data[i].worklist = malloc(sizeof(int)*data[i].nn);
			int j;
			for(j=0;j<data[i].nn;j++){
				scanf("%d",&data[i].worklist[j]);	
			}
		}
		
		printf("%d\n",findans(data,n));
		for(i=0;i<n;i++){
			int j;
			for(j=0;j<data[i].nn;j++){
				free(data[i].worklist);
			}
		}
		free(data);
	}
	return 0;
}