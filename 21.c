#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define wordlen 50
typedef char(*_2dlist)[wordlen];
_2dlist init(int row){
	int i;
	_2dlist k=(_2dlist)malloc(row*wordlen*sizeof(char));
	for(i=0;i<row;i++)memset(k[i],'0',sizeof(k[i]));
	return k;
}
void debug(char *a){
	int i;
	for(i=0;i<wordlen;i++)printf("%d ",*(a+i));printf("\n");
}
void split(char *a,const char *delim,_2dlist b){
	char *token = strtok(a,delim);
	int i=0;
	while(token!=NULL){
		strncpy(*(b+i++),token,wordlen);
		token=strtok(NULL,delim);
	}
}
int getrow(_2dlist a){
	int i;
	for(i=0;i<10;i++){
		if(a[i][0]=='0')return i;
	}
	return 10;
}
void magic(char *a,const char *delim,char *b,_2dlist c,int wordn){
	debug(a);
	char *token = strtok(a,delim);
	int i;
	while(token!=NULL){
		for(i=0;i<wordn;i++){
			if(strcmp(*(c+i),token)==0){
				b[i]='1';
			}
		}
		token=strtok(NULL,delim);
	}
}
int main(){
	char str[wordlen];
	memset(str,'#',sizeof(str));
	int n,i,j,total=0,wordn;
	gets(str);
	_2dlist S = init(10);
	split(str," ",S);
	wordn = getrow(S);
	
	scanf("%d%*c",&n);
	_2dlist sav = init(n);
	for(i=0;i<n;i++){
		memset(str,'#',sizeof(str));
		gets(str);
		magic(str," ",*(sav+i),S,wordn);
	}
	
	int k;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			int count=1;
			for(k=0;k<wordn;k++){
				if((sav[i][k]-'0')^(sav[j][k]-'0')==0){
					count=0;
				}
			}
			total+=count;
		}
	}
	free(sav);
	free(S);
	printf("%d",total);
	return 0;
}