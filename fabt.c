#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// int f(int *arr,int n)return(!arr[n]&&n>1)?f(arr,n-1)+f(arr,n-2):arr[n];
int f(int *arr,int n){
	if(!arr[n]){
		arr[n]=f(arr,n-1)+f(arr,n-2);
	}
	return arr[n];
}
int main(){
	int n;
	int *arr;
	scanf("%d%*c",&n);
	arr=malloc(n*sizeof(int));
	memset(arr,0,n*sizeof(int));
	arr[0]=1;arr[1]=1;
	printf("%d",f(arr,n-1));
	free(arr);
	return 0;
}