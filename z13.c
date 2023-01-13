#include<stdio.h>
#include<string.h>
int main(){
	char a[100];
	memset(a,0,sizeof(a));
	gets(a);
	int L=strlen(a);
	int i;
	for(i=0;i<L/2;i++){
		if(a[i]!=a[L-i-1]){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}