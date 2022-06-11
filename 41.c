#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	scanf("%d",&n);
	int** data=(int**)malloc(sizeof(int*)*n);
	
	int i,j;
	
	for(i=0;i<n;i++){
		
		for(j=0;j<n;j++){
			scanf("%d",&data[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",data[i][j]);
			
		}
		puts("");
	}
	return 0;
}