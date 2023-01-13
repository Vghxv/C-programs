#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef char (*arr)[20];
typedef struct element{
	char str[20];
	int count;
}element;
arr initarr(){
	int i;
	arr k = (arr)malloc(50*20*sizeof(char));
	for(i=0;i<50;i++)memset(k[i],0,sizeof(k[i]));
	return k;
}
void debugset(element * a){
	int i;
	for(i=0;i<50&&a[i].str[0]!=0;i++)printf("%s %d\n",a[i].str,a[i].count);
}
void debugarr(arr a){
	int i;
	for(i=0;i<50;i++)printf("%s\n",a[i]);
}
int cmp(const void *a,const void *b){
	if((((element*)a)->count)!=(((element*)b)->count))return (((element*)b)->count)-(((element*)a)->count);
	else if(strlen(((element*)a)->str)!=strlen(((element*)b)->str))return strlen(((element*)a)->str)-strlen(((element*)b)->str);
	else return (strncmp(((element*)a)->str,((element*)b)->str,20));
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
	element set[50];
	for(i=0;i<50;i++){
		memset(set[i].str,0,sizeof(set[i].str));
		set[i].count=0;
	}
	i=0;
	while(i<50){
		int flag=1;
		j=0;
		while(j<50){
			// printf("hello %d %d\n",i,j);
			if(strncmp(S[i],set[j].str,20)==0){
				flag=0;
				break;
			}
			j++;
		}
		if(flag){
			// printf("i:%d",i);
			strncpy(set[k].str,S[i],20);
			j=0;
			while(j<50){
				if(strncmp(S[i],S[j],20)==0){
					set[k].count++;
				}
				j++;
			}
			k++;
		}
		i++;
	}
	qsort(set,k,sizeof(element),cmp);
	debugset(set);
}

int main(){
	char A[500];
	char P[20];
	char Q[20];
	memset(A,0,sizeof(A));
	memset(P,0,sizeof(P));
	memset(Q,0,sizeof(Q));
	gets(A);
	gets(P);
	gets(Q);
	arr S = initarr();
	save(A,S);
	// debugarr(S);
	replace(S,P,Q);
	puts("");
	insert(S,P,Q);
	puts("");
	del(S,P,Q);
	puts("");
	count(S);
	free(S);
	return 0;
}