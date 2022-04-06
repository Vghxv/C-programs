#include<stdio.h>
#include<stdlib.h>
void isort(int *a,int len){
	int i=1;
	while(i<len){
		int key = a[i];
		int j = i-1;
		while(key<a[j]&&j>-1){
            a[j+1] = a[j];
            j--;
		}
		a[j+1] = key;
		i++;
	}
}
int main(){
	int i;
	int a[10];
	for(i=0;i<10;i++)scanf("%d",a+i);
	isort(a,10);
	for(i=0;i<10;i++)printf("%d ",*(a+i));
	return 0;
}
