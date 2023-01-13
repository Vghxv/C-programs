#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(int *a,int *b,int *c,int *d){
	int tmp = *a;
	*a=*b;
	*b=*c;
	*c=*d;
	*d=tmp;
}
void faceclockwise(int face[3][3]){
	swap(&face[0][0],&face[2][0],&face[2][2],&face[0][2]);
	swap(&face[0][1],&face[1][0],&face[2][1],&face[1][2]);
}
void facecounterclockwise(int a[3][3]){
	swap(&a[0][2],&a[2][2],&a[2][0],&a[0][0]);
	swap(&a[1][2],&a[2][1],&a[1][0],&a[0][1]);
}
void turn10(int a[6][3][3]){
	int i;
	for(i=0;i<3;i++)swap(&a[3][i][0],&a[5][i][0],&a[2][2-i][2],&a[0][i][0]);
	facecounterclockwise(a[4]);
}
void turn11(int a[6][3][3]){
	int i;
	for(i=0;i<3;i++)swap(&a[3][i][1],&a[5][i][1],&a[2][i][1],&a[0][i][1]);	
}
void turn12(int a[6][3][3]){
	int i;
	for(i=0;i<3;i++)swap(&a[3][i][2],&a[5][i][2],&a[2][2-i][0],&a[0][i][2]);
	faceclockwise(a[1]);
}
void turn20(int a[6][3][3]){
	int i;
	for(i=0;i<3;i++)swap(&a[4][0][i],&a[3][0][i],&a[1][0][i],&a[2][0][i]);
	faceclockwise(a[0]);
}
void turn21(int a[6][3][3]){
	int i;
	for(i=0;i<3;i++)swap(&a[4][1][i],&a[3][1][i],&a[1][1][i],&a[2][1][i]);
}
void turn22(int a[6][3][3]){
	int i;
	for(i=0;i<3;i++)swap(&a[4][2][i],&a[3][2][i],&a[1][2][i],&a[2][2][i]);
	facecounterclockwise(a[5]);
}
int main(){
	int i,j,k;
	int cube[6][3][3];
	for(i=0;i<6;i++){
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				cube[i][j][k]=i+1;
			}
		}
	}
	void (*func[2][3])(int [6][3][3])={turn10,turn11,turn12,turn20,turn21,turn22};
	int n=0;
	scanf("%d%*c",&n);
	while(n>0){
		int op0=getchar()-'1';
		int op1=getchar()-'0';
		getchar();
		func[op0][op1](cube);
		n--;
	}	
	i=0;
	for(j=0;j<3;j++){
		for(k=0;k<3;k++){
			printf("%d ",cube[i][j][k]);
		}
		puts("");
	}
	return 0;
}