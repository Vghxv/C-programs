#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef enum{
	Ap=95,
	A=87,
	Am=82,
	Bp=78,
	B=75,
	Bm=70,
	Cp=68,
	C=65,
	Cm=60,
	F=50
}re_score;
typedef struct student{
	char ID[10];
	float score;
	union{
		float fp;
		char str[10];
	}var;
}student;
int transfp(float a){
	re_score k;
	if(a>=4.29)k=Ap;
	else if(a>=3.99)k=A;
	else if(a>=3.69)k=Am;
	else if(a>=3.29)k=Bp;
	else if(a>=2.99)k=B;
	else if(a>=2.69)k=Bm;
	else if(a>=2.29)k=Cp;
	else if(a>=1.99)k=C;
	else if(a>=0.99)k=Cm;
	else k=F;
	return k;
}
int transstr(char *a){
	re_score k;
	if(strcmp(a,"A+")==0||strcmp(a,"90-100")==0)k=Ap;
	else if(strcmp(a,"A")==0||strcmp(a,"85-89")==0)k=A;
	else if(strcmp(a,"A-")==0||strcmp(a,"80-84")==0)k=Am;
	else if(strcmp(a,"B+")==0||strcmp(a,"77-79")==0)k=Bp;
	else if(strcmp(a,"B")==0||strcmp(a,"73-76")==0)k=B;
	else if(strcmp(a,"B-")==0||strcmp(a,"70-72")==0)k=Bm;
	else if(strcmp(a,"C+")==0||strcmp(a,"67-69")==0)k=Cp;
	else if(strcmp(a,"C")==0||strcmp(a,"63-66")==0)k=C;
	else if(strcmp(a,"C-")==0||strcmp(a,"60-62")==0)k=Cm;
	else if(strcmp(a,"F")==0||strcmp(a,"0-59")==0)k=F;
	return k;
}
int cmp(void const *a,void const *b){
	return (((student*)b)->score)-(((student*)a)->score);
}
int main(){ 
	int M,N,i=0,j,standard[4];
	char buff[5];
	scanf("%d%*c",&M);
	for(i=0;i<M;i++){
		scanf("%s",buff);
		if(strcmp(buff,"GPA")==0)standard[i]=0;
		else standard[i]=1;
	}
	scanf("%d%*c",&N);
	student st[N];
	for(i=0;i<N;i++){
		st[i].score=0;
		scanf("%s",st[i].ID);	
		for(j=0;j<M;j++){
			if(standard[j]==0){
				scanf("%f",&st[i].var.fp);
				st[i].score+=transfp(st[i].var.fp);
			}
			else if(standard[j]==1){
				scanf("%s",st[i].var.str);
				st[i].score+=transstr(st[i].var.str);
			}
		}
		st[i].score/=M;
	}
	qsort(st,N,sizeof(student),cmp);
	for(i=0;i<3;i++){
		printf("%s\n%d\n",st[i].ID,(int)(st[i].score+0.5));
	}
	return 0;
}
// void debug(student *a){
	// printf("ID:%s\tscore:%.2f\tvar.fp:%.2f\tvar.str:%s\n",a->ID,a->score,a->var.fp,a->var.str);
// }

// void ddebug(student *a){
	// printf("ID:%s\tscore:%.0f\tvar.fp:%.2f\tvar.str:%s\n",a->ID,a->score,a->var.fp,a->var.str);
// }