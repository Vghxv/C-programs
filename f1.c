#include<stdio.h>
#include<string.h>
int f(int n,int arr[1000]){
	if(!arr[n]){
		arr[n]=f(n-1,arr)+f(n-2,arr)+f(n-3,arr);
	}
	return arr[n];
}
int main(){
	int n;
	int arr[1000];
	memset(arr,0,sizeof(arr));
	arr[0]=1;arr[1]=1;arr[2]=1;
	scanf("%d",&n);
	printf("%d",f(n,arr));
	return 0;
}