#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct pp{
	int anda;
	int bla;
}pp;
void init(pp (*people)[9]){
	int i;
	for(i=0;i<9;i++){
		(*people)[i].anda=0;
		(*people)[i].bla=0;
	}
}
void de(int a[8]){
	int i,j;
	for(i=0;i<8;i++)printf("%d ",a[i]);
	puts("");
}
void depp(pp people[][9]){
	int i;
	for(i=0;i<9;i++){
		printf("%d %d %d",i+1,(*people)[i].anda,(*people)[i].bla);
		if(i!=8)puts("");
	}
}
void shift(int field[][8],int n){
	int i;
	for(i=3;i>-1;i--){
		(*field)[i+n]=(*field)[i];
		(*field)[i]=0;
	}
}
void clear(int field[][8]){
	int i;
	for(i=0;i<8;i++)(*field)[i]=0;
}
void start(int data[45],pp people[][9],int field[][8],int fuckedup,int *score){
	int i=0;
	int c=0;
	while(data[i]!=-1){
		(*field)[0]=(i%9)+1;
		if(data[i]==0){
			c+=1;
			if(c%3==0)clear(field);
		}
		else{
			((*people)[(*field)[0]-1].anda)+=1;
			shift(field,data[i]);
		}
		int j;
		for(j=4;j<8;j++){
			if((*field)[j]!=0){
				((*people)[(*field)[j]-1].bla)+=1;
				(*field)[j]=0;
				(*score)+=1;
			}
		}
		if(c==fuckedup)break;
		i++;
	}
}
int main(){
	int data[45];
	char buff[12];
	int i;
	int end;
	int score=0;
	int field[8];
	int f;
	for(f=0;f<8;f++)field[f]=0;
	pp people[9];
	init(&people);
	// depp(people);
	memset(data,-1,sizeof(data));
	for(i=0;i<9;i++){
		memset(buff,0,sizeof(buff));
		gets(buff);
		int j=2,jj=buff[0]-48,k=i;
		for(;j<12;j++){
			if(buff[j]!=32&&buff[j]!=0){
				if(buff[j]=='H'){
					data[k]=4;
				}
				else if(buff[j]=='O'){
					data[k]=0;
				}
				else data[k]=buff[j]-48;
				k+=9;
			}
		}
	}
	scanf("%d",&end);
	start(data,&people,&field,end,&score);
	printf("%d\n",score);
	depp(&people);
	return 0;
}