#include<stdio.h>
#include<stdlib.h>
void inssort(int *a,int len){
	int i;
	int j;
	for(i=1;i<len;i++){
		int key = a[i];
		j = i-1;
		while(key<a[j]&&j>-1){
            a[j+1] = a[j];
            j--;
		}
		a[j+1] = key;
	}
}
int main(){
	int i;
	int a[10];
	for(i=0;i<10;i++)scanf("%d",a+i);
	inssort(a,10);
	for(i=0;i<10;i++)printf("%d ",*(a+i));
	return 0;
}
