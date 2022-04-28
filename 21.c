#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define wordlen 30
#define ROW 10 
typedef char(*_2dlist)[wordlen];
void debug(_2dlist mem){
	int i,j;
	for(i=0;i<ROW;i++){
		for(j=0;j<wordlen;j++){
			printf("%c",mem[i][j]);
		}
		puts("");
	}
}
int iscomplement(_2dlist a,char *b){
	int i;
	puts(b);
	for(i=0;i<ROW;i++){
		if(strcmp(*(a+i),b)==0)return 0;
	}
	return 1;
}
int main(){
	char str[100],strtmp[100];
	memset(str,0,sizeof(str));
	memset(strtmp,0,sizeof(strtmp));
	char *tok,*toktmp;
	int n,i,total=0;
	
	gets(str);
	_2dlist mem =(_2dlist)malloc(ROW*wordlen*sizeof(char));
	for(i=0;i<ROW;i++)memset(mem[i],'#',sizeof(mem[i]));
	
	i=0;
	tok=strtok(str," ");
	while(tok!=NULL){
		strncpy(*(mem+i++),tok,wordlen);
		tok=strtok(NULL," ");
	}
	debug(mem);
	
	scanf("%d%*c",&n);
	for(i=0;i<n;i++){
		gets(strtmp);
		toktmp=strtok(strtmp," ");
		while(toktmp!=NULL){
			if(iscomplement(mem,toktmp)){
				total++;
			}
			toktmp=strtok(NULL," ");
		}
	}
	free(mem);
	printf("%d",total);
	return 0;
}