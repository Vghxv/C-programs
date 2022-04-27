#include<stdio.h>
#include<string.h>
int __strcmp(char *a,char *b){
	for(;(*a!=0)&&(*b!=0);){
		if(*a>*b)return 1;
		else if(*b>*a)return -1;
		a++;b++;
	}
	
	return 0;
}
int main(){
	char s1[50],s2[50];
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	scanf("%s",s1);
	scanf("%s",s2);
	printf("%d",__strcmp(s1,s2));
	return 0;
}