#include<stdio.h>
#include<string.h>
#include<ctype.h>
typedef struct card_t{
	int p;
	char f;
}card_t;
typedef struct pc{
	card_t cards[5];
}pc;
int cmpn(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}
int cmp(const void *a,const void *b){
	card_t *A = (card_t*)a;
	card_t *B = (card_t*)b;
	if(A->p!=B->p)return (A->p)-(B->p);
	else{
		int i,c,d;
		if(A->f=='S')c=0;
		else if(A->f=='H')c=1;
		else if(A->f=='D')c=2;
		else c=3;
		if(B->f=='S')d=0;
		else if(B->f=='H')d=1;
		else if(B->f=='D')d=2;
		else d=3;
		return c-d;
	}
}
int intlen(int *a){
	int k=0;
	int i;
	for(i=0;i<5;i++){if(a[i]!=0)k++;}
	return k;
}
void getpset(card_t *a,int *b,int *max){
	int i,j;
	int seti=0;
	for(i=0;i<5;i++)b[i]=0;
	for(i=0;i<5;i++){
		int flag=0;
		for(j=0;j<5;j++){
			if(a[i].p==b[j]){
				flag=1;
				break;
			}
		}
		if(!flag)b[seti++]=a[i].p;
	}
	for(i=0;i<intlen(b);i++){
		int count=0;
		for(j=0;j<5;j++){
			if(b[i]==a[j].p)count++;
		}
		*max=(*max>count)?*max:count;
	}
}
void getfset(card_t *a,char *b,int *max){
	int i,j;
	int seti=0;
	for(i=0;i<5;i++)b[i]=0;
	for(i=0;i<5;i++){
		int flag=0;
		for(j=0;j<5;j++){
			if(a[i].f==b[j]){
				flag=1;
				break;
			}
		}
		if(!flag)b[seti++]=a[i].f;
	}
	for(i=0;i<strlen(b);i++){
		int count=0;
		for(j=0;j<5;j++){
			if(b[i]==a[j].f)count++;
		}
		*max=(*max>count)?*max:count;
	}
	
}
int jg(pc *a){
	int i,j;
	int count;
	int flowp=0;
	int tmp[5]={2,3,4,5,6};
	int pset[5];
	int pmax=0;
	char fset[5];
	int fmax=0;
	for(i=0;i<13;i++){
		qsort(tmp,5,sizeof(int),cmpn);
		for(j=0;j<5;j++){
			if(a->cards[j].p!=tmp[j])break;
		}
		if(j==5){
			flowp=1;
			break;
		}
		else{
			for(j=0;j<5;j++){
				tmp[j]=(tmp[j]>=14)?tmp[j]-12:tmp[j]+1;
			}
		}
	}
	getpset(a->cards,pset,&pmax);
	getfset(a->cards,fset,&fmax);
	if(flowp==1){
		if(fmax==5)return 8;
		else return 4;
	}
	else{
		if(pmax==4)return 7;
		if(intlen(pset)==2)return 6;
		if(fmax==5)return 5;
		if(pmax==3)return 3;
		if(intlen(pset)==3)return 2;
		if(intlen(pset)==4)return 1;
		return 0;	
	}
}
void input(pc *a){
	char buff[5];
	int i;
	for(i=0;i<5;i++){
		scanf("%s",buff);
		if(strlen(buff)==3){
			a->cards[i].p=10;
			a->cards[i].f=buff[2];
		}
		else if(isdigit(buff[0])){
			sscanf(buff,"%d%c",&(a->cards[i].p),&(a->cards[i].f));
		}
		else{
			int j;
			char t[4]={'J','Q','K','A'};
			for(j=0;j<4;j++){
				if(t[j]==buff[0]){
					a->cards[i].p=j+11;
					a->cards[i].f=buff[1];
					break;
				}
			}
		}
	}
}
int main(){
	pc a;
	pc b;
	input(&a);
	input(&b);
	qsort(a.cards,5,sizeof(card_t),cmp);
	qsort(b.cards,5,sizeof(card_t),cmp);
	printf("%c",jg(&a)>jg(&b)?'A':'B');
	return 0;
}