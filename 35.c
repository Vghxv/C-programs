#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct llld_s{
	int num[300];
	int sign;
	int L;
	int point;
}llld_t;
void swap(int *a,int *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
llld_t init(){
	llld_t k;
	k.L=0;
	memset(k.num,0,sizeof(k.num));
	k.sign=1;
	k.point=0;
	return k;
}
void shift(llld_t*k,int ext){
	int i;
	for(i=k->L;i>-1;i--){
		swap(&k->num[i+ext],&k->num[i]);
	}
	memset(k->num,0,sizeof(int)*ext);
	k->L+=ext;
	k->point+=ext;
}
void scanllld(llld_t* k){
	char *buff;
	buff=malloc(sizeof(char)*300);
	scanf("%s",buff);
	int j=0;
	int i;
	int L = strlen(buff);
	for(i=L-1;i>-1;i--){
		if(buff[i]=='.')k->point=L-i-1;
		else if(buff[i]=='-')k->sign=-1;
		else k->num[j++]=buff[i]-'0';
	}
	k->L=j;
	free(buff);
}
void de(llld_t k){
	printf("sign:%d point:%d L:%d\n",k.sign,k.point,k.L);
	int i;
	for(i=0;i<k.L;i++)printf("%d",k.num[i]);
	puts("");
}
void printllld(llld_t k){
	int i=299;
	int j=0;
	int f1=1;
	while(k.num[i]==0&&i>k.point)i--;
	// printf("the i is %d\n",i);
	while(k.num[j]==0&&j<k.point)j++;
	// printf("the j is %d\n",j);
	if(i==j){
		printf("0\n");
		return;
	}
	if(k.sign==-1)printf("-");
	for(;i>=j;i--){
		if(i+1==k.point){
			printf(".");
		}
		printf("%d",k.num[i]);
		f1=0;
	}
	puts("");
}
int cmp_big(llld_t a,llld_t b){
	int i;
	int n1=a.L - a.point;
	int n2=b.L - b.point;
	if(n1!=n2)return n1-n2;
	for(i=a.L-1;i>-1;i--){
		if(a.num[i]!=b.num[i])return a.num[i]-b.num[i];
	}
	return 0;
}
void align(llld_t *a,llld_t *b){
	int ext = a->point-b->point; 
	if(ext>=0)shift(b,ext);
	else shift(a,abs(ext));
}
void add_big(llld_t*a,llld_t*b,llld_t*c){
	int i;
	int carry=0;
	for(i=0;i<a->L;i++){
		c->num[i]=(a->num[i]+b->num[i]+carry)%10;
		carry=(a->num[i]+b->num[i]+carry)/10;
	}
	c->L=a->L;
	c->point=a->point;
	if(carry!=0){
		c->num[i]=carry;
		c->L++;
	}
}
void sub_big(llld_t *a,llld_t *b,llld_t *c){
	int i;
	int borrow=0;
	for(i=0;i< a->L ;i++){
		c->num[i]=a->num[i]-b->num[i]-borrow;
		if(c->num[i]<0){
			c->num[i]+=10;
			borrow=1;
		}
		else {
			borrow=0;
		}
	}
	i=299;
	c->point=a->point;
	while(c->num[i]==0&&i>c->point)i--;
	c->L=i+1;
}
void mul_big(llld_t *a,llld_t *b,llld_t *c){
	int i,j;
	int carry=0;
	for(i=0;i<a->L+1;i++){
		for(j=0;j<b->L+1;j++){
			int tmp=a->num[i]*b->num[j]+c->num[i+j]+carry;
			carry=tmp/10;
			c->num[i+j]=tmp%10;
		}
	}
	c->point=a->point+b->point;
	
}
int main(){
	llld_t a=init();
	llld_t b=init();
	llld_t c=init();
	scanllld(&a);
	scanllld(&b);
	llld_t tmp=init();
	// de(a);
	// de(b);
	tmp.sign=a.sign*b.sign;
	mul_big(&a,&b,&tmp);
	
	align(&a,&b);
	if(cmp_big(a,b)>=0){
		if(a.sign==1&&b.sign==1){
			// puts("[1]");
			add_big(&a,&b,&c);
			c.sign=1;
			printllld(c);
			
			c=init();
			sub_big(&a,&b,&c);
			c.sign=1;
			printllld(c);
		}
		else if(a.sign==-1&&b.sign==-1){
			// puts("[2]");
			add_big(&a,&b,&c);
			c.sign=-1;
			printllld(c);
			
			c=init();
			sub_big(&a,&b,&c);
			c.sign=-1;
			printllld(c);
			// de(c);
		}
		else if(a.sign>b.sign){
			// puts("[3]");
			sub_big(&a,&b,&c);
			c.sign=1;
			printllld(c);
			
			c=init();
			add_big(&a,&b,&c);
			c.sign=1;
			printllld(c);
			
		}
		else{
			// puts("[4]");
			sub_big(&a,&b,&c);
			c.sign=-1;
			printllld(c);
			
			c=init();
			add_big(&a,&b,&c);
			c.sign=-1;
			printllld(c);
		}
	}
	else{
		if(a.sign==1&&b.sign==1){
			// puts("[5]");
			add_big(&b,&a,&c);
			c.sign=1;
			printllld(c);
			
			c=init();
			sub_big(&b,&a,&c);
			c.sign=-1;
			printllld(c);
		}
		else if(a.sign==-1&&b.sign==-1){
			// puts("[6]");
			add_big(&b,&a,&c);
			c.sign=-1;
			printllld(c);
			
			c=init();
			sub_big(&b,&a,&c);
			c.sign=1;
			printllld(c);
		}
		else if(b.sign>a.sign){
			// puts("[7]");
			sub_big(&b,&a,&c);
			c.sign=1;
			printllld(c);
			
			c=init();
			add_big(&b,&a,&c);
			c.sign=-1;
			printllld(c);
		}
		else{
			// puts("[8]");
			sub_big(&b,&a,&c);
			c.sign=-1;
			printllld(c);

			c=init();
			add_big(&b,&a,&c);
			c.sign=1;
			printllld(c);
		}
	}
	printllld(tmp);
	
	return 0;
}