#include<stdio.h>
#include<string.h>
int __pow(int a,int p){
	int k=1;
	int i;
	for(i=0;i<p;i++)k*=a;
	return k;
}
int main(){
	int a,l;
	int b=0;
	scanf("%d",&a);
	l=a;
	int i=0;
	while(a!=0){
		a/=10;
		i++;
	}
	a=l;
	int y=i;
	for(;i>-1;i--){
		int m=a%10;
		b+=__pow(m,y);
		a/=10;
	}
	a=l;
	printf((a==b)?"Yes!":"No!");
	return 0;
}