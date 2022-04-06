#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void merge(int *a,int front, int mid,int end){
	int *L,*R,i,j,k=0;
	int n1 = mid - front + 1;
	int n2 = end - mid;
	L = malloc(n1*sizeof(int));
	R = malloc(n2*sizeof(int));
	for(k=0;k<n1;k++)L[k] = a[front+k];
	for(k=0;k<n2;k++)R[k] = a[mid+1+k];
	i=0;
	j=0;
	k=front;
	while(i<n1&&j<n2){
		if(L[i]<R[j]) a[k++] = L[i++];
		else a[k++] = R[j++];
	}
	while(i<n1) a[k++] = L[i++];
	while(j<n2) a[k++] = R[j++];
	free(L);
	free(R);
}
void msort(int *a,int front,int end){
	if(front<end){
		int mid = (front+end)/2;
		msort(a,front,mid);
		msort(a,mid+1,end);
		merge(a,front,mid,end);
	}
}
int main(){
	int i;
	int a[10];
	memset(a,0,sizeof(a));
	for(i=0;i<10;i++)scanf("%d",a+i);
	//merge(a,0,4,9);
	msort(a,0,9);
	for(i=0;i<10;i++)printf("%d ",*(a+i));
	
	return 0;
}