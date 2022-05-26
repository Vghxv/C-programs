#include<stdio.h>
#include<stdlib.h>
#define SINGLEGATEVALUE() int(*SGateValue)(int);
#define DOUBLEGATEVALUE() int(*DGateValue)(int,int);
typedef struct gate{
	SINGLEGATEVALUE();
	DOUBLEGATEVALUE();
	int O;
}gate;
int not_value(int a){return !a;}
int empty_value(int a){return a;}
int and_value(int a,int b){return a&b;}
int or_value(int a,int b){return a|b;}
int xor_value(int a,int b){return a==b?0:1;}
int main(int argc, char *argv[]){
	int i1,i2,i3,i4;
	int t1,t2;
	gate GL[6];
	int O[3];
	scanf("%d%*c%d%*c%d%*c%d%*c",&i1,&i2,&i3,&i4);
	int i;
	char buff;
	for(i=0;i<6;i++){
		scanf("%c%*c",&buff);
		if(buff=='A'){
			GL[i].DGateValue=and_value;
		}
		else if(buff=='O'){
			GL[i].DGateValue=or_value;
		}
		else if(buff=='X'){
			GL[i].DGateValue=xor_value;
		}
		else if(buff=='N'){
			GL[i].SGateValue=not_value;
		}
		else if(buff=='E'){
			GL[i].SGateValue=empty_value;
		}
	}
	t1=GL[0].DGateValue(i1,i2);
	O[0]=GL[1].SGateValue(t1);
	t2=GL[2].DGateValue(t1,i3);
	O[1]=GL[3].DGateValue(t2,O[0]);
	t1=GL[4].DGateValue(t2,i4);
	O[2]=GL[5].DGateValue(t1,O[1]);
	printf("%d,%d,%d",O[0],O[1],O[2]);
	return 0;
	
}