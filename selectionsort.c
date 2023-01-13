#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(int *a,int *b){
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
void selsort(int *arr,int size){
	int i,j;
	int index;
	int max = 0;
	i = size;
	while(i>0){
		max = 0;
		j=0;
		while(j<i){
			if(arr[j]>max){
				max = arr[j];
				index = j;
			}
			j++;
		}
		swap(arr+index,arr+i-1);
		i--;
	}
}
int main(){
	int i;
	int size;
	int *a;
	printf("enter size : \n");
	scanf("%d",&size);
	a = malloc(size*sizeof(int));
	memset(a,0,size*sizeof(int));
	for(i=0;i<size;i++)scanf("%d",a+i);
	selsort(a,size);
	for(i=0;i<size;i++)printf("%d ",*(a+i));
	free(a);
	return 0;
}