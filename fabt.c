#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int f(int *arr,int n){
	if(n<=2)return 1;
	if(arr[n-1]!=0)return arr[n-1];
	else arr[n-1]=f(arr,n-1);
	if(arr[n-2]!=0)return arr[n-2];
	else arr[n-2]=f(arr,n-2);
	return arr[n-1]+arr[n-2];
}
int main(){
	int n;
	int *arr;
	scanf("%d",&n);
	arr=malloc(n*sizeof(int));
	memset(arr,0,n*sizeof(int));
	printf("%d",f(arr,n));
	return 0;
}