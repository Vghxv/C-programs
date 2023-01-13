#include<stdio.h>
#include<string.h>
int f(int *a,int n){
	if(a[n]==0)a[n]=f(a,n-1)+f(a,n-3);
	return a[n];
}
int main(){
	int a[20]={1,1,1};
	int i;
	// for(i=0;i<20;i++)printf("%d ",a[i]);
	for(i=0;i<15;i++){
		printf("%d ",f(a,i));
	}
	
	return 0;
}