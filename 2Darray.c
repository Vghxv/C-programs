#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Bs 20
int main(){
	char str[Bs];
	char *token;
	char a[]="123a456s789d";
	char b[]="qwert";
	memset(str,0,sizeof(str));
	gets(str);
	int n,i,j;
	scanf("%d%*c",&n);
	char (*mem)[Bs]=(char(*)[Bs])malloc(n*Bs*sizeof(char));
	for(i=0;i<n;i++)memset(mem[i],'0',sizeof(mem[i]));
	i=0;
	token=strtok(str," ");
	while(token!=NULL){
		strncpy(*(mem+i),token,Bs);
		token=strtok(NULL," ");
		i++;
	}
	for(i=0;i<n;i++){
		for(j=0;j<Bs;j++){
			printf("%c",mem[i][j]);
		}
		puts("");
	}
	free(mem);
	return 0;
}