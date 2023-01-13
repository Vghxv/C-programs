#include<stdio.h>
#include<stdlib.h>
typedef struct data{
	int as;
	int *arr;
}data_t;
int cmp(const void *a,const void *b){
	data_t* aa=(data_t*)a;
	data_t* bb=(data_t*)b;
	int i;
	for(i=0;i<aa->as-1;i++){
		if(aa->arr[i]!=bb->arr[i])return aa->arr[i]-bb->arr[i];
	}
	return aa->arr[i]-bb->arr[i];
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	data_t *a;
	a=(data_t*)malloc(sizeof(data_t)*n);
	int i,j;
	for(i=0;i<n;i++){
		a[i].arr=(int*)malloc(sizeof(int)*m);
		a[i].as=m;
		for(j=0;j<m;j++){
			scanf("%d",&(a[i].arr[j]));
		}
	}
	qsort(a,n,sizeof(data_t),cmp);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d ",(a[i].arr[j]));
		}
		free(a[i].arr);
		puts("");
	}
	free(a);
	return 0;
}