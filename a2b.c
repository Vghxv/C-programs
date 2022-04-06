#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define S 20
void trans(char *a,char *b,int an,int bn){
	int i=S-1;
	int j=0;
	int deci=0;
	while(a[i]==0)i--;
	for(;i>-1;i--){
		int tmp = (a[i]>'9')?a[i]-'A':a[i]-'0';
		deci+=;	
		printf("%d",deci);
	}
	i=0;
	while(deci>=pow(bn,i))i++;
	i--;
	for(;i>-1;i--){
		printf("?");
		int div = pow(bn,i);
		int tmp = deci%div;
		char tmpc = tmp<10 ? (tmp+'0'):(tmp+'A');
		b[j++]=tmpc;
		deci/=pow(bn,i);
	}
}
int is_valid(char *a,int n){
	int i;
	for(i=0;i<strlen(a);i++){
		int tmp;
		if(a[i]>='0'&&a[i]<='9')tmp=a[i]-'0';
		else if(a[i]>='A'&&a[i]<='F')tmp=a[i]-'A';
		else return 0;
		
		if(tmp>=n)return 0;
	}
	return 1;
}

int main(){
	char *a,*b;
	int an,bn;
	a = malloc(S*sizeof(char));
	b = malloc(S*sizeof(char));
	memset(a,0,S*sizeof(char));
	memset(b,0,S*sizeof(char));
	scanf("%d%d",&an,&bn);
	scanf("%s",a);
	if(is_valid(a,an)){
		trans(a,b,an,bn);
		//puts(b);
	}
	else printf("FUCK OFF DUMB");
	free(a);
	free(b);
	return 0;
}