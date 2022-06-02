#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int vectorlen(int a,int b){
	return sqrt(a*a+b*b);
}
int main(){
	char **board;
	int i;
	scanf("%d%d%d",&a,&b,&c);
	board=(char**)malloc(sizeof(char*)*a);
	memset(*board,'-',sizeof(*board));
	memset(board[a-1],'-',sizeof(*board));
	char shit=abs(a)>abs(b)?'|':'-';
	for(i=0;i<);
	for(i=0;i<a;i++)*board=(char*)malloc(sizeof(board)*b);
	int pt1,pt2;	
	int t1=0,t2=0;
	int dt1=0,dt2=0;
	for(i=0;i<c;i++){
		if(!t1||!t2){pt1=t1;pt2=t2}
		scanf("%d%d",&t1,&t2);
		board[t1][t2]='*';
		dt1=t1-pt1;
		dt2=t2-pt2;
	}
	printf("-------\n");
	printf("|****-\n");
	printf("|* *-\n");
	printf("|**-\n");
	printf("|*-\n");
	printf("|-\n");
	
	return 0;
}