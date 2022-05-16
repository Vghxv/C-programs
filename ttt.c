#include<stdio.h>
#include<stdlib.h>
int main(){
	int *a;
	a=malloc(sizeof(int)*0);
	printf("%d\n",sizeof(a));
	printf("%d",*a);
	if(a==NULL)printf("sss");
	return 0;
}