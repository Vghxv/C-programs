#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef char (*arr)[20];
void debug(arr a){
	int i;
	for(i=0;i<30;i++)printf("%s\n",a[i]);
}
arr setarr(){
	int i;
	arr k= (arr)malloc(50*20*sizeof(char));
	for(i=0;i<50;i++)memset(k[i],0,sizeof(k[i]));
	return k;
}
void save(char *a,arr k){
	char *tok;
	tok=strtok(a," ");
	int i=0;
	while(tok!=NULL){
		strncpy(*(k+i),tok,20);
		tok=strtok(NULL," ");
		i++;
	}
}
void replace(arr S,char *a,char *b){
	int i=0;
	while(S[i][0]!=0){
		if(strcmp(*(S+i),a)==0){
			printf("%s ",b);
		}
		else printf("%s ",*(S+i));
		i++;
	}
}
void insert(arr S,char *a,char *b){
	int i=0;
	while(S[i][0]!=0){
		if(strcmp(*(S+i),a)==0){
			printf("%s ",b);
		}
		printf("%s ",*(S+i));
		i++;
	}
}
void del(arr S,char *a,char *b){
	int i=0;
	while(S[i][0]!=0){
		if(strcmp(*(S+i),a)!=0){
			printf("%s ",*(S+i));
		}
		i++;
	}
}
void count(arr S){
	int i=0,j=0,k=0;
	arr mem=setarr();
	while(i<50||S[i][0]!=0){
		int flag=1;
		while(j<50||mem[j][0]!=0){
			if(strncmp(S[i],mem[j],20)==0){
				flag=0;
				break;
			}
			j++;
		}
		if(flag)strncpy(mem[k++],S[i],20);
		i++;
	}
	debug(mem);
}

int main(){
	char A[100];
	char P[20];
	char Q[20];
	memset(A,0,sizeof(A));
	memset(P,0,sizeof(P));
	memset(Q,0,sizeof(Q));
	gets(A);
	gets(P);
	gets(Q);
	arr S = setarr();
	save(A,S);
	debug(S);
	replace(S,P,Q);
	puts("");
	insert(S,P,Q);
	puts("");
	del(S,P,Q);
	count(S);
	free(S);
	return 0;
}