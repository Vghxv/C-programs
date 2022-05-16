#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int n;
	int i;
	int *m;
	int *M;
	int *a;
	int *inv;
	int k=1;
	int ans=0;
	scanf("%d",&n);
	m=malloc(n*sizeof(int));
	M=malloc(n*sizeof(int));
	a=malloc(n*sizeof(int));
	inv=malloc(n*sizeof(int));
	for(i=0;i<n;i++)scanf("%d%d",m+i,a+i);
	for(i=0;i<n;i++)k*=m[i];
	for(i=0;i<n;i++){
		M[i]=k/m[i];
		int j=1;
		while((M[i]*=j)%m[i]!=1)j++;
		inv[i]=j;
		ans+=M[i]*a[i];
	}
	printf("%d",(ans>k)?ans%k:ans);
	free(m);
	free(M);
	free(a);
	free(inv);
	return 0;
}