#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define wordlen 50
#define ROW 10 

typedef char(*_2dlist)[wordlen];
typedef char(*_2dlistB)[wordlen*2];
// _2dlist init(int row){
	// int i;
	// _2dlist k=(_2dlist)malloc(row*wordlen*sizeof(char));
	// for(i=0;i<row;i++)memset(k[i],'#',sizeof(k[i]));
	// return k;
// }
void debug(char *a){
	int i;
	for(i=0;i<wordlen;i++){
		printf("%d ",*(a+i));
	}
	printf("\n");
}
_2dlistB initB(int row){
	int i;
	_2dlistB k=(_2dlistB)malloc(row*wordlen*2*sizeof(char));
	for(i=0;i<row;i++)memset(k[i],'#',sizeof(k[i]));
	return k;
}

// void split(char *a,const char *delim,_2dlist b){
	// char *token = strtok(a,delim);
	// int i=0;
	// while(token!=NULL){
		// strncpy(*(b+i++),token,wordlen);
		// token=strtok(NULL,delim);
	// }
// }
// void debug(_2dlist a,int row){
	// int i,j;
	// for(i=0;i<row;i++){
		// for(j=0;j<wordlen;j++){
			// printf("%c",a[i][j]);
		// }
		// puts("");
	// }
// }
int iscomplement(char *a,char *b,char *c){
}
int main(){
	char str[wordlen*2];
	char tmp[wordlen];
	memset(str,0,sizeof(str));
	int n,i,j,total=0;
	gets(str);
	printf("str:%s\n",str);
	// _2dlist S = init(ROW);
	// split(str," ",S);
	// debug(S,ROW);
	scanf("%d%*c",&n);
	_2dlistB sav = initB(n);
	for(i=0;i<n;i++){
		memset(tmp,0,sizeof(wordlen*2));
		gets(tmp);
		strncpy(sav[i],tmp,wordlen*2);
	}
	// printf("str:%s------\n",str);
	debug(str);
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
		// printf("str:%s------\n",str);
		// if(iscomplement(sav[i],sav[j],str))total++;
		// int k;
		char *toka,*tokb,*tokc;
		int founded;
		tokc=strtok(str," ");
		debug(str);
		
		printf("sav[i]:%s\n",sav[i]);
		printf("sav[j]:%s\n",sav[j]);
		printf("str:%s\n",str);
		while(tokc!=NULL){
			founded=0;
			toka = strtok(sav[i]," ");
			while(toka!=NULL){
				if(strncmp(toka,tokc,50)==0)founded=1;
				tokb = strtok(sav[j], " ");
				while(tokb!=NULL){
					printf("tokc : %s\n",tokc);
					printf("toka : %s\n",toka);
					printf("tokb : %s\n",tokb);
					if(strncmp(tokb,tokc,50)==0)founded=1;
					if(strncmp(toka,tokb,wordlen*2)==0)return 0;
					tokb=strtok(NULL," ");
				}
				toka=strtok(NULL," ");
			}
			// if(founded!=1)return 0;
			puts("----tokcnew------");
			tokc=strtok(NULL," ");
			// puts("---------------");
		}
		total+=founded;
			// printf("%d\n",total);
		}
	}
	free(sav);
	printf("%d",total);
	return 0;
}