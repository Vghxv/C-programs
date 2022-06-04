#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct llld_s{
	int num[300];
	int sign;
	int L;
	int ud; //units digit
}llld_t;
void swap(int *a,int *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
llld_t init(){
	llld_t k;
	memset(k.num,0,sizeof(k.num));
	k.sign=1;
	k.ud=0;
	return k;
}
void shift(llld_t*k,int ext){
	int i;
	for(i=k->L;i>-1;i--){
		swap(&k->num[i+ext],&k->num[i]);
	}
	memset(k->num,0,sizeof(int)*ext);
	k->L+=ext;
	k->ud+=ext;
}
void scanllld(llld_t* k){
	char *buff;
	buff=malloc(sizeof(char)*300);
	scanf("%s",buff);
	int j=0;
	int i;
	int L = strlen(buff);
	for(i=L-1;i>-1;i--){
		if(buff[i]=='.')k->ud=L-i-1;
		else if(buff[i]=='-')k->sign=-1;
		else k->num[j++]=buff[i]-'0';
	}
	k->L=j;
	free(buff);
}
void printllld(llld_t k){
	printf("sign:%d ud:%d L:%d\n",k.sign,k.ud,k.L);
	int i;
	for(i=0;i<k.L;i++)printf("%d",k.num[i]);
	puts("");
}
void add_big(llld_t*a,llld_t*b,llld_t*c){
	int ext = a->ud-b->ud; 
	int bound=0;
	if(ext>=0){
		shift(b,ext);
		bound=a->L;
	}
	else if(ext<0){
		shift(a,abs(ext));
		bound=b->L;
	}
	if(bound==0){
		printf("fuck");
		_Exit(0);
	}
	int i;
	int carry=0;
	for(i=0;i<bound;i++){
		c->num[i]=(a->num[i]+b->num[i]+carry)%10;
		carry=(a->num[i]+b->num[i]+carry)/10;
	}
}
int main(){
	llld_t a=init();
	llld_t b=init();
	llld_t c=init();
	scanllld(&a);
	scanllld(&b);
	add_big(&a,&b,&c);
	printllld(c);
	return 0;
}