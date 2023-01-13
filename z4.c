#include<stdio.h>
#include<string.h>
#include<math.h>
void reversestr(char a[10]){
	int i=9;
	int j=0;
	for(;i>-1;i--){
		if(a[i]!=0&&j<i){
			int tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
			j++;	
		}
	}
}
int main(){
	double a;
	scanf("%lf",&a);
	int b=floor(a);
	double c=a-b;
	char tmp[100];
	memset(tmp,0,sizeof(tmp));
	int i=0;
	while(b!=0){
		tmp[i]=b%2+'0';
		b/=2;
		i++;
	}
	reversestr(tmp);
	tmp[i++]='.';
	while(c<1&&i<100){
		int x = floor(c*=2);
		if(x==0)tmp[i++]='0';
		else tmp[i++]='1';
		c-=x;
		if(c==0)break;
	}
	puts(tmp);	
	return 0;
}