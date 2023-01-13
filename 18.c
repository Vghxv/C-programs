#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int len(char *a){
	int i=0;
	while(a[i]!=0)i++;
	return i;
}
int is_counted(char *stack,int di,char b){
	int i;
	for(i=0;i<di;i++){
		if(stack[i]==b)return 0;
	}
	return 1;
}
void append(char *stack,char b){
	int i=0;
	while(stack[i]!=0)i++;
	stack[i]=b;
}
int main(){
	int i,j,di,La,k;
	int count=0;
	char a[30];
	char *stack;
	memset(a,0,sizeof(a));
	scanf("%s",a);
	scanf("%d",&di);
	stack=malloc(di*sizeof(char));
	memset(stack,0,di*sizeof(char));
	La=len(a);
	for(i=0;i<La-di+1;i++){
		// printf("%d\n",i);
		for(j=i;j<di+i;j++){
			char tmp = a[j]; 
			// printf("j=%d:value=%c ",j,tmp);
			if(is_counted(stack,di,tmp)){
				append(stack,tmp);
				// printf("stack:");
				// puts(stack);
				if(j==di+i-1){
					count+=1;
					memset(stack,0,di*sizeof(char));
				}
			}
			else{
				// printf("stack:");
				// puts(stack);
				memset(stack,0,di*sizeof(char));
				break;
			} 
		}
		// printf("count=%d ",count);
		// printf("\n\n");
	}
	printf("%d",count);
	free(stack);
	return 0;
}