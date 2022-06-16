#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INF 0x3f3f3f3f
int find_path(int **record,int **data,int start,int end,int n){
	int i,ans=INF;
	if(record[start][end]>=0)return record[start][end];
	for(i=0;i<n;i++){
		if(!(end>>i&1)){
			int t=find_path(record,data,i,end|(1<<i),n)+data[start][i];
			ans=(ans>t)?t:ans;
		}
	}
	record[start][end]=ans;
	return record[start][end];
}
int main(){
	int n;
	scanf("%d",&n);
	int** data=(int**)malloc(sizeof(int*)*n);
	int** record=(int**)malloc(sizeof(int*)*n);
	int i,j;
	for(i=0;i<n;i++){
		data[i]=(int*)malloc(sizeof(int)*n);
		record[i]=(int*)malloc(sizeof(int)*(1<<n));
		memset(record[i],-1,sizeof(int)*(1<<n));
		for(j=0;j<n;j++){
			scanf("%d",data[i]+j);
		}
		record[i][(1<<n)-1]=data[i][0];
	}
	printf("%d",find_path(record,data,0,1,n));
	for(i=0;i<n;i++){
		free(data[i]);
		free(record[i]);
	}
	free(data);
	free(record);
	return 0;
}