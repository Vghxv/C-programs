#include<stdio.h>
#include<string.h>
int main(){
	char f[100];
	char u[100];
	int c;
	int k;
	int i;
	int a[100];
	int b[100];
	int o[200];
	memset(o,0,sizeof(o));
	int ca;
	scanf("%s",f);
	scanf("%s",u);
	for(i=0;i<100&&f[i]!=0;i++)a[i]=f[strlen(f)-i-1]-'0';
	for(i=0;i<100&&u[i]!=0;i++)b[i]=u[strlen(u)-i-1]-'0';
	for(c=0;c<strlen(f);c++){
		ca=0;
		for(k=0;k<strlen(u);k++){
			o[c+k]=(a[c]*b[k]+ca+o[c+k])%10;
			ca=(a[c]*b[k]+o[c+k]+ca)/10;
		}
	}
	for(i=199;i>-1;i--){
		if(o[i]!=0)printf("%d",o[i]);
	}
	return 0;
}
// 1234569871256631264256242345425
// 1124617912461249157612791847612