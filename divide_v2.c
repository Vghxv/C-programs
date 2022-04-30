#include<stdio.h>
#include<string.h>
void complement(char *a){
	int i;
	for(i=0;i<32;i++){
		a[i]=(a[i]=='1')?'0':'1';
	}
	
}
void ALU(char *remainder,const char *divisor){
	int i;
	
	int len=strlen(dividend);
	for(i=0;i<qlen;i++){
		remainder[63-i]=dividend[len-i-1];
	}
	
	
}
int main(){
	int i;
	char remainder[64];
	char divisor[32];
	char dividend[32];
	memset(remainder,'0',sizeof(remainder));
	memset(divisor,'0',sizeof(divisor));
	memset(dividend,'0',sizeof(dividend));
	scanf("%s",dividened);
	scanf("%s",divisor);	
	ALU(remainder,divisor);
	puts("remainder");
	for(i=0;i<32;i++)
	printf("%c",remainder[i]);
	puts("quotient");
	for(;i<64;i++)
	printf("%c",remainder[i]);
	return 0;
}
