#include<stdio.h>
#include<stdlib.h>
int main(){
	char p[50];
	gets(p);
	int i;
	for(i=0;i<50;i++){
		printf("%d ",p[i]);
	}
	// printf("%s",p);
	return 0;
}